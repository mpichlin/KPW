/********************************************************************************
** Form generated from reading UI file 'przegladarka.ui'
**
** Created: Wed Jan 5 00:16:01 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRZEGLADARKA_H
#define UI_PRZEGLADARKA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_przegladarka
{
public:
    QAction *actionWczytaj;
    QAction *actionZapisz;
    QAction *actionKoniec;
    QAction *actionO_programie;
    QAction *actionDokumentacja;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *znajdzLineEdit;
    QListWidget *pojeciaListWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pokazButton;
    QVBoxLayout *verticalLayout_11;
    QPushButton *edytujButton;
    QPushButton *dodajButton;
    QGridLayout *gridLayout;
    QCheckBox *wezszeBox;
    QCheckBox *szerszeBox;
    QCheckBox *skojarzoneBox;
    QSpinBox *wezsze_spinBox;
    QSpinBox *szersze_spinBox;
    QSpinBox *skumulowane_spinBox;
    QCheckBox *definicjaBox;
    QCheckBox *skumulowaneBox;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QTextBrowser *synonimyTextBrowser;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QTextBrowser *definicjaTextBrowser;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QTextBrowser *powiazaneTextBrowser;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QTextBrowser *syn_powTextBrowser;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QTextBrowser *skumulowaneTextBrowser;
    QMenuBar *menubar;
    QMenu *Plik;
    QMenu *menuPomoc;

    void setupUi(QMainWindow *przegladarka)
    {
        if (przegladarka->objectName().isEmpty())
            przegladarka->setObjectName(QString::fromUtf8("przegladarka"));
        przegladarka->resize(749, 727);
        actionWczytaj = new QAction(przegladarka);
        actionWczytaj->setObjectName(QString::fromUtf8("actionWczytaj"));
        actionZapisz = new QAction(przegladarka);
        actionZapisz->setObjectName(QString::fromUtf8("actionZapisz"));
        actionKoniec = new QAction(przegladarka);
        actionKoniec->setObjectName(QString::fromUtf8("actionKoniec"));
        actionO_programie = new QAction(przegladarka);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        actionDokumentacja = new QAction(przegladarka);
        actionDokumentacja->setObjectName(QString::fromUtf8("actionDokumentacja"));
        centralwidget = new QWidget(przegladarka);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_10 = new QVBoxLayout(centralwidget);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        znajdzLineEdit = new QLineEdit(centralwidget);
        znajdzLineEdit->setObjectName(QString::fromUtf8("znajdzLineEdit"));

        verticalLayout->addWidget(znajdzLineEdit);

        pojeciaListWidget = new QListWidget(centralwidget);
        pojeciaListWidget->setObjectName(QString::fromUtf8("pojeciaListWidget"));

        verticalLayout->addWidget(pojeciaListWidget);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pokazButton = new QPushButton(centralwidget);
        pokazButton->setObjectName(QString::fromUtf8("pokazButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pokazButton->sizePolicy().hasHeightForWidth());
        pokazButton->setSizePolicy(sizePolicy);
        pokazButton->setMinimumSize(QSize(0, 27));
        pokazButton->setMaximumSize(QSize(16777215, 60));

        horizontalLayout->addWidget(pokazButton);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        edytujButton = new QPushButton(centralwidget);
        edytujButton->setObjectName(QString::fromUtf8("edytujButton"));

        verticalLayout_11->addWidget(edytujButton);

        dodajButton = new QPushButton(centralwidget);
        dodajButton->setObjectName(QString::fromUtf8("dodajButton"));

        verticalLayout_11->addWidget(dodajButton);


        horizontalLayout->addLayout(verticalLayout_11);


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        wezszeBox = new QCheckBox(centralwidget);
        wezszeBox->setObjectName(QString::fromUtf8("wezszeBox"));
        wezszeBox->setChecked(true);

        gridLayout->addWidget(wezszeBox, 0, 0, 1, 1);

        szerszeBox = new QCheckBox(centralwidget);
        szerszeBox->setObjectName(QString::fromUtf8("szerszeBox"));
        szerszeBox->setChecked(true);

        gridLayout->addWidget(szerszeBox, 1, 0, 1, 1);

        skojarzoneBox = new QCheckBox(centralwidget);
        skojarzoneBox->setObjectName(QString::fromUtf8("skojarzoneBox"));
        skojarzoneBox->setChecked(true);

        gridLayout->addWidget(skojarzoneBox, 2, 0, 1, 1);

        wezsze_spinBox = new QSpinBox(centralwidget);
        wezsze_spinBox->setObjectName(QString::fromUtf8("wezsze_spinBox"));

        gridLayout->addWidget(wezsze_spinBox, 0, 1, 1, 1);

        szersze_spinBox = new QSpinBox(centralwidget);
        szersze_spinBox->setObjectName(QString::fromUtf8("szersze_spinBox"));

        gridLayout->addWidget(szersze_spinBox, 1, 1, 1, 1);

        skumulowane_spinBox = new QSpinBox(centralwidget);
        skumulowane_spinBox->setObjectName(QString::fromUtf8("skumulowane_spinBox"));

        gridLayout->addWidget(skumulowane_spinBox, 2, 1, 1, 1);

        definicjaBox = new QCheckBox(centralwidget);
        definicjaBox->setObjectName(QString::fromUtf8("definicjaBox"));
        definicjaBox->setChecked(true);

        gridLayout->addWidget(definicjaBox, 0, 3, 1, 1);

        skumulowaneBox = new QCheckBox(centralwidget);
        skumulowaneBox->setObjectName(QString::fromUtf8("skumulowaneBox"));
        skumulowaneBox->setChecked(true);

        gridLayout->addWidget(skumulowaneBox, 1, 3, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_10->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        synonimyTextBrowser = new QTextBrowser(centralwidget);
        synonimyTextBrowser->setObjectName(QString::fromUtf8("synonimyTextBrowser"));

        verticalLayout_5->addWidget(synonimyTextBrowser);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        definicjaTextBrowser = new QTextBrowser(centralwidget);
        definicjaTextBrowser->setObjectName(QString::fromUtf8("definicjaTextBrowser"));

        verticalLayout_3->addWidget(definicjaTextBrowser);


        verticalLayout_9->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        verticalLayout_9->addLayout(verticalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_6->addWidget(label_5);

        powiazaneTextBrowser = new QTextBrowser(centralwidget);
        powiazaneTextBrowser->setObjectName(QString::fromUtf8("powiazaneTextBrowser"));

        verticalLayout_6->addWidget(powiazaneTextBrowser);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_7->addWidget(label_6);

        syn_powTextBrowser = new QTextBrowser(centralwidget);
        syn_powTextBrowser->setObjectName(QString::fromUtf8("syn_powTextBrowser"));

        verticalLayout_7->addWidget(syn_powTextBrowser);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_10->addLayout(horizontalLayout_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_8->addWidget(label_7);

        skumulowaneTextBrowser = new QTextBrowser(centralwidget);
        skumulowaneTextBrowser->setObjectName(QString::fromUtf8("skumulowaneTextBrowser"));

        verticalLayout_8->addWidget(skumulowaneTextBrowser);


        verticalLayout_10->addLayout(verticalLayout_8);

        przegladarka->setCentralWidget(centralwidget);
        menubar = new QMenuBar(przegladarka);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 749, 23));
        Plik = new QMenu(menubar);
        Plik->setObjectName(QString::fromUtf8("Plik"));
        menuPomoc = new QMenu(menubar);
        menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
        przegladarka->setMenuBar(menubar);

        menubar->addAction(Plik->menuAction());
        menubar->addAction(menuPomoc->menuAction());
        Plik->addAction(actionWczytaj);
        Plik->addAction(actionZapisz);
        Plik->addAction(actionKoniec);
        menuPomoc->addAction(actionO_programie);
        menuPomoc->addAction(actionDokumentacja);

        retranslateUi(przegladarka);
        QObject::connect(actionKoniec, SIGNAL(activated()), przegladarka, SLOT(close()));
        QObject::connect(definicjaBox, SIGNAL(toggled(bool)), definicjaTextBrowser, SLOT(setVisible(bool)));
        QObject::connect(definicjaBox, SIGNAL(toggled(bool)), label_4, SLOT(setVisible(bool)));
        QObject::connect(skumulowaneBox, SIGNAL(toggled(bool)), skumulowaneTextBrowser, SLOT(setVisible(bool)));
        QObject::connect(skumulowaneBox, SIGNAL(toggled(bool)), label_7, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(przegladarka);
    } // setupUi

    void retranslateUi(QMainWindow *przegladarka)
    {
        przegladarka->setWindowTitle(QApplication::translate("przegladarka", "Tezaurus", 0, QApplication::UnicodeUTF8));
        actionWczytaj->setText(QApplication::translate("przegladarka", "Wczytaj", 0, QApplication::UnicodeUTF8));
        actionZapisz->setText(QApplication::translate("przegladarka", "Zapisz", 0, QApplication::UnicodeUTF8));
        actionKoniec->setText(QApplication::translate("przegladarka", "Koniec", 0, QApplication::UnicodeUTF8));
        actionO_programie->setText(QApplication::translate("przegladarka", "O programie", 0, QApplication::UnicodeUTF8));
        actionDokumentacja->setText(QApplication::translate("przegladarka", "Dokumentacja", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("przegladarka", "Znajdz s\305\202owo", 0, QApplication::UnicodeUTF8));
        pokazButton->setText(QApplication::translate("przegladarka", "Poka\305\274", 0, QApplication::UnicodeUTF8));
        edytujButton->setText(QApplication::translate("przegladarka", "Edytuj/Usu\305\204 poj\304\231cie", 0, QApplication::UnicodeUTF8));
        dodajButton->setText(QApplication::translate("przegladarka", "Dodaj poj\304\231cie", 0, QApplication::UnicodeUTF8));
        wezszeBox->setText(QApplication::translate("przegladarka", "poj\304\231cia w\304\231\305\274sze", 0, QApplication::UnicodeUTF8));
        szerszeBox->setText(QApplication::translate("przegladarka", "poj\304\231cia szersze", 0, QApplication::UnicodeUTF8));
        skojarzoneBox->setText(QApplication::translate("przegladarka", "poj\304\231cia skojarzone", 0, QApplication::UnicodeUTF8));
        definicjaBox->setText(QApplication::translate("przegladarka", "Definicja", 0, QApplication::UnicodeUTF8));
        skumulowaneBox->setText(QApplication::translate("przegladarka", "Skumulowane", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("przegladarka", "Polski (pl)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("przegladarka", "English (en)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("przegladarka", "INNY", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("przegladarka", "Synonimy", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("przegladarka", "Definicja", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("przegladarka", "Powi\304\205zane", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("przegladarka", "Synonimy powi\304\205zanych", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("przegladarka", "Skumulowane", 0, QApplication::UnicodeUTF8));
        Plik->setTitle(QApplication::translate("przegladarka", "Plik", 0, QApplication::UnicodeUTF8));
        menuPomoc->setTitle(QApplication::translate("przegladarka", "Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class przegladarka: public Ui_przegladarka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRZEGLADARKA_H
