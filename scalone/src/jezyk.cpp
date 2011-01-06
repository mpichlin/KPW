#include "jezyk.h"
#include "ui_jezyk.h"

jezyk::jezyk(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::jezyk)
{
    ui->setupUi(this);
    connect(ui->okButton, SIGNAL(clicked()), this,
           SLOT(zakoncz()));
}

jezyk::~jezyk()
{
    delete ui;
}
void jezyk::zakoncz()
{
    skrot=ui->lineEdit->text();
    this->accept();
}
