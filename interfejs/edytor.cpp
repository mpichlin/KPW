#include "edytor.h"
#include "ui_edytor.h"

edytor::edytor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edytor)
{
    ui->setupUi(this);
}

edytor::~edytor()
{
    delete ui;
}

void edytor::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
