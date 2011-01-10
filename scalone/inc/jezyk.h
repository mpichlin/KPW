#ifndef JEZYK_H
#define JEZYK_H

#include <QDialog>

/*! \file jezyk.h
 *  \brief Zawiera definicję klasy jezyk
 *
 * Plik zawiera definicję klasy jezyk.
 *
 * \author Piotr Batog
 * \date 2011.01.06
 * \version 1.00.00
 */


namespace Ui {
    class jezyk;
}

/*! \class jezyk
 * \brief Klasa odpowiedzialna za ustawienia języka
 *
 * Klasa odpowiedzialna za ustawienia języka
 */
class jezyk : public QDialog {
    Q_OBJECT

public:
  /*! \brief Sparametryzowany konstruktor
   *
   * Sparametryzowany konstruktor
   * \param parent - wskaźnik na widget, który utworzył obiekt tej klasy
   */
    jezyk(QWidget *parent = 0);

    /*! \brief Domyślny destruktor
     *
     * Domyślny destruktor
     */
    ~jezyk();

    /*! \brief Skrót języka
     *
     * Skrót określający wybrany język
     */
    QString skrot;

private:
    Ui::jezyk *ui;

public slots:
    
    /*! \brief Wyłącza okno
     *
     * Wyłącza okno z jednoczesnym zapisaniem skrótu języka
     */
    void zakoncz();
};

#endif // JEZYK_H
