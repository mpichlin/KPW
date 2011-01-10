#ifndef PRZEGLADARKA_H
#define PRZEGLADARKA_H

/*! \file przegladarka.h
 *  \brief Zawiera definicję klasy przegladarka
 *
 * Plik zawiera definicję klasy przegladarka.
 *
 * \author Piotr Batog
 * \date 2010.12.11
 * \version 1.00.00
 */

#include <QMainWindow>
#include "SkosParser.hpp"
#include "SkosSerializer.hpp"
#include "SkosModel.hpp"
#include "SkosConcept.hpp"
#include "edytor.h"
#include "ui_edytor.h"
#include <QList>
namespace Ui {
    class przegladarka;
}

/*! \class przegladarka
 * \brief Okno główne programu będące przeglądarką tezaurusów.
 *
 * Okno główne programu będące przeglądarką tezaurusów. Dzięki tej klasie
 * użytkownik może przejrzeć wszystkie koncepty, wczytywać i zapisywać pliki
 * oraz przejść do edycji poszczególnych słów
 */
class przegladarka : public QMainWindow {
    Q_OBJECT
public:

  /*! \brief Sparametryzowany konstruktor
   *
   * Sparametryzowany konstruktor tworzący przglądarkę ze wskaźnikiem na model
   * na którym będą wykonywane operacje związane z tezaurusem
   * \param p_model - wskaźnik na model na którym będzie działała przeglądarka
   * \param parent - wskaźnik na rodzica widgetu
   */
    przegladarka(SkosModel *p_model, QWidget *parent = 0);

    /*! \brief Domyślny destruktor
     *
     * Domyślny destruktor
     */
    ~przegladarka();
private:
    Ui::przegladarka *ui;
    SkosModel* Model;
    Soprano::LanguageTag Jezyk;
    bool WszystkieJezyki;
    void zapelnij_liste();
    bool znajdz(QString, SkosConcept&);
    void wyswietl(SkosConcept);
    SkosConcept stworz_koncept(edytor edyt);
    QList<Soprano::LanguageTag> ListaJezykow;
    void znajdz_szersze(QList<SkosConcept*>* lista,SkosConcept* pojecie, int glebokosc);
    void znajdz_wezsze(QList<SkosConcept*>* lista,SkosConcept* pojecie, int glebokosc);
    void znajdz_skojarzone(QList<SkosConcept*>* lista,SkosConcept* pojecie, int glebokosc);
    void inicjalizuj_jezyki();
    void zaladuj_comboBox();
public slots:

    /*! \brief Wywołuje okno edycji
     *
     * Wywołuje okno edycji
     */
    void edytuj();

    /*! \brief Wywołuje okno dodawania nowych konceptów
     *
     * Wywołuje okno dodawania nowych konceptów
     */
    void dodaj();

    /*! \brief Pokazuje zawartość wybranego konceptu
     *
     * Pokazuje zawartość wybranego w oknie przeglądarki konceptu
     */
    void pokaz();

    /*! \brief Wywołuje okno dialogowe zapisania
     *
     * Wywołuje okno dialogowe zapisania aktualnie przeglądanego tezaurusa,
     * gdzie można wybrać nazwę pod jaką chce się zapisać aktualną pracę.
     */
    void zapisz();

    /*! \brief Wczytuje tezaurus
     *
     * Wywołuje okno wczytania tezaursa w którym można wybrać plik,
     * który ma zostać wczytany.
     */
    void wczytaj();

    /*! \brief Odświeża okno przeglądarki
     *
     * Odświeża okno przeglądarki by uwzględnić zmiany jakie zaszły w modelu
     * i sposobie jego wyświetlania
     */
    void odswiez();

    /*! \brief Przpisuje zawartosc pozycji kliknietej na liscie
     *
     * Przpisuje zawartosc pozycji kliknietej na liscie
     */
    void wstaw_z_listy();

    /*! \brief Zmienia filtr języka konceptów
     *
     * Zmienia filtr języka konceptów, który określa w jakim
     * języku mają być wyświetlane dane z tezaurusa
     * \param numer - numer języka z listy języków do wyboru
     */
    void zmien_jezyk(int numer);

    /*! \brief Zmienia flagę wyświetlania pojęć szerszych
     *
     * Zmienia flagę wyświetlania pojęć szerszych
     * \param wlacz - określa czy pojęcia szersze mają być wyświetlone
     */
    void czy_szersze(bool);

    /*! \brief Zmienia flagę wyświetlania pojęć węższych
     *
     * Zmienia flagę wyświetlania pojęć węższych
     * \param wlacz - określa czy pojęcia węższe mają być wyświetlone
     */
    void czy_wezsze(bool wlacz);

    /*! \brief Zmienia flagę wyświetlania pojęć skojarzonych
     *
     * Zmienia flagę wyświetlania pojęć skojarzonych
     * \param wlacz - określa czy pojęcia skojarzone mają być wyświetlone
     */
    void czy_skojarzone(bool);

    /*! \brief Zmienia głębokość wyświetlania szerszych pojęć
     *
     * Zmienia głębokość wyświetlania szerszych pojęć
     * \param liczba - liczba okrślająca głębokość wyświetlanych pojęć szerszych
     */
    void szerszeSpinBoxChanged(int liczba);

    /*! \brief Zmienia głębokość wyświetlania węższych pojęć
     *
     * Zmienia głębokość wyświetlania pojęć węższych
     * \param liczba - liczba okrślająca głębokość węższych pojęć
     */
    void wezszeSpinBoxChanged(int);

    /*! \brief Zmienia głębokość wyświetlania skojarzonych pojęć
     *
     * Zmienia głębokość wyświetlania pojęć skojarzonych
     * \param liczba - liczba okrślająca głębokość wyświetlanych skojarzonych
     * pojęć
     */
    void skojarzoneSpinBoxChanged(int);
};
#endif // PRZEGLADARKA_H
