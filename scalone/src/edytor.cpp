#include "edytor.h"
#include "ui_edytor.h"
#include "dodaj.h"
#include<QMessageBox>

edytor::edytor(QWidget *parent, SkosModel *model, SkosConcept *koncept, QList<Soprano::LanguageTag>* listaJ) :
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
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this, SLOT(zmien_jezyk(int)));

    connect(ui->alternatywneQlista, SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(dodaj_atlernatywne(QListWidgetItem*)));
    connect(ui->ukryteQlista, SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(dodaj_ukryte(QListWidgetItem*)));

    ui->UrlLineEdit->hide();
    this->Model=model;
    this->Koncept=koncept;
    this->ListaJezykow=listaJ;
    this->Jezyk="pl";
    przeladuj();
    zaladuj_comboBox();
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
    ui->alternatywneQlista->clear();
    for(int j=0;j<Koncept->getLabelList(AlternativeLabelType).size();j++){
       QListWidgetItem *pom = new QListWidgetItem();
       pom->setText(Koncept->getLabelList(AlternativeLabelType).value(j).literal().toString());
       pom->setFlags (pom->flags () | Qt::ItemIsEditable);
       ui->alternatywneQlista->insertItem(0,pom);
       if(Koncept->getLabelList(AlternativeLabelType).value(j).language()==Jezyk){
           ui->alternatywneQlista->item(0)->setHidden(false);
       }
       else{
           ui->alternatywneQlista->item(0)->setHidden(true);
       }
    }
    ui->alternatywneQlista->sortItems(Qt::AscendingOrder);
    QListWidgetItem *dodaj = new QListWidgetItem();
    dodaj->setText("DODAJ");
    dodaj->setFlags (dodaj->flags () | Qt::ItemIsEditable);
    ui->alternatywneQlista->insertItem(ui->alternatywneQlista->count(),dodaj);


    //zaladuj etykiety ukryte:
    ui->ukryteQlista->clear();
    for(int j=0;j<Koncept->getLabelList(HiddenLabelType).size();j++){
        QListWidgetItem *pom = new QListWidgetItem();
        pom->setText(Koncept->getLabelList(HiddenLabelType).value(j).literal().toString());
        pom->setFlags (pom->flags () | Qt::ItemIsEditable);
        ui->ukryteQlista->insertItem(0,pom);
        if(Koncept->getLabelList(HiddenLabelType).value(j).language()==Jezyk){
            ui->ukryteQlista->item(0)->setHidden(false);
        }
        else{
            ui->ukryteQlista->item(0)->setHidden(true);
        }
    }
    ui->ukryteQlista->sortItems(Qt::AscendingOrder);
    QListWidgetItem *dodaj1 = new QListWidgetItem();
    dodaj1->setText("DODAJ");
    dodaj1->setFlags (dodaj1->flags () | Qt::ItemIsEditable);
    ui->ukryteQlista->insertItem(ui->ukryteQlista->count(),dodaj1);


    //zaladuj preferowany:
    ui->preferowanyQline->clear();
    for(int j=0;j<Koncept->getLabelList(PrefferedLabelType).size();j++){
        if(Koncept->getLabelList(PrefferedLabelType).value(j).language()==Jezyk){
            ui->preferowanyQline->setText(Koncept->getLabelList(PrefferedLabelType).value(j).literal().toString());
        }
    }

    //zaladuj definicję:
    ui->definicjaText->clear();
    for(int j=0;j<Koncept->getDefinitions().size();j++){
        if(Koncept->getDefinitions().value(j).language()==Jezyk){
        ui->definicjaText->setPlainText(Koncept->getDefinitions().value(j).literal().toString());
        }
    }

    odswiez_wezsze();
    odswiez_szersze();
    odswiez_skojarzone();

}

void edytor::odswiez_wezsze()
{
    ui->wezszeQlista->clear();
    for(int j=0;j< Koncept->getRelatedConceptsList(NarrowerRelation).size();j++){
        QListWidgetItem *pom = new QListWidgetItem(ui->wezszeQlista);
        pom->setText(Koncept->getRelatedConceptsList(NarrowerRelation).value(j)->getUrl().toString());
    }
}
void edytor::odswiez_szersze()
{
    ui->szerszeQlista->clear();
    for(int j=0;j< Koncept->getRelatedConceptsList(BroaderRelation).size();j++){
        QListWidgetItem *pom = new QListWidgetItem(ui->szerszeQlista);
        pom->setText(Koncept->getRelatedConceptsList(BroaderRelation).value(j)->getUrl().toString());
    }
}
void edytor::odswiez_skojarzone()
{
    ui->skojarzoneQlista->clear();
    for(int j=0;j< Koncept->getRelatedConceptsList(RelatedRelation).size();j++){
        QListWidgetItem *pom = new QListWidgetItem(ui->skojarzoneQlista);
        pom->setText(Koncept->getRelatedConceptsList(RelatedRelation).value(j)->getUrl().toString());
    }

}

void edytor::zmien_szersze()
{
    Koncept = &(*(Model->findConcept(*Koncept)));
    dodaj dod(0,Model,Koncept,BroaderRelation);
    if (dod.exec() == QDialog::Accepted) {
        if(Koncept->getRelatedConceptsList(BroaderRelation).size()!=0){
            Model->removeConceptRelation(*Koncept,*Koncept->getRelatedConceptsList(BroaderRelation).value(0),BroaderRelation);
        }
        Koncept = &(*(Model->findConcept(*dod.Bazowy)));
        this->odswiez_szersze();
    }

}

