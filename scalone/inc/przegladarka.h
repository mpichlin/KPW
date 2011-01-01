#ifndef PRZEGLADARKA_H
#define PRZEGLADARKA_H

#include <QMainWindow>
#include "SkosParser.hpp"
#include "SkosSerializer.hpp"
#include "SkosModel.hpp"
#include "SkosConcept.hpp"
#include "edytor.h"
#include "ui_edytor.h"

namespace Ui {
    class przegladarka;
}

class przegladarka : public QMainWindow {
    Q_OBJECT
public:
    przegladarka(QWidget *parent = 0);
    ~przegladarka();
private:
    Ui::przegladarka *ui;
    SkosModel Model;
    void zapelnij_liste();
    bool znajdz(QString, SkosConcept&);
    void wyswietl(SkosConcept);
    SkosConcept stworz_koncept(edytor edyt);
public slots:
    void edytuj();
    void dodaj();
    void pokaz();
    void zapisz();
    void wczytaj();
    void odswiez();
    void wstaw_z_listy();
signals:
    QList<SkosConcept> lista_konceptow();

};
#endif // PRZEGLADARKA_H
