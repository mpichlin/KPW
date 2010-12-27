/********************************************************************************
** Form generated from reading UI file 'dodaj.ui'
**
** Created: Sat Dec 11 19:39:08 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJ_H
#define UI_DODAJ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dodaj
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dodaj)
    {
        if (dodaj->objectName().isEmpty())
            dodaj->setObjectName(QString::fromUtf8("dodaj"));
        dodaj->resize(400, 300);
        horizontalLayout = new QHBoxLayout(dodaj);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(dodaj);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        listWidget = new QListWidget(dodaj);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(dodaj);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(dodaj);
        QObject::connect(buttonBox, SIGNAL(accepted()), dodaj, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dodaj, SLOT(reject()));

        QMetaObject::connectSlotsByName(dodaj);
    } // setupUi

    void retranslateUi(QDialog *dodaj)
    {
        dodaj->setWindowTitle(QApplication::translate("dodaj", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dodaj: public Ui_dodaj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJ_H
