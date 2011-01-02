#ifndef EDYTOR_H
#define EDYTOR_H

#include <QDialog>
#include <QString>
#include <QList>
#include <QListWidgetItem>
#include "SkosConcept.hpp"
namespace Ui {
    class edytor;
}

class edytor : public QDialog {
    Q_OBJECT
public:
    edytor(QWidget *parent = 0);
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
public slots:
    void zmien_szersze();
    void dodaj_skojarzone();
    void dodaj_wezsze();
    void usun_skojarzone();
    void usun_wezsze();
    void zatwierdz();
    void dodaj_atlernatywne(QListWidgetItem*);
    void dodaj_ukryte(QListWidgetItem*);

};

#endif // EDYTOR_H
