/********************************************************************************
** Form generated from reading UI file 'edytor.ui'
**
** Created: Sat Jan 8 16:55:20 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDYTOR_H
#define UI_EDYTOR_H

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
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edytor
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *preferowanyQline;
    QComboBox *comboBox;
    QVBoxLayout *Layout;
    QHBoxLayout *pojecieLayout;
    QVBoxLayout *terminyLayout;
    QGridLayout *gridLayout;
    QListWidget *ukryteQlista;
    QListWidget *alternatywneQlista;
    QLabel *label_3;
    QLabel *label_2;
    QVBoxLayout *pojeciaLayout;
    QLabel *label_7;
    QTextEdit *definicjaText;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *domyslneUrlBox;
    QLineEdit *UrlLineEdit;
    QHBoxLayout *relacjeLayout;
    QVBoxLayout *szerszeLayout;
    QLabel *label_4;
    QListWidget *szerszeQlista;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *dodaj_szerszeButton;
    QPushButton *usun_szerszeButton;
    QVBoxLayout *wezszeLayout;
    QLabel *label_5;
    QListWidget *wezszeQlista;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *dodaj_wezszeButton;
    QPushButton *usun_wezszeButton;
    QVBoxLayout *skojarzoneLayout;
    QLabel *label_6;
    QListWidget *skojarzoneQlista;
    QHBoxLayout *horizontalLayout;
    QPushButton *dodaj_skojarzoneButton;
    QPushButton *usun_skojarzoneButton;
    QPushButton *usunButton;
    QPushButton *zatwierdzButton;

    void setupUi(QWidget *edytor)
    {
        if (edytor->objectName().isEmpty())
            edytor->setObjectName(QString::fromUtf8("edytor"));
        edytor->resize(828, 584);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edytor->sizePolicy().hasHeightForWidth());
        edytor->setSizePolicy(sizePolicy);
        edytor->setMinimumSize(QSize(600, 400));
        verticalLayout_3 = new QVBoxLayout(edytor);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(edytor);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        preferowanyQline = new QLineEdit(edytor);
        preferowanyQline->setObjectName(QString::fromUtf8("preferowanyQline"));

        horizontalLayout_2->addWidget(preferowanyQline);

        comboBox = new QComboBox(edytor);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        Layout = new QVBoxLayout();
        Layout->setSpacing(6);
        Layout->setObjectName(QString::fromUtf8("Layout"));
        pojecieLayout = new QHBoxLayout();
        pojecieLayout->setSpacing(6);
        pojecieLayout->setObjectName(QString::fromUtf8("pojecieLayout"));
        terminyLayout = new QVBoxLayout();
        terminyLayout->setSpacing(6);
        terminyLayout->setObjectName(QString::fromUtf8("terminyLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ukryteQlista = new QListWidget(edytor);
        ukryteQlista->setObjectName(QString::fromUtf8("ukryteQlista"));
        ukryteQlista->setEnabled(true);
        ukryteQlista->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        ukryteQlista->setViewMode(QListView::ListMode);
        ukryteQlista->setSelectionRectVisible(false);
        ukryteQlista->setSortingEnabled(false);

        gridLayout->addWidget(ukryteQlista, 1, 1, 1, 1);

        alternatywneQlista = new QListWidget(edytor);
        alternatywneQlista->setObjectName(QString::fromUtf8("alternatywneQlista"));
        alternatywneQlista->setEnabled(true);
        alternatywneQlista->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        alternatywneQlista->setViewMode(QListView::ListMode);
        alternatywneQlista->setSelectionRectVisible(false);
        alternatywneQlista->setSortingEnabled(false);

        gridLayout->addWidget(alternatywneQlista, 1, 0, 1, 1);

        label_3 = new QLabel(edytor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_2 = new QLabel(edytor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        terminyLayout->addLayout(gridLayout);


        pojecieLayout->addLayout(terminyLayout);

        pojeciaLayout = new QVBoxLayout();
        pojeciaLayout->setSpacing(6);
        pojeciaLayout->setObjectName(QString::fromUtf8("pojeciaLayout"));
        label_7 = new QLabel(edytor);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        pojeciaLayout->addWidget(label_7);

        definicjaText = new QTextEdit(edytor);
        definicjaText->setObjectName(QString::fromUtf8("definicjaText"));

        pojeciaLayout->addWidget(definicjaText);


        pojecieLayout->addLayout(pojeciaLayout);

        pojecieLayout->setStretch(0, 1);
        pojecieLayout->setStretch(1, 1);

        Layout->addLayout(pojecieLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        domyslneUrlBox = new QCheckBox(edytor);
        domyslneUrlBox->setObjectName(QString::fromUtf8("domyslneUrlBox"));
        domyslneUrlBox->setAutoFillBackground(false);
        domyslneUrlBox->setChecked(true);

        horizontalLayout_5->addWidget(domyslneUrlBox);

        UrlLineEdit = new QLineEdit(edytor);
        UrlLineEdit->setObjectName(QString::fromUtf8("UrlLineEdit"));
        UrlLineEdit->setEnabled(true);

        horizontalLayout_5->addWidget(UrlLineEdit);


        Layout->addLayout(horizontalLayout_5);

        relacjeLayout = new QHBoxLayout();
        relacjeLayout->setSpacing(6);
        relacjeLayout->setObjectName(QString::fromUtf8("relacjeLayout"));
        szerszeLayout = new QVBoxLayout();
        szerszeLayout->setSpacing(6);
        szerszeLayout->setObjectName(QString::fromUtf8("szerszeLayout"));
        label_4 = new QLabel(edytor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        szerszeLayout->addWidget(label_4);

        szerszeQlista = new QListWidget(edytor);
        szerszeQlista->setObjectName(QString::fromUtf8("szerszeQlista"));
        szerszeQlista->setMinimumSize(QSize(0, 20));
        szerszeQlista->setMaximumSize(QSize(16777215, 16777215));

        szerszeLayout->addWidget(szerszeQlista);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        dodaj_szerszeButton = new QPushButton(edytor);
        dodaj_szerszeButton->setObjectName(QString::fromUtf8("dodaj_szerszeButton"));

        horizontalLayout_6->addWidget(dodaj_szerszeButton);

        usun_szerszeButton = new QPushButton(edytor);
        usun_szerszeButton->setObjectName(QString::fromUtf8("usun_szerszeButton"));

        horizontalLayout_6->addWidget(usun_szerszeButton);


        szerszeLayout->addLayout(horizontalLayout_6);


        relacjeLayout->addLayout(szerszeLayout);

        wezszeLayout = new QVBoxLayout();
        wezszeLayout->setSpacing(6);
        wezszeLayout->setObjectName(QString::fromUtf8("wezszeLayout"));
        label_5 = new QLabel(edytor);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        wezszeLayout->addWidget(label_5);

        wezszeQlista = new QListWidget(edytor);
        wezszeQlista->setObjectName(QString::fromUtf8("wezszeQlista"));
        wezszeQlista->setSortingEnabled(true);

        wezszeLayout->addWidget(wezszeQlista);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dodaj_wezszeButton = new QPushButton(edytor);
        dodaj_wezszeButton->setObjectName(QString::fromUtf8("dodaj_wezszeButton"));

        horizontalLayout_3->addWidget(dodaj_wezszeButton);

        usun_wezszeButton = new QPushButton(edytor);
        usun_wezszeButton->setObjectName(QString::fromUtf8("usun_wezszeButton"));

        horizontalLayout_3->addWidget(usun_wezszeButton);


        wezszeLayout->addLayout(horizontalLayout_3);


        relacjeLayout->addLayout(wezszeLayout);

        skojarzoneLayout = new QVBoxLayout();
        skojarzoneLayout->setSpacing(6);
        skojarzoneLayout->setObjectName(QString::fromUtf8("skojarzoneLayout"));
        label_6 = new QLabel(edytor);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        skojarzoneLayout->addWidget(label_6);

        skojarzoneQlista = new QListWidget(edytor);
        skojarzoneQlista->setObjectName(QString::fromUtf8("skojarzoneQlista"));
        skojarzoneQlista->setSortingEnabled(true);

        skojarzoneLayout->addWidget(skojarzoneQlista);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dodaj_skojarzoneButton = new QPushButton(edytor);
        dodaj_skojarzoneButton->setObjectName(QString::fromUtf8("dodaj_skojarzoneButton"));

        horizontalLayout->addWidget(dodaj_skojarzoneButton);

        usun_skojarzoneButton = new QPushButton(edytor);
        usun_skojarzoneButton->setObjectName(QString::fromUtf8("usun_skojarzoneButton"));

        horizontalLayout->addWidget(usun_skojarzoneButton);


        skojarzoneLayout->addLayout(horizontalLayout);


        relacjeLayout->addLayout(skojarzoneLayout);


        Layout->addLayout(relacjeLayout);


        verticalLayout_3->addLayout(Layout);

        usunButton = new QPushButton(edytor);
        usunButton->setObjectName(QString::fromUtf8("usunButton"));

        verticalLayout_3->addWidget(usunButton);

        zatwierdzButton = new QPushButton(edytor);
        zatwierdzButton->setObjectName(QString::fromUtf8("zatwierdzButton"));

        verticalLayout_3->addWidget(zatwierdzButton);


        retranslateUi(edytor);
        QObject::connect(domyslneUrlBox, SIGNAL(clicked(bool)), UrlLineEdit, SLOT(setHidden(bool)));

        ukryteQlista->setCurrentRow(-1);
        alternatywneQlista->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(edytor);
    } // setupUi

    void retranslateUi(QWidget *edytor)
    {
        edytor->setWindowTitle(QApplication::translate("edytor", "Edytor poj\304\231\304\207", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("edytor", "termin preferowany:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("edytor", "Polski (pl)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("edytor", "English (en)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("edytor", "INNY", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("edytor", "Okresla j\304\231zyk w kt\303\263rym dokonywane b\304\231d\304\205 zmiany.  ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("edytor", "terminy ukryte:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("edytor", "terminy alternatywne:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("edytor", "definicja poj\304\231cia:", 0, QApplication::UnicodeUTF8));
        domyslneUrlBox->setText(QApplication::translate("edytor", "domy\305\233lne Url", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("edytor", "Poj\304\231cie szersze", 0, QApplication::UnicodeUTF8));
        dodaj_szerszeButton->setText(QApplication::translate("edytor", "dodaj", 0, QApplication::UnicodeUTF8));
        usun_szerszeButton->setText(QApplication::translate("edytor", "usu\305\204", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("edytor", "Poj\304\231cia w\304\231\305\274sze", 0, QApplication::UnicodeUTF8));
        dodaj_wezszeButton->setText(QApplication::translate("edytor", "dodaj", 0, QApplication::UnicodeUTF8));
        usun_wezszeButton->setText(QApplication::translate("edytor", "usu\305\204", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("edytor", "Poj\304\231cia skojarzone", 0, QApplication::UnicodeUTF8));
        dodaj_skojarzoneButton->setText(QApplication::translate("edytor", "dodaj", 0, QApplication::UnicodeUTF8));
        usun_skojarzoneButton->setText(QApplication::translate("edytor", "usu\305\204", 0, QApplication::UnicodeUTF8));
        usunButton->setText(QApplication::translate("edytor", "USU\305\203", 0, QApplication::UnicodeUTF8));
        zatwierdzButton->setText(QApplication::translate("edytor", "ZATWIERD\305\271", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class edytor: public Ui_edytor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDYTOR_H
