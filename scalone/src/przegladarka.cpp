#include "przegladarka.h"
#include "ui_przegladarka.h"
#include "edytor.h"
#include "ui_edytor.h"
#include "jezyk.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

przegladarka::przegladarka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::przegladarka)
{
    ui->setupUi(this);
    Model=SkosModel();
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
        edytor edyt(0,&Model,&Koncept,&ListaJezykow);
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
    SkosConcept Koncept=SkosConcept(QUrl("tmp"));
    Model.addConcept(QUrl("tmp"));
    edytor edyt(0,&Model,&Koncept,&ListaJezykow);
    edyt.show();
    if (edyt.exec() == QDialog::Accepted) {      
        zapelnij_liste();
    }
}
bool przegladarka::znajdz(QString slowo, SkosConcept& Koncept)
{
    bool znaleziony=false;
    QList<SkosConcept> wszystkie;
    wszystkie=Model.getConcepts();
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
        Koncept=Model.getConcepts().value(i-1);
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
    if (znajdz(slowo,Koncept))
        wyswietl(Koncept);
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
    for(int j=0;j<Koncept.getLabelList(AlternativeLabelType).size();j++){
        synonimy+=Koncept.getLabelList(AlternativeLabelType).value(j).literal().toString();
        synonimy+=' ';
    }
     ui->synonimyTextBrowser->setText(synonimy);

     QString definicja;
     for(int j=0;j<Koncept.getDefinitions().size();j++){
         definicja+=Koncept.getDefinitions().value(j).literal().toString();
         definicja+=QChar(QChar::LineSeparator);
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
           fileName+=".tur";
           SkosSerializer Serializer(&Model);
           Serializer.serialize(fileName, Soprano::SerializationTurtle);
       }
   }
void przegladarka::zapelnij_liste()       
{
    ui->pojeciaListWidget->clear();
    ui->znajdzLineEdit->setText("");
    QList<SkosConcept> wszystkie;
    wszystkie=Model.getConcepts();
    //dla wszystkich konceptów:
    for(int i=0;i<wszystkie.size();i++){
        //dla wszystkich labelek preferowanych
        for(int j=0;j<wszystkie.value(i).getLabelList(PrefferedLabelType).size();j++){
            if((wszystkie.value(i).getLabelList(PrefferedLabelType).value(j).language()==Jezyk)||(this->WszystkieJezyki)){
                ui->pojeciaListWidget->addItem(wszystkie.value(i).getLabelList(PrefferedLabelType).value(j).literal().toString());
            }
        }
        //dla wszystkich labelek alternatywnych
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
          SkosParser Parser(&Model);
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
    zapelnij_liste();
}
