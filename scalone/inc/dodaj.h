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
    dodaj(QWidget *parent = 0,SkosModel *model=0, SkosConcept p_bazowyKoncept = SkosConcept(QUrl("empty")), ERelationType typ=RelatedRelation);
    ~dodaj();

private:
    Ui::dodaj *ui;
    SkosConcept m_bazowyKoncept;
    SkosModel *Model;

    ERelationType TypRelacji;
public slots:
    void odswiez();
    void zakoncz();
};

#endif // DODAJ_H
