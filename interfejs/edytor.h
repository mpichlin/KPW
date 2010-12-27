#ifndef EDYTOR_H
#define EDYTOR_H

#include <QDialog>

namespace Ui {
    class edytor;
}

class edytor : public QDialog {
    Q_OBJECT
public:
    edytor(QWidget *parent = 0);
    ~edytor();

private:
    Ui::edytor *ui;

public slots:
    void zmien_szersze();
    void dodaj_skojarzone();
    void dodaj_wezsze();
    void usun_skojarzone();
    void usun_wezsze();
    void zatwierdz();
};

#endif // EDYTOR_H
