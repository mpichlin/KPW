#include "edytor.h"
#include "ui_edytor.h"
#include "dodaj.h"
#include<QMessageBox>

edytor::edytor(QWidget *parent, SkosModel *model, SkosConcept *koncept, TrybType tryb) :
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

    connect(ui->alternatywneQlista, SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(dodaj_atlernatywne(QListWidgetItem*)));
    connect(ui->ukryteQlista, SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(dodaj_ukryte(QListWidgetItem*)));
    this->Tryb=tryb;
    this->Model=model;
    this->Koncept=koncept;
    if (tryb==Dodawanie){
        ui->usunButton->hide();
        ui->zatwierdzButton->setText("DODAJ");
    }
    przeladuj();
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
    //zaladuj etykiety alternatywne:
    for(int j=0;j<Koncept->getLabelList(AlternativeLabelType).size();j++){
       QListWidgetItem *pom = new QListWidgetItem();
       pom->setText(Koncept->getLabelList(AlternativeLabelType).value(j).literal().toString());
       pom->setFlags (pom->flags () | Qt::ItemIsEditable);
       ui->alternatywneQlista->insertItem(0,pom);
    }
    ui->alternatywneQlista->sortItems(Qt::AscendingOrder);
    QListWidgetItem *dodaj = new QListWidgetItem();
    dodaj->setText("DODAJ");
    dodaj->setFlags (dodaj->flags () | Qt::ItemIsEditable);
    ui->alternatywneQlista->insertItem(ui->alternatywneQlista->count(),dodaj);

    //zaladuj etykiety ukryte:
    for(int j=0;j<Koncept->getLabelList(HiddenLabelType).size();j++){
        QListWidgetItem *pom = new QListWidgetItem();
        pom->setText(Koncept->getLabelList(HiddenLabelType).value(j).literal().toString());
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
        ui->ukryteQlista->insertItem(0,pom);
    }
    ui->ukryteQlista->sortItems(Qt::AscendingOrder);
    QListWidgetItem *dodaj1 = new QListWidgetItem();
    dodaj1->setText("DODAJ");
    dodaj1->setFlags (dodaj1->flags () | Qt::ItemIsEditable);
    ui->ukryteQlista->insertItem(ui->ukryteQlista->count(),dodaj1);

    //zaladuj preferowany:
    ui->preferowanyQline->setText(Koncept->getLabelList(PrefferedLabelType).value(0).literal().toString());
    //zaladuj skojarzone:
    for(int j=0;j< Koncept->getRelatedConceptsList(RelatedRelation).size();j++){
        QListWidgetItem *pom = new QListWidgetItem(ui->skojarzoneQlista);
        pom->setText(Koncept->getRelatedConceptsList(RelatedRelation).value(j)->getUrl().toString());
    }
    //zaladuj wezsze
    for(int j=0;j< Koncept->getRelatedConceptsList(NarrowerRelation).size();j++){
        QListWidgetItem *pom = new QListWidgetItem(ui->wezszeQlista);
        pom->setText(Koncept->getRelatedConceptsList(NarrowerRelation).value(j)->getUrl().toString());
    }
    //zaladuj szersze
    for(int j=0;j< Koncept->getRelatedConceptsList(BroaderRelation).size();j++){
        QListWidgetItem *pom = new QListWidgetItem(ui->szerszeQlista);
        pom->setText(Koncept->getRelatedConceptsList(BroaderRelation).value(j)->getUrl().toString());
    }
    QString definicja;
    for(int j=0;j<Koncept->getDefinitions().size();j++){
        definicja+=Koncept->getDefinitions().value(j).literal().toString();
        definicja+=QChar(QChar::LineSeparator);
    }
    ui->definicjaText->setPlainText(definicja);
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
        int nr=ui->wezszeQlista->currentRow();
        Model->removeConceptRelation(*Koncept,*Koncept->getRelatedConceptsList(NarrowerRelation).value(nr),NarrowerRelation);
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
    if (ui->skojarzoneQlista->isItemSelected(ui->skojarzoneQlista->currentItem())) {
        int nr=ui->skojarzoneQlista->currentRow();
        Model->removeConceptRelation(*Koncept,*Koncept->getRelatedConceptsList(RelatedRelation).value(nr),RelatedRelation);
    }
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
{
    if(Tryb==Dodawanie)
    {
        if(ui->preferowanyQline->text()==""){
            return;
        }
        Koncept->setUrl(QUrl(ui->preferowanyQline->text()));

        Soprano::Node def= Soprano::Node(Soprano::LiteralValue(ui->definicjaText->toPlainText()));
        Koncept->addDefinition(def);

        Soprano::Node lab= Soprano::Node(Soprano::LiteralValue(ui->preferowanyQline->text()));
        Koncept->addLabel(lab,PrefferedLabelType);

        for(int i=0;i<ui->alternatywneQlista->count()-1;i++){
            Soprano::Node lab = Soprano::Node(Soprano::LiteralValue(ui->alternatywneQlista->item(i)->text()));
            Koncept->addLabel(lab,AlternativeLabelType);
        }
        for(int i=0;i<ui->ukryteQlista->count()-1;i++){
            Soprano::Node lab = Soprano::Node(Soprano::LiteralValue(ui->ukryteQlista->item(i)->text()));
            Koncept->addLabel(lab,HiddenLabelType);
        }
        Model->addConcept(*Koncept);
    }
    this->accept();
}
