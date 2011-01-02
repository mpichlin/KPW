#include "przegladarka.h"
#include "ui_przegladarka.h"
#include "edytor.h"
#include "ui_edytor.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

przegladarka::przegladarka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::przegladarka)
{
    ui->setupUi(this);

    connect(ui->edytujButton, SIGNAL(clicked()), this,SLOT(edytuj()));
    connect(ui->dodajButton, SIGNAL(clicked()), this,SLOT(dodaj()));
    connect(ui->pokazButton, SIGNAL(clicked()), this,SLOT(pokaz()));
    connect(ui->actionZapisz, SIGNAL(triggered()), this,SLOT (zapisz()));
    connect(ui->actionWczytaj, SIGNAL(triggered()), this,SLOT (wczytaj()));
    connect(ui->znajdzLineEdit, SIGNAL(textEdited(QString)), this,SLOT(odswiez()));
    connect(ui->pojeciaListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(wstaw_z_listy()));

    Model=SkosModel();


    }

przegladarka::~przegladarka()
{
    delete ui;
}
void przegladarka::edytuj()
{
    edytor edyt;
    QString slowo = ui->znajdzLineEdit->text();
    SkosConcept Koncept;
    if (znajdz(slowo,Koncept)){
        QList<SkosConcept>::iterator iter;
        iter=Model.findConcept(Koncept);
        for(int j=0;j<Koncept.getLabelList(AlternativeLabelType).size();j++){
          edyt.alternatywne.push_back(Koncept.getLabelList(AlternativeLabelType).value(j).literal().toString());
        }
        for(int j=0;j<Koncept.getLabelList(HiddenLabelType).size();j++){
          edyt.ukryte.push_back(Koncept.getLabelList(HiddenLabelType).value(j).literal().toString());
        }
        for(int j=0;j<Koncept.getLabelList(PrefferedLabelType).size();j++){
          edyt.preferowany=Koncept.getLabelList(PrefferedLabelType).value(j).literal().toString();
        }
        for(int j=0;j< Koncept.getRelatedConceptsList(RelatedRelation).size();j++){
          edyt.skojarzone.push_back(Koncept.getRelatedConceptsList(RelatedRelation).value(j)->getUrl().toString());
        }
        for(int j=0;j< Koncept.getRelatedConceptsList(NarrowerRelation).size();j++){
          edyt.wezsze.push_back(Koncept.getRelatedConceptsList(NarrowerRelation).value(j)->getUrl().toString());
        }
        for(int j=0;j< Koncept.getRelatedConceptsList(BroaderRelation).size();j++){
          edyt.szersze.push_back(Koncept.getRelatedConceptsList(BroaderRelation).value(j)->getUrl().toString());
        }
        for(int j=0;j<Koncept.getDefinitions().size();j++){
          edyt.definicja+=Koncept.getDefinitions().value(j).literal().toString();
          edyt.definicja+=QChar(QChar::LineSeparator);
        }
        edyt.przeladuj();
        edyt.show();
        if (edyt.exec() == QDialog::Accepted) {   ;

           //zapelnij_liste();
        }
    }
    else{
            QMessageBox::information(this, tr("Nie znaleziono"),
              tr("Niestety nie ma wyrazu \"%1\" w bazie").arg(slowo));
    }
}

void przegladarka::dodaj()
{
    edytor edyt;
    edyt.przeladuj();
    edyt.show();
    if (edyt.exec() == QDialog::Accepted) {

        SkosConcept Koncept=SkosConcept(QUrl(edyt.preferowany));

        Soprano::Node def= Soprano::Node(Soprano::LiteralValue(edyt.definicja));
        Koncept.addDefinition(def);

        Soprano::Node lab= Soprano::Node(Soprano::LiteralValue(edyt.preferowany));
        Koncept.addLabel(lab,PrefferedLabelType);

        for(int i=0;i<edyt.alternatywne.size();i++){
            Soprano::Node lab = Soprano::Node(Soprano::LiteralValue(edyt.alternatywne.value(i)));
            Koncept.addLabel(lab,AlternativeLabelType);
        }

        for(int i=0;i<edyt.ukryte.size();i++){
            Soprano::Node lab = Soprano::Node(Soprano::LiteralValue(edyt.ukryte.value(i)));
            Koncept.addLabel(lab,HiddenLabelType);
        }
        Model.addConcept(Koncept);
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
{    QString slowo = ui->znajdzLineEdit->text();
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
/*
     QString powiazane;
     if (ui->skojarzoneBox->isChecked()){
     for(int j=0;j< Koncept.getRelatedConceptsList(RelatedRelation).size();j++){
         for(int k=0; k<Koncept.getRelatedConceptsList(RelatedRelation).value(j)->getLabelList(PrefferedLabelType).size;k++)
            powiazane+=Koncept.getRelatedConceptsList(RelatedRelation).value(j)->getLabelList(PrefferedLabelType).value(k).literal().toString();
            powiazane+=' ';
     }



     ui->powiazaneTextBrowser->setText(powiazane);
     */

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
{   //dla wszystkich konceptów:
    for(int i=0;i<Model.getConcepts().size();i++){
        //dla wszystkich labelek preferowanych
        for(int j=0;j<Model.getConcepts().value(i).getLabelList(PrefferedLabelType).size();j++)
            ui->pojeciaListWidget->addItem(Model.getConcepts().value(i).getLabelList(PrefferedLabelType).value(j).literal().toString());
        //dla wszystkich labelek alternatywnych
        for(int j=0;j<Model.getConcepts().value(i).getLabelList(AlternativeLabelType).size();j++)
            ui->pojeciaListWidget->addItem(Model.getConcepts().value(i).getLabelList(AlternativeLabelType).value(j).literal().toString());
    }

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
