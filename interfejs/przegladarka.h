#ifndef PRZEGLADARKA_H
#define PRZEGLADARKA_H

#include <QMainWindow>

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
public slots:
    void edytuj();
    void pokaz();
    void zapisz();
    void wczytaj();

};

#endif // PRZEGLADARKA_H
