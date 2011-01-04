#include "edytor.h"
#include "ui_edytor.h"
#include "dodaj.h"
#include<QMessageBox>

edytor::edytor(QWidget *parent, SkosModel *model, SkosConcept *koncept) :
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
    connect(ui->usunButton, SIGNAL(clicked()), this,
                                   SLOT(usun()));
    this->Model=model;
    this->Koncept=koncept;
}
edytor::~edytor()
{
    delete ui;
}
void edytor::dodaj_atlernatywne(QListWidgetItem* zmieniona)
{
    if (ui->alternatywneQlista->row(zmieniona)==ui->alternatywneQlista->count()-1){   
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
    ui->wezszeQlista->insertItem(ui->ukryteQlista->count(),pom1);

    for(int i=0;i<szersze.size();i++){
        QListWidgetItem *pom = new QListWidgetItem(ui->szerszeQlista);
        pom->setText(this->szersze.takeAt(i));
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);

    }
    for(int i=0;i<skojarzone.size();i++){
        QListWidgetItem *pom = new QListWidgetItem(ui->skojarzoneQlista);
        pom->setText(this->skojarzone.takeAt(i));
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
    dodaj dod(0,Model,Koncept,NarrowerRelation);
    if (dod.exec() == QDialog::Accepted) {
    }
}
void edytor::usun_wezsze()
{
    if (ui->wezszeQlista->isItemSelected(ui->wezszeQlista->currentItem())) {
        SkosConcept usuwany; bool znaleziony=false;
        QString slowo = ui->wezszeQlista->currentItem()->text();
        QList<SkosConcept> wszystkie;
        wszystkie=Model->getConcepts();
        int i=0;
        int j=0;
        while (!znaleziony && i<wszystkie.size()) {
            j=0;
            while(!znaleziony && j<wszystkie.value(i).getLabelList(PrefferedLabelType).size()){
                if (wszystkie.value(i).getLabelList(PrefferedLabelType).value(j).literal().toString()==slowo)
                    znaleziony=true;
                j++;
                }
            i++;
        }
    //Model->removeConceptRelation(*Koncept,wszystkie.value(i),NarrowerRelation);
    }
}
void edytor::dodaj_skojarzone()
{
    dodaj dod(0,Model,Koncept,RelatedRelation);
    if (dod.exec() == QDialog::Accepted) {
    }
}
void edytor::usun_skojarzone()
{

}
void edytor::usun()
{
    QMessageBox potw;
    potw.setIcon(QMessageBox::Question);
    potw.setText("Bezpowrotnie usunac pojecie?");
    potw.setStandardButtons(QMessageBox::Ok| QMessageBox::Cancel);
    int ret=potw.exec();
    switch (ret) {
      case QMessageBox::Ok:
          Model->removeConcept(*Koncept);
          this->accept();
          break;
      case QMessageBox::Cancel:
          break;
    }
}
void edytor::zatwierdz()
{//przepisanie zawartości pól edycyjnych:
    this->preferowany=ui->preferowanyQline->text();
    this->definicja=ui->definicjaText->toPlainText();
    this->przyklady=ui->przykladyText->toPlainText();
    this->alternatywne.clear();
    for(int i=0;i<ui->alternatywneQlista->count()-1;i++){
        this->alternatywne.push_back(ui->alternatywneQlista->item(i)->text());
    }
    this->ukryte.clear();
    for(int i=0;i<ui->ukryteQlista->count()-1;i++){
        this->ukryte.push_back(ui->ukryteQlista->item(i)->text());
    }
    this->accept();
}
