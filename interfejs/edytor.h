#ifndef EDYTOR_H
#define EDYTOR_H

#include <QWidget>

namespace Ui {
    class edytor;
}

class edytor : public QWidget {
    Q_OBJECT
public:
    edytor(QWidget *parent = 0);
    ~edytor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::edytor *ui;
};

#endif // EDYTOR_H
