/********************************************************************************
** Form generated from reading UI file 'dodaj.ui'
**
** Created: Thu Jan 6 01:02:56 2011
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dodaj
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *znajdzLineEdit;
    QListWidget *pojeciaListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *anulujButton_2;

    void setupUi(QDialog *dodaj)
    {
        if (dodaj->objectName().isEmpty())
            dodaj->setObjectName(QString::fromUtf8("dodaj"));
        dodaj->resize(400, 300);
        verticalLayout = new QVBoxLayout(dodaj);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        znajdzLineEdit = new QLineEdit(dodaj);
        znajdzLineEdit->setObjectName(QString::fromUtf8("znajdzLineEdit"));

        verticalLayout->addWidget(znajdzLineEdit);

        pojeciaListWidget = new QListWidget(dodaj);
        pojeciaListWidget->setObjectName(QString::fromUtf8("pojeciaListWidget"));

        verticalLayout->addWidget(pojeciaListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(dodaj);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        anulujButton_2 = new QPushButton(dodaj);
        anulujButton_2->setObjectName(QString::fromUtf8("anulujButton_2"));

        horizontalLayout->addWidget(anulujButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dodaj);
        QObject::connect(anulujButton_2, SIGNAL(clicked()), dodaj, SLOT(reject()));

        QMetaObject::connectSlotsByName(dodaj);
    } // setupUi

    void retranslateUi(QDialog *dodaj)
    {
        dodaj->setWindowTitle(QApplication::translate("dodaj", "Dialog", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("dodaj", "OK", 0, QApplication::UnicodeUTF8));
        anulujButton_2->setText(QApplication::translate("dodaj", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dodaj: public Ui_dodaj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJ_H
