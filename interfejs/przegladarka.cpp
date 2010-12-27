#include "przegladarka.h"
#include "ui_przegladarka.h"
#include "edytor.h"
#include <QMessageBox>
#include <QFileDialog>

przegladarka::przegladarka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::przegladarka)
{
    ui->setupUi(this);

    connect(ui->edytujButton, SIGNAL(clicked()), this,
           SLOT(edytuj()));
    connect(ui->pokazButton, SIGNAL(clicked()), this,
           SLOT(pokaz()));
    connect(ui->actionZapisz, SIGNAL(triggered()), this,
           SLOT (zapisz()));
    connect(ui->actionWczytaj, SIGNAL(triggered()), this,
           SLOT (zapisz()));
}

przegladarka::~przegladarka()
{
    delete ui;
}
void przegladarka::edytuj()
{
    edytor edyt;
    edyt.show();
    if (edyt.exec() == QDialog::Accepted) {
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
       else {
           QFile file(fileName);

           if (!file.open(QIODevice::WriteOnly)) {
               QMessageBox::information(this, tr("Nie można odczytac pliku"),
                   file.errorString());
               return;
           }
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
          QFile file(fileName);

          if (!file.open(QIODevice::ReadOnly)) {
              QMessageBox::information(this, tr("Nie można otworzyc pliku"),
                  file.errorString());
              return;
          }
      }
  }
