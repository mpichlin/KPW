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

    connect(ui->edytujButton, SIGNAL(clicked()), this,
           SLOT(edytuj()));
    connect(ui->dodajButton, SIGNAL(clicked()), this,
           SLOT(dodaj()));
    connect(ui->pokazButton, SIGNAL(clicked()), this,
           SLOT(pokaz()));
    connect(ui->actionZapisz, SIGNAL(triggered()), this,
           SLOT (zapisz()));
    connect(ui->actionWczytaj, SIGNAL(triggered()), this,
           SLOT (wczytaj()));

    Model=SkosModel();


    }

przegladarka::~przegladarka()
{
    delete ui;
}
void przegladarka::edytuj()
{
    edytor edyt;
    //ustaw wszystkie pola
    edyt.alternatywne.push_back("1");
    edyt.alternatywne.push_back("2");
    edyt.alternatywne.push_back("3");
    edyt.alternatywne.push_back("4");
    edyt.alternatywne.push_back("5");
    edyt.alternatywne.push_back("6");
    edyt.alternatywne.push_back("7");
    edyt.preferowany=ui->znajdzLineEdit->text();
    edyt.przeladuj();
    edyt.show();
    if (edyt.exec() == QDialog::Accepted) {
    }

}
void przegladarka::dodaj()
{
    edytor edyt;
    edyt.przeladuj();
    edyt.show();
    if (edyt.exec() == QDialog::Accepted) {

        SkosConcept *Koncept=new SkosConcept;

        Soprano::Node pom= Soprano::Node(edyt.definicja);
        Koncept->addDefinition(pom);

        Model.addConcept(*Koncept);
    }

}

void przegladarka::pokaz()
//Poszukuje słowa pobranego z linii, wśród wszystkich zawartych w tezaurusie słowach i pokazuje odpodiedni koncept i jego pokrewne zgodnie z określonymi wlaściwościami.
//W przeciwnym razie zwraca informacje o braku słowa w bazie
{
    QString slowo = ui->znajdzLineEdit->text();
    QMessageBox::information(this, tr("Nie znaleziono"),
         tr("Niestety nie ma wyrazu \"%1\" w bazie").arg(slowo));
}
void przegladarka::zapisz()

   {
       QString fileName = QFileDialog::getSaveFileName(this,
           tr("Zapisz Tezaurus jako"), "",
           tr("tezaurus (*.tzs);; Wszystkie pliki (*)"));

       if (fileName.isEmpty())
           return;
       else{
           SkosSerializer Serializer(&Model);
           Serializer.serialize(fileName, Soprano::SerializationTurtle);
       }
   }

void przegladarka::wczytaj()
  {
      QString fileName = QFileDialog::getOpenFileName(this,
          tr("Otworz Tezaurus"), "",
          tr("tezaurus(*.tzs);; Wszystkie pliki(*)"));

      if (fileName.isEmpty())
          return;
      else {
          SkosParser Parser(&Model);
          Parser.parseFile(fileName, Soprano::SerializationTurtle);
      }
  }
