#include "przegladarka.h"
#include "ui_przegladarka.h"
#include "edytor.h"
#include "ui_edytor.h"
#include "jezyk.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

przegladarka::przegladarka(SkosModel* p_model, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::przegladarka)
{
    ui->setupUi(this);
    Model=p_model;
    Jezyk=Soprano::LanguageTag("pl");
    this->WszystkieJezyki=true;
    inicjalizuj_jezyki();
    zaladuj_comboBox();

    connect(ui->edytujButton, SIGNAL(clicked()), this,SLOT(edytuj()));
    connect(ui->dodajButton, SIGNAL(clicked()), this,SLOT(dodaj()));
    connect(ui->pokazButton, SIGNAL(clicked()), this,SLOT(pokaz()));
    connect(ui->actionZapisz, SIGNAL(triggered()), this,SLOT (zapisz()));
    connect(ui->actionWczytaj, SIGNAL(triggered()), this,SLOT (wczytaj()));
    connect(ui->znajdzLineEdit, SIGNAL(textEdited(QString)), this,SLOT(odswiez()));
    connect(ui->pojeciaListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(wstaw_z_listy()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this, SLOT(zmien_jezyk(int)));
    }

przegladarka::~przegladarka()
{
    delete ui;
}
void przegladarka::edytuj()
{

    QString slowo = ui->znajdzLineEdit->text();
    SkosConcept Koncept;
    if (znajdz(slowo,Koncept)){
        SkosConcept* ptrNaDodawany = &(*(Model->findConcept(Koncept)));
        edytor edyt(0,Model,*ptrNaDodawany,&ListaJezykow);
        //edytor edyt(0,&Model,&Koncept,&ListaJezykow);
        edyt.show();
        if (edyt.exec() == QDialog::Accepted) {
             zapelnij_liste();
        }
    }
    else{
            QMessageBox::information(this, tr("Nie znaleziono"),
              tr("Niestety nie ma wyrazu \"%1\" w bazie").arg(slowo));
    }
}
void przegladarka::dodaj()
{
    QString tmp;
    tmp.setNum(Model->getConcepts().size());
    SkosConcept Koncept=SkosConcept(QUrl(tmp));
    Model->addConcept(QUrl(tmp));
    SkosConcept* ptrNaDodawany = &(*(Model->findConcept(Koncept)));
    edytor edyt(0,Model,*ptrNaDodawany,&ListaJezykow);
    edyt.show();
    if (edyt.exec() == QDialog::Accepted) {      
        zapelnij_liste();
    }
}
bool przegladarka::znajdz(QString slowo, SkosConcept& Koncept)
{
    bool znaleziony=false;
    QList<SkosConcept> wszystkie;
    wszystkie=Model->getConcepts();
    int i=0;
    int j=0;
    while (!znaleziony && i<wszystkie.size()) {
        j=0;
        while(!znaleziony && j<wszystkie.value(i).getLabelList(PrefferedLabelType).size()){
            if (wszystkie.value(i).getLabelList(PrefferedLabelType).value(j).literal().toString()==slowo)
                znaleziony=true;
            j++;
            }
        j=0;
        while(!znaleziony && j<wszystkie.value(i).getLabelList(AlternativeLabelType).size()){
            if (wszystkie.value(i).getLabelList(AlternativeLabelType).value(j).literal().toString()==slowo)
                znaleziony=true;
            j++;
            }
        j=0;
        while(!znaleziony && j<wszystkie.value(i).getLabelList(HiddenLabelType).size()){
            if (wszystkie.value(i).getLabelList(HiddenLabelType).value(j).literal().toString()==slowo)
                znaleziony=true;
            j++;
            }
    i++;
    }
    if (znaleziony){
        Koncept=Model->getConcepts().value(i-1);
        return true;
    }
    else
        return false;
}
void przegladarka::pokaz()
//Poszukuje słowa pobranego z linii, wśród wszystkich zawartych w tezaurusie słowach i pokazuje odpodiedni koncept i jego pokrewne zgodnie z określonymi wlaściwościami.
//W przeciwnym razie zwraca informacje o braku słowa w bazie
{
    QString slowo = ui->znajdzLineEdit->text();
    SkosConcept Koncept;
    if (znajdz(slowo,Koncept)){
        wyswietl(Koncept);
        SkosConcept* ptrNaKoncept = &(*(Model->findConcept(Koncept)));
        QList<SkosConcept*>lista;
        QList<SkosConcept*>*ptrNaListe;
        ptrNaListe=&lista;
        ptrNaListe->clear();
        QString powiazane;
        QString syn_powiazanych;
        QString skumulowane;
        znajdz_szersze(ptrNaListe,ptrNaKoncept,ui->szersze_spinBox->value());
        znajdz_wezsze(ptrNaListe,ptrNaKoncept,ui->wezsze_spinBox->value());
        znajdz_skojarzone(ptrNaListe,ptrNaKoncept,ui->skojarzone_spinBox->value());


        for (int i=1;i<lista.size();i++){
            for(int j=0;j<lista.value(i)->getLabelList(PrefferedLabelType).size();j++){
                if((lista.value(i)->getLabelList(PrefferedLabelType).value(j).language()==Jezyk)||WszystkieJezyki){
                   powiazane+=lista.value(i)->getLabelList(PrefferedLabelType).value(j).literal().toString();
                   powiazane+=';';
               }
            }
            for(int j=0;j<lista.value(i)->getLabelList(AlternativeLabelType).size();j++){
                if((lista.value(i)->getLabelList(AlternativeLabelType).value(j).language()==Jezyk)||WszystkieJezyki){
                   syn_powiazanych+=lista.value(i)->getLabelList(AlternativeLabelType).value(j).literal().toString();
                   syn_powiazanych+=';';
               }
            }
        }


        ui->powiazaneTextBrowser->setText(powiazane);
        ui->syn_powTextBrowser->setText(syn_powiazanych);

        skumulowane+=ui->synonimyTextBrowser->toPlainText();
        skumulowane+=powiazane;
        skumulowane+=syn_powiazanych;

        ui->skumulowaneTextBrowser->setText(skumulowane);



    }
    else{
       QMessageBox::information(this, tr("Nie znaleziono"),
         tr("Niestety nie ma wyrazu \"%1\" w bazie").arg(slowo));
    }
}
void przegladarka::wstaw_z_listy()
//Przpisuje zawartosc pozycji kliknietej na liscie
{
ui->znajdzLineEdit->setText(ui->pojeciaListWidget->currentItem()->text());
}
void przegladarka::wyswietl(SkosConcept Koncept)
{
    QString synonimy;
    for(int j=0;j<Koncept.getLabelList(PrefferedLabelType).size();j++){
         if((Koncept.getLabelList(PrefferedLabelType).value(j).language()==Jezyk)||WszystkieJezyki){
            synonimy+=Koncept.getLabelList(PrefferedLabelType).value(j).literal().toString();
            synonimy+=';';
        }
    }

    for(int j=0;j<Koncept.getLabelList(AlternativeLabelType).size();j++){
         if((Koncept.getLabelList(AlternativeLabelType).value(j).language()==Jezyk)||WszystkieJezyki){
            synonimy+=Koncept.getLabelList(AlternativeLabelType).value(j).literal().toString();
            synonimy+=';';
        }
    }

     ui->synonimyTextBrowser->setText(synonimy);

     QString definicja;
     for(int j=0;j<Koncept.getDefinitions().size();j++){
         if((Koncept.getDefinitions().value(j).language()==Jezyk)||WszystkieJezyki){
            definicja+=Koncept.getDefinitions().value(j).literal().toString();
            definicja+=QChar(QChar::LineSeparator);
        }
     }
     ui->definicjaTextBrowser->setText(definicja);
}


void przegladarka::zapisz()

   {
       QString fileName = QFileDialog::getSaveFileName(this,
           tr("Zapisz Tezaurus jako"), "",
           tr("turtle (*.tur);; Wszystkie pliki (*)"));

       if (fileName.isEmpty())
           return;
       else{
           SkosSerializer Serializer(Model);
           Serializer.serialize(fileName, Soprano::SerializationTurtle);
       }
   }
void przegladarka::zapelnij_liste()       
{
    ui->pojeciaListWidget->clear();
    QList<SkosConcept> wszystkie;
    wszystkie=Model->getConcepts();
    //dla wszystkich konceptów:
    for(int i=0;i<wszystkie.size();i++){
        //dla wszystkich etykiet preferowanych
        for(int j=0;j<wszystkie.value(i).getLabelList(PrefferedLabelType).size();j++){
            if((wszystkie.value(i).getLabelList(PrefferedLabelType).value(j).language()==Jezyk)||(this->WszystkieJezyki)){
                ui->pojeciaListWidget->addItem(wszystkie.value(i).getLabelList(PrefferedLabelType).value(j).literal().toString());
            }
        }
        //dla wszystkich etykiet alternatywnych
        for(int j=0;j<wszystkie.value(i).getLabelList(AlternativeLabelType).size();j++){
            if((wszystkie.value(i).getLabelList(AlternativeLabelType).value(j).language()==Jezyk)||(this->WszystkieJezyki)){
                ui->pojeciaListWidget->addItem(wszystkie.value(i).getLabelList(AlternativeLabelType).value(j).literal().toString());
            }
        }
    }
    ui->pojeciaListWidget->sortItems(Qt::AscendingOrder);
}
void przegladarka::wczytaj()
  {
      QString fileName = QFileDialog::getOpenFileName(this,
          tr("Otworz Tezaurus"), "",
          tr("turtle(*.tur);; Wszystkie pliki(*)"));

      if (fileName.isEmpty())
          return;
      else {
          SkosParser Parser(Model);
          Parser.parseFile(fileName, Soprano::SerializationTurtle);
      }
      zapelnij_liste();
  }

void przegladarka::odswiez()
{   QString pom;
    pom=ui->znajdzLineEdit->text();
    int n;
    n=ui->pojeciaListWidget->count();
    for(int i=0;i<n;i++){
        if (ui->pojeciaListWidget->item(i)->text().contains(pom,Qt::CaseInsensitive)){
            ui->pojeciaListWidget->item(i)->setHidden(0);
            ui->pojeciaListWidget->setCurrentRow(i);}
        else
            ui->pojeciaListWidget->item(i)->setHidden(1);
    }
}
void przegladarka::inicjalizuj_jezyki(){
    this->ListaJezykow.push_back(Soprano::LanguageTag("pl"));
    this->ListaJezykow.push_back(Soprano::LanguageTag("en"));
}
void przegladarka::zaladuj_comboBox(){
    ui->comboBox->clear();
    ui->comboBox->addItem("wszystkie");
    for(int i=0;i<ListaJezykow.size();i++){
        ui->comboBox->addItem(ListaJezykow.value(i));
    }
    ui->comboBox->addItem("inny");
}

void przegladarka::zmien_jezyk(int numer)
{
    if(numer==0){
        WszystkieJezyki=true;
    }
    else{
        if(numer==ui->comboBox->count()-1){
            jezyk dod;
            dod.show();
            if (dod.exec() == QDialog::Accepted) {
                ListaJezykow.push_back(Soprano::LanguageTag(dod.skrot));
                Jezyk=ListaJezykow.value(numer-1);
                ui->comboBox->setItemText(numer,ListaJezykow.value(numer-1).toString());
                ui->comboBox->addItem("inny");
                WszystkieJezyki=false;
            }
            else
                ui->comboBox->setCurrentIndex(0);
        }
        else{
            WszystkieJezyki=false;
            Jezyk=ListaJezykow.value(numer-1);
        }
    }
    pokaz();
    zapelnij_liste();

}
void przegladarka::znajdz_szersze(QList<SkosConcept*>* lista,SkosConcept *pojecie, int glebokosc)
{
    if (!lista->contains(pojecie)){
        lista->push_back(pojecie);
    }
    if(glebokosc>0){
        for(int i=0;i<pojecie->getRelatedConceptsList(BroaderRelation).size();i++){
            SkosConcept* ptr = &(*(Model->findConcept(pojecie->getRelatedConceptsList(BroaderRelation).value(i))));
            znajdz_szersze(lista,ptr,glebokosc-1);
        }
    }
}

void przegladarka::znajdz_wezsze(QList<SkosConcept*>* lista,SkosConcept *pojecie, int glebokosc)
{
    if (!lista->contains(pojecie)){
        lista->push_back(pojecie);
    }
    if(glebokosc>0){
        for(int i=0;i<pojecie->getRelatedConceptsList(NarrowerRelation).size();i++){
            SkosConcept* ptr = &(*(Model->findConcept(pojecie->getRelatedConceptsList(NarrowerRelation).value(i))));
            znajdz_szersze(lista,ptr,glebokosc-1);
        }
    }
}
void przegladarka::znajdz_skojarzone(QList<SkosConcept*>* lista,SkosConcept *pojecie, int glebokosc)
{
    if (!lista->contains(pojecie)){
        lista->push_back(pojecie);
    }
    if(glebokosc>0){
        for(int i=0;i<pojecie->getRelatedConceptsList(RelatedRelation).size();i++){
            SkosConcept* ptr = &(*(Model->findConcept(pojecie->getRelatedConceptsList(RelatedRelation).value(i))));
            znajdz_szersze(lista,ptr,glebokosc-1);
        }
    }
}
