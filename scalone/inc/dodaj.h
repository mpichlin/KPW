#ifndef DODAJ_H
#define DODAJ_H

/*! \file dodaj.h
 *  \brief Zawiera definicję klasy dodaj
 *
 * Plik zawiera definicję klasy dodaj.
 *
 * \author Piotr Batog
 * \date 2010.12.11
 * \version 1.00.00
 */

#include <QDialog>
#include "SkosModel.hpp"
#include "SkosConcept.hpp"

namespace Ui {
    class dodaj;
}

/*! \class dodaj
 * \brief Klasa odpowiedzialna za okno dodawania relacji do konceptuw
 *
 * Klasa odpowiedzialna za dodawanie relacji do konceptu. Dzięki niemu
 * w modelu dany koncept można uzupełnić o dodatkowe relacje
 */
class dodaj : public QDialog {
    Q_OBJECT
public:
  /*! \brief Sparametryzowany konstruktor
   *
   * Sparametryzowany konstruktor tworzący okno dodawania relacji
   * \param parent - wskaźnik na widget wywołujący okno
   * \param model - wskaźnik na model na którym pracuje tezurus
   * \param p_bazowyKoncept - koncept, do którego zostanie dodana relacja
   * \param typ - rodzaj dodawanej relacji
   */
    dodaj(QWidget *parent = 0,SkosModel *model=0, SkosConcept p_bazowyKoncept = SkosConcept(QUrl("empty")), ERelationType typ=RelatedRelation);
    
    /*! \brief Domyślny destruktor
     *
     * Domyślny destruktor
     */
    ~dodaj();

private:
    Ui::dodaj *ui;
    SkosConcept m_bazowyKoncept;
    SkosModel *Model;

    ERelationType TypRelacji;
public slots:
    /*! \brief Odświeża koncepty które można dodać do relacji
     *
     * Odświeża koncepty które można dodać do relacji
     */
    void odswiez();

    /*! \brief Zamyka okno dodawania relacji i dodaje relację.
     *
     * Zamyka okno dodawania relacji i dodaje relację z wybranym
     * w momencie zamykania okna konceptem.
     * \post Koncept zostaje uzupełniony o nową relację jeśli został
     * wybrany jeden z konceptów
     */
    void zakoncz();
};

#endif // DODAJ_H
