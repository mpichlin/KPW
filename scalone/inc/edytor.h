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
class edytor : public QDialog {
    Q_OBJECT
public:
    edytor(QWidget *parent = 0, SkosModel* Model=0, SkosConcept* Koncept=0,QList<Soprano::LanguageTag>* ListaJezykow=0);
    ~edytor();
private:
    Ui::edytor *ui;
    SkosModel *Model;
    SkosConcept *Koncept;
    Soprano::LanguageTag Jezyk;
    QList<Soprano::LanguageTag>* ListaJezykow;
    void przeladuj();
    void odswiez_wezsze();
    void odswiez_szersze();
    void odswiez_skojarzone();
    void zaladuj_comboBox();



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
    void zmien_jezyk(int numer);
};

#endif // EDYTOR_H
