#ifndef PRZEGLADARKA_H
#define PRZEGLADARKA_H

#include <QMainWindow>
#include "SkosParser.hpp"
#include "SkosSerializer.hpp"
#include "SkosModel.hpp"
#include "SkosConcept.hpp"

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
public slots:
    void edytuj();
    void dodaj();
    void pokaz();
    void zapisz();
    void wczytaj();
};
#endif // PRZEGLADARKA_H
