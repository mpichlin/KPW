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

protected:
    void changeEvent(QEvent *e);

private:
    Ui::przegladarka *ui;
public slots:
    void otworz_edytor();
};

#endif // PRZEGLADARKA_H
