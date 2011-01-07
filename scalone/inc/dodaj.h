#ifndef DODAJ_H
#define DODAJ_H

#include <QDialog>
#include "SkosModel.hpp"
#include "SkosConcept.hpp"

namespace Ui {
    class dodaj;
}

class dodaj : public QDialog {
    Q_OBJECT
public:
    dodaj(QWidget *parent = 0,SkosModel *model=0, SkosConcept* bazowy=0, ERelationType typ=RelatedRelation);
    ~dodaj();
    SkosConcept *Bazowy;

private:
    Ui::dodaj *ui;
    SkosModel *Model;

    ERelationType TypRelacji;
public slots:
    void odswiez();
    void zakoncz();
};

#endif // DODAJ_H
