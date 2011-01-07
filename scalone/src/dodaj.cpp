#include "dodaj.h"
#include "ui_dodaj.h"
#include <QListWidget>
#include <QListWidgetItem>
dodaj::dodaj(QWidget *parent, SkosModel *model, SkosConcept p_bazowyKoncept, ERelationType typ) :
    QDialog(parent),
    ui(new Ui::dodaj),
    m_bazowyKoncept(p_bazowyKoncept)
{
    this->Model=model;
    this->TypRelacji=typ;
    ui->setupUi(this);
    //wrzuc wszystkie koncepty na liste:
    ui->pojeciaListWidget->clear();
    ui->znajdzLineEdit->setText("");
    //dla wszystkich konceptów:
    for(int i=0;i<Model->getConcepts().size();i++){
        //dla wszystkich etykiet preferowanych:
        for(int j=0;j<Model->getConcepts().value(i).getLabelList(PrefferedLabelType).size();j++)
            ui->pojeciaListWidget->addItem(Model->getConcepts().value(i).getLabelList(PrefferedLabelType).value(j).literal().toString());
    }
    ui->pojeciaListWidget->sortItems();
    ui->pojeciaListWidget->setCurrentRow(0);

    connect(ui->znajdzLineEdit, SIGNAL(textEdited(QString)), this,
           SLOT(odswiez()));
    connect(ui->okButton, SIGNAL(clicked()), this,
                                    SLOT(zakoncz()));
}

dodaj::~dodaj()
{
    delete ui;
}
void dodaj::odswiez()
{   QString pom;
    pom=ui->znajdzLineEdit->text();
    int n;
    n=ui->pojeciaListWidget->count();
    for(int i=0;i<n;i++){
        if (ui->pojeciaListWidget->item(i)->text().contains(pom,Qt::CaseInsensitive)){
            ui->pojeciaListWidget->item(i)->setHidden(0);
            ui->pojeciaListWidget->setCurrentRow(i);}
        else
            ui->pojeciaListWidget->item(i)->setHidden(1);
    }
}
void dodaj::zakoncz()
{
    QString slowo=ui->pojeciaListWidget->currentItem()->text();
    bool znaleziony=false;
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
    SkosConcept dodawany=wszystkie.value(i-1);
    SkosConcept* ptrNaDodawany = &(*(Model->findConcept(dodawany)));
    SkosConcept* ptrNaBazowy = &(*(Model->findConcept(m_bazowyKoncept)));
    Model->addConceptRelation(*ptrNaBazowy,*ptrNaDodawany,TypRelacji);
    this->accept();
}
