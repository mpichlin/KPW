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
                                   SLOT(dodaj_atlernatywne()));
    connect(ui->zatwierdzButton, SIGNAL(clicked()), this,
                                   SLOT(zatwierdz()));
}
edytor::~edytor()
{
    delete ui;
}
void edytor::dodaj_atlernatywne(QListWidgetItem* zmieniona)
{
    if (ui->alternatywneQlista->row(zmieniona)==ui->alternatywneQlista->count()-1){   
        ui->preferowanyQline->setText("dupa");
        ui->alternatywneQlista->sortItems(Qt::AscendingOrder);

        QListWidgetItem *pom = new QListWidgetItem();
        pom->setText("DODAJ");
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
        ui->alternatywneQlista->insertItem(ui->alternatywneQlista->count(),pom);
    }
}

void edytor::dodaj_ukryte(QListWidgetItem* zmieniona)
{
    if (ui->ukryteQlista->row(zmieniona)==ui->ukryteQlista->count()-1){
        ui->ukryteQlista->sortItems(Qt::AscendingOrder);

        QListWidgetItem *pom = new QListWidgetItem();
        pom->setText("DODAJ");
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
        ui->ukryteQlista->insertItem(ui->ukryteQlista->count(),pom);
    }
}

void edytor::przeladuj(){
//zaladuj wszystkie pola:

    ui->definicjaText->setPlainText(this->definicja);
    ui->przykladyText->setPlainText(this->przyklady);
    ui->preferowanyQline->setText(this->preferowany);
    for(int i=0;i<alternatywne.size();i++){
        QListWidgetItem *pom = new QListWidgetItem(ui->alternatywneQlista);
        pom->setText(this->alternatywne.value(i));
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
    }
    ui->alternatywneQlista->sortItems(Qt::AscendingOrder);

    QListWidgetItem *pom = new QListWidgetItem();
    pom->setText("DODAJ");
    pom->setFlags (pom->flags () | Qt::ItemIsEditable);
    ui->alternatywneQlista->insertItem(ui->alternatywneQlista->count(),pom);



    for(int i=0;i<ukryte.size();i++){
        QListWidgetItem *pom = new QListWidgetItem(ui->ukryteQlista);
        pom->setText(this->ukryte.takeAt(i));
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
    }
    ui->ukryteQlista->sortItems(Qt::AscendingOrder);
    QListWidgetItem *pom1 = new QListWidgetItem();
    pom1->setText("DODAJ");
    pom1->setFlags (pom1->flags () | Qt::ItemIsEditable);
    ui->ukryteQlista->insertItem(ui->ukryteQlista->count(),pom1);

    for(int i=0;i<wezsze.size();i++){
        QListWidgetItem *pom = new QListWidgetItem(ui->wezszeQlista);
        pom->setText(this->wezsze.takeAt(i));
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
    }


    for(int i=0;i<szersze.size();i++){
        QListWidgetItem *pom = new QListWidgetItem(ui->szerszeQlista);
        pom->setText(this->szersze.takeAt(i));
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
    }
    connect(ui->alternatywneQlista, SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(dodaj_atlernatywne(QListWidgetItem*)));
    connect(ui->ukryteQlista, SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(dodaj_ukryte(QListWidgetItem*)));
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
{//przepisanie zawartości pól edycyjnych:
    this->preferowany=ui->preferowanyQline->text();
    this->definicja=ui->definicjaText->toPlainText();
    this->przyklady=ui->przykladyText->toPlainText();
    //this->alternatywne=ui->alternatywneQlista->


    this->accept();
}
