#ifndef PRZEGLADARKA_H
#define PRZEGLADARKA_H

#include <QMainWindow>
#include "SkosParser.hpp"
#include "SkosSerializer.hpp"
#include "SkosModel.hpp"
#include "SkosConcept.hpp"
#include "edytor.h"
#include "ui_edytor.h"
#include <QList>
namespace Ui {
    class przegladarka;
}

class przegladarka : public QMainWindow {
    Q_OBJECT
public:
    przegladarka(SkosModel *p_model, QWidget *parent = 0);
    ~przegladarka();
private:
    Ui::przegladarka *ui;
    SkosModel* Model;
    Soprano::LanguageTag Jezyk;
    bool WszystkieJezyki;
    void zapelnij_liste();
    bool znajdz(QString, SkosConcept&);
    void wyswietl(SkosConcept);
    SkosConcept stworz_koncept(edytor edyt);
    QList<Soprano::LanguageTag> ListaJezykow;
    void znajdz_szersze(QList<SkosConcept*>* lista,SkosConcept* pojecie, int glebokosc);
    void znajdz_wezsze(QList<SkosConcept*>* lista,SkosConcept* pojecie, int glebokosc);
    void znajdz_skojarzone(QList<SkosConcept*>* lista,SkosConcept* pojecie, int glebokosc);
    void inicjalizuj_jezyki();
    void zaladuj_comboBox();
public slots:
    void edytuj();
    void dodaj();
    void pokaz();
    void zapisz();
    void wczytaj();
    void odswiez();
    void wstaw_z_listy();
    void zmien_jezyk(int);
    void czy_szersze(bool);
    void czy_wezsze(bool);
    void czy_skojarzone(bool);
    void szerszeSpinBoxChanged(int);
    void wezszeSpinBoxChanged(int);
    void skojarzoneSpinBoxChanged(int);
};
#endif // PRZEGLADARKA_H
