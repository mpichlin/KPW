#include "dodaj.h"
#include "ui_dodaj.h"
#include <QListWidget>
#include <QListWidgetItem>
dodaj::dodaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodaj)
{
    ui->setupUi(this);
    //wrzuc wszystkie koncepty na liste
    ui->listWidget->insertItem(1,"dupa");
    ui->listWidget->insertItem(1,"jasiu");
    ui->listWidget->insertItem(1,"salata");

    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this,
           SLOT(odswiez()));
}


dodaj::~dodaj()
{
    delete ui;
}
void dodaj::odswiez()
{   QString pom;
    pom=ui->lineEdit->text();
    int n;
    n=ui->listWidget->size();
    int i=1;
    while ((ui->listWidget->item(i)->text()<pom)&&(i<n)){
        ui->listWidget->item(i)->setHidden(1);
        i++;
    }

}
