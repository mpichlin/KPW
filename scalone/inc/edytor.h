#ifndef EDYTOR_H
#define EDYTOR_H

#include <QDialog>
#include <QString>
#include <QList>
#include <QListWidgetItem>
#include "SkosConcept.hpp"
#include "SkosModel.hpp"
namespace Ui {
    class edytor;
}
enum TrybType
{
  Edycja   = 0,
  Dodawanie = 1,
};

class edytor : public QDialog {
    Q_OBJECT
public:
    edytor(QWidget *parent = 0, SkosModel* Model=0, SkosConcept* Koncept=0, TrybType Tryb=Edycja);
    ~edytor();
private:
    Ui::edytor *ui;
    SkosModel *Model;
    SkosConcept *Koncept;
    TrybType Tryb;
    void przeladuj();

public slots:
    void zmien_szersze();
    void dodaj_skojarzone();
    void dodaj_wezsze();
    void usun_skojarzone();
    void usun_wezsze();
    void zatwierdz();
    void dodaj_atlernatywne(QListWidgetItem*);
    void dodaj_ukryte(QListWidgetItem*);
    void usun();
};

#endif // EDYTOR_H
