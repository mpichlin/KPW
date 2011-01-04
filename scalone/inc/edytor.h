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
    edytor(QWidget *parent = 0, SkosModel* Model=0, SkosConcept* Koncept=0);
    ~edytor();

    //QString id;

    QString preferowany;
    QString definicja;
    QString przyklady;

    QList<QString> alternatywne;
    QList<QString> ukryte;
    QList<QString> wezsze;
    QList<QString> szersze;
    QList<QString> skojarzone;
    void przeladuj();


private:
    Ui::edytor *ui;
    SkosModel *Model;
    SkosConcept *Koncept;
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
