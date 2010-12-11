#include "przegladarka.h"
#include "ui_przegladarka.h"
#include "edytor.h"

przegladarka::przegladarka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::przegladarka)
{
    ui->setupUi(this);

    connect(ui->edytujButton, SIGNAL(clicked()), this,
           SLOT(otworz_edytor()));
}

przegladarka::~przegladarka()
{
    delete ui;
}

void przegladarka::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void przegladarka::otworz_edytor()
{

}
