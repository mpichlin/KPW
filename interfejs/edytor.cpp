#include "edytor.h"
#include "ui_edytor.h"
#include "dodaj.h"

edytor::edytor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edytor)
{
    ui->setupUi(this);

    connect(ui->zmienButton, SIGNAL(clicked()), this,
           SLOT(zmien_szersze()));
    connect(ui->dodaj_wezszeButton, SIGNAL(clicked()), this,
                                   SLOT(dodaj_wezsze()));
    connect(ui->usun_wezszeButton, SIGNAL(clicked()), this,
                                   SLOT(usun_wezsze()));
    connect(ui->dodaj_skojarzoneButton, SIGNAL(clicked()), this,
                                   SLOT(dodaj_skojarzone()));
    connect(ui->usun_skojarzoneButton, SIGNAL(clicked()), this,
                                   SLOT(usun_skojarzone()));
    connect(ui->zatwierdzButton, SIGNAL(clicked()), this,
                                   SLOT(zatwierdz()));
}
edytor::~edytor()
{
    delete ui;
}
void edytor::zmien_szersze()
{

}

void edytor::dodaj_wezsze()
{
    dodaj dod;
    if (dod.exec() == QDialog::Accepted) {
    }
}
void edytor::usun_wezsze()
{

}
void edytor::dodaj_skojarzone()
{
    dodaj dod;
    if (dod.exec() == QDialog::Accepted) {
    }

}
void edytor::usun_skojarzone()
{

}
void edytor::zatwierdz()
{
    this->accept();
}