void edytor::dodaj_wezsze()
{
    dodaj dod(0,Model,Koncept,NarrowerRelation);
    if (dod.exec() == QDialog::Accepted) {

        Koncept = &(*(Model->findConcept(*dod.Bazowy)));
        this->odswiez_wezsze();
    }

}
void edytor::usun_wezsze()
{
    if (ui->wezszeQlista->isItemSelected(ui->wezszeQlista->currentItem())) {
        int nr=ui->wezszeQlista->currentRow();
        Model->removeConceptRelation(*Koncept,*Koncept->getRelatedConceptsList(NarrowerRelation).value(nr),NarrowerRelation);
        Koncept = &(*(Model->findConcept(*Koncept)));
        this->odswiez_wezsze();
    }    
}
void edytor::dodaj_skojarzone()
{
    dodaj dod(0,Model,Koncept,RelatedRelation);
    if (dod.exec() == QDialog::Accepted) {
        Koncept = &(*(Model->findConcept(*dod.Bazowy)));
        this->odswiez_skojarzone();
    }
}
void edytor::usun_skojarzone()
{
    if (ui->skojarzoneQlista->isItemSelected(ui->skojarzoneQlista->currentItem())) {
        int nr=ui->skojarzoneQlista->currentRow();
        Model->removeConceptRelation(*Koncept,*Koncept->getRelatedConceptsList(RelatedRelation).value(nr),RelatedRelation);
        Koncept = &(*(Model->findConcept(*Koncept)));
        this->odswiez_skojarzone();
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
    //zmiana url:
    if (ui->domyslneUrlBox->isChecked()){
        Model->changeUrl(Koncept->getUrl(),QUrl(Koncept->getLabelList(PrefferedLabelType).value(0).literal().toString()));
    }
    else{
        Model->changeUrl(Koncept->getUrl(),QUrl(ui->UrlLineEdit->text()));
    }
    //usuniecie starych etykiet alternatywnych w danym jezyku:
    QList<Soprano::Node> stare;
    stare=Koncept->getLabelList(AlternativeLabelType);
    for(int i=0;i<stare.size();i++){
        if (stare.value(i).language()==Jezyk){
            Model->removeLabel(stare.value(i),AlternativeLabelType,Koncept->getUrl());
        }
    }
    //dodanie nowych etykiet alternatywnych w danym jezyku:
    for(int i=0;i<ui->alternatywneQlista->count()-1;i++){
        if(ui->alternatywneQlista->item(i)->text()!=""){
            if(ui->alternatywneQlista->item(i)->isHidden()==false){
                Soprano::Node lab = Soprano::Node(Soprano::LiteralValue::createPlainLiteral(ui->alternatywneQlista->item(i)->text(),Jezyk));
                Model->addLabel(lab,AlternativeLabelType,Koncept->getUrl());
            }
        }
    }

    //usuniecie starych etykiet ukrytych w danym jezyku:
    stare=Koncept->getLabelList(HiddenLabelType);
    for(int i=0;i<stare.size();i++){
        if (stare.value(i).language()==Jezyk){
           Model->removeLabel(stare.value(i),HiddenLabelType,Koncept->getUrl());
        }
    }

    //dodanie nowych etykiet ukrytych w danym jezyku:
    for(int i=0;i<ui->ukryteQlista->count()-1;i++){
        if(ui->ukryteQlista->item(i)->text()!=""){
            if (ui->ukryteQlista->item(i)->isHidden()==false){
                Soprano::Node lab = Soprano::Node(Soprano::LiteralValue::createPlainLiteral(ui->ukryteQlista->item(i)->text(),Jezyk));
                Model->addLabel(lab,HiddenLabelType,Koncept->getUrl());
            }
        }
    }

    //zmiana terminu preferowanego w danym jezyku:

    if(ui->preferowanyQline->text()!=""){

        stare=Koncept->getLabelList(PrefferedLabelType);
        for(int i=0;i<stare.size();i++){
            if (stare.value(i).language()==Jezyk){
               Model->removeLabel(stare.value(i),PrefferedLabelType,Koncept->getUrl());
            }
        }
        Soprano::Node lab = Soprano::Node(Soprano::LiteralValue::createPlainLiteral(ui->preferowanyQline->text(),Jezyk));
        Model->addLabel(lab,PrefferedLabelType,Koncept->getUrl());
    }

    //zmiana definicji w danym jezyku:
    stare=Koncept->getDefinitions();
    for(int i=0;i<stare.size();i++){
        if (stare.value(i).language()==Jezyk){
           Model->removeDefinition(stare.value(i),Koncept->getUrl());
        }
    }
    if (ui->definicjaText->toPlainText()!=""){
        Soprano::Node def = Soprano::Node(Soprano::LiteralValue::createPlainLiteral(ui->definicjaText->toPlainText(),Jezyk));
        Model->addDefinition(def,Koncept->getUrl());
    }
    this->accept();
}
void edytor::zaladuj_comboBox()
{
    ui->comboBox->clear();
    for(int i=0;i<ListaJezykow->size();i++){
        ui->comboBox->addItem(ListaJezykow->value(i));
    }
}

void edytor::zmien_jezyk(int numer)
{
    Jezyk=ListaJezykow->value(numer);
    przeladuj();
}


