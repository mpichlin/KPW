#ifndef EDYTOR_H
#define EDYTOR_H

/*! \file edytor.h
 *  \brief Zawiera definicję klasy edytor
 *
 * Plik zawiera definicję klasy edytor.
 *
 * \author Piotr Batog
 * \date 2010.12.11
 * \version 1.00.00
 */

#include <QDialog>
#include <QString>
#include <QList>
#include <QListWidgetItem>
#include "SkosConcept.hpp"
#include "SkosModel.hpp"
namespace Ui {
    class edytor;
}

/*! \class edytor
 * \brief Klasa odpowiedzialna za okno edytora konceptów.
 *
 * Klasa odpowiedzialna za okno edytora konceptów. Pozwla ona na edycję
 * pojedynczych konceptów.
 */
class edytor : public QDialog {
    Q_OBJECT
public:
  /*! \brief Sparametryzowany konstruktor
   *
   * Sparametryzowany konstruktor który tworzy okno edycji konceptu
   * \param parent - wskaźnik na widget wywołujący okno
   * \param Model - wskaźnik na model na którym pracuje tezurus
   * \param p_koncept - koncept, który będzie edytowany
   * \param ListaJezykow - lista dostępnych jezykow
   */
    edytor(QWidget *parent = 0, SkosModel* Model=0, SkosConcept p_koncept=SkosConcept(QUrl("empty")),QList<Soprano::LanguageTag>* ListaJezykow=0);

    /*! \brief Domyślny destruktor
     *
     * Domyślny destruktor
     */
    ~edytor();
private:
    Ui::edytor *ui;
    SkosModel *Model;
    SkosConcept m_koncept;
    Soprano::LanguageTag Jezyk;
    QList<Soprano::LanguageTag>* ListaJezykow;
    void przeladuj();
    void odswiez_wezsze();
    void odswiez_szersze();
    void odswiez_skojarzone();
    void zaladuj_comboBox();



public slots:
    /*! \brief Uruchamia dodawanie szerszych konceptów
     *
     * Uruchamia dodawanie szerszych konceptów
     */
    void dodaj_szersze();

    /*! \brief Uruchamia usuwanie szerszych konceptów
     *
     * Uruchamia usuwanie szerszych konceptów
     */
    void usun_szersze();

    /*! \brief Uruchamia dodawanie skojarzonych konceptów
     *
     * Uruchamia dodawanie skojarzonych konceptów
     */
    void dodaj_skojarzone();

    /*! \brief Uruchamia dodawanie węższych konceptów
     *
     * Uruchamia dodawanie węższych konceptów
     */
    void dodaj_wezsze();
    /*! \brief Uruchamia usuwanie skojarzonych konceptów
     *
     * Uruchamia usuwanie skojarzonych konceptów
     */
    void usun_skojarzone();

    /*! \brief Uruchamia usuwanie węższych konceptów
     *
     * Uruchamia usuwanie węższych konceptów
     */
    void usun_wezsze();

    /*! \brief Wyłącza okno edycji i zapisuje zmiany w koncepcie
     *
     * Wyłącza okno edycji i zapisuje zmiany w koncepcie
     */
    void zatwierdz();

    /*! \brief Dodaje alternatywną etykietę
     *
     * Dodaje alternatywną etykietę do edytowanego konceptu konceptu
     * \param zmieniona -wskaźnik na listę alternatywnych etykiet,
     * która została zmieniona poprzez dodanie nowej etykiety
     */
    void dodaj_atlernatywne(QListWidgetItem* zmieniona);
    
    /*! \brief Dodaje ukrytą etykietę
     *
     * Dodaje ukrytą etykietę do edytowanego konceptu konceptu
     * \param zmieniona -wskaźnik na listę ukrytych etykiet,
     * która została zmieniona poprzez dodanie nowej etykiety
     */
    void dodaj_ukryte(QListWidgetItem* zmieniona);

    /*! \brief Usuwa edytowany koncept z modelu
     *
     * Bezpowrotnie usuwa edytowany koncept z modelu
     */
    void usun();

    /*! \brief Zmienia język edytowanego pojęcia
     * 
     * Zmienia język edytowanego pojęcia
     * \param numer - numer języka z listy dostępnych języków
     */
    void zmien_jezyk(int numer);
};

#endif // EDYTOR_H
