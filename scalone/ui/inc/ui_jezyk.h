/********************************************************************************
** Form generated from reading UI file 'jezyk.ui'
**
** Created: Thu Jan 6 01:02:56 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JEZYK_H
#define UI_JEZYK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_jezyk
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *anulujButton;

    void setupUi(QDialog *jezyk)
    {
        if (jezyk->objectName().isEmpty())
            jezyk->setObjectName(QString::fromUtf8("jezyk"));
        jezyk->resize(213, 103);
        verticalLayout = new QVBoxLayout(jezyk);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(jezyk);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(jezyk);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(jezyk);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        anulujButton = new QPushButton(jezyk);
        anulujButton->setObjectName(QString::fromUtf8("anulujButton"));

        horizontalLayout->addWidget(anulujButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(jezyk);
        QObject::connect(anulujButton, SIGNAL(clicked()), jezyk, SLOT(reject()));

        QMetaObject::connectSlotsByName(jezyk);
    } // setupUi

    void retranslateUi(QDialog *jezyk)
    {
        jezyk->setWindowTitle(QApplication::translate("jezyk", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("jezyk", "Wprowadz nowy skrot jezyka:", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("jezyk", "OK", 0, QApplication::UnicodeUTF8));
        anulujButton->setText(QApplication::translate("jezyk", "Anuluj", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class jezyk: public Ui_jezyk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JEZYK_H
