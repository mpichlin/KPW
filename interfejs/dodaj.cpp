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
    ui->listWidget->insertItem(1,"kupa");
    ui->listWidget->sortItems();
    ui->listWidget->setCurrentRow(0);
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
    n=ui->listWidget->count();
    for(int i=0;i<n;i++){
        if (ui->listWidget->item(i)->text().contains(pom)){
            ui->listWidget->item(i)->setHidden(0);
            ui->listWidget->setCurrentRow(i);}
        else
            ui->listWidget->item(i)->setHidden(1);
    }
}
