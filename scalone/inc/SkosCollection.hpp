#ifndef SKOS_COLLECTION_HPP
#define SKOS_COLLECTION_HPP

/*! \file SkosCollection.hpp
 *  \brief Zawiera definicję klasy SkosCollection
 *
 * Plik zawiera definicję klasy SkosCollection
 *
 * \author Michał Pichliński
 * \date 2010.12.19
 * \version 1.00.00
 */

#include "SkosClass.hpp"
#include "SkosConcept.hpp"

/*! \class SkosCollection
 * \brief Klasa modelująca klasę SKOSową Collection
 *
 * Klasa modelująca klasę SKOSową Collection.
 * UWAGA: Klasa jest zaimplementowana, jednak brakuje implementacji
 * w \link SkosModel modelu\endlink do obsługi obiektów tej klasy.
 */
class SkosCollection : public SkosClass
{
public:
  /*! \brief Konstruktor tworzący obiekt z danym URL
   *
   * Konstruktor tworzący obiekt o danym URL
   * \param p_url - URL który ma posiadać skonstruowany obiekt
   * \post Stworzony obiekt zawiera URL określony w p_url
   */
  SkosCollection(QUrl p_url){setUrl(p_url);};

  /*! \brief Dodaje koncept do kolekcji
   *
   * Dodaje koncept do kolekcji
   * \param p_concept - dodawany koncept
   * \pre p_concept musi istnieć
   * \post Obiekt kolekcji zawiera w sobie koncept p_concept
   */
  void addConcept(const SkosConcept &p_concept);

  /*! \brief Usuwa koncept z kolekcji
   *
   * Usuwa z obiektu dany koncept
   * \param p_concept - koncept który ma zostać usunięty z kolekcji
   * \post Obiekt nie zawiera konceptu p_concept
   */
  void removeConcept(const SkosConcept &p_concept);

  /*! \brief Dodaje kolekcję do obiektu
   *
   * Dodaje daną kolekcję do obiektu (kolekcje mogą zawierać inne kolekcje).
   * \param p_collection - dodawana kolekcja
   * \pre p_collection musi istnieć
   * \post Obiekt zawiera wskaźnik na kolekcję p_collection
   */
  void addCollection(const SkosCollection &p_collection);

  /*! \brief Usuwa kolekcję z obiektu
   *
   * Usuwa daną kolekcję z obiektu
   * \param p_collection
   * \post Obiekt nie zawiera w sobie kolekcji p_collection
   */
  void removeCollection(const SkosCollection &p_collection);

  /*! \brief Zwraca listę wszystkich konceptów zawartych w kolekcji
   *
   * Zwraca listę URL wszystkich konceptów zawartych w kolekcji
   * \return Lista URL konceptów znajdujących się w obiekcie
   */
  QList<QUrl> getConcepts();

  /*! \brief Zwraca listę wszystkich kolekcji zawartych w kolekcji
   *
   * Zwraca listę wszystkich kolekcji zawartych w kolekcji
   * \return Lista URL kolekcji znajdujących się w obiekcie
   */
  QList<QUrl> getCollections();
private:
  bool hasConcept(const SkosConcept &p_concept);
  bool hasCollection(const SkosCollection &p_collection);

  QList<QUrl>    m_memberConcepts;
  QList<QUrl> m_memberCollections;
};

#endif
