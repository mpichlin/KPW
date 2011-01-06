#ifndef JEZYK_H
#define JEZYK_H

#include <QDialog>

namespace Ui {
    class jezyk;
}

class jezyk : public QDialog {
    Q_OBJECT

public:
    jezyk(QWidget *parent = 0);
    ~jezyk();
    QString skrot;

private:
    Ui::jezyk *ui;

public slots:
    void zakoncz();
};

#endif // JEZYK_H
