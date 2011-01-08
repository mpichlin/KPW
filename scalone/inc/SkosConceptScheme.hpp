#ifndef SKOS_CONCEPT_SCHEME_HPP
#define SKOS_CONCEPT_SCHEME_HPP

/*! \file SkosConceptScheme.hpp
 *  \brief Zawiera definicję klasy SkosConceptScheme
 *
 * Plik zawiera definicję klasy SkosConceptScheme.
 *
 * \author Michał Pichliński
 * \date 2010.12.01
 * \version 1.00.00
 */

#include "ESchemeRelation.hpp"
#include "SkosClass.hpp"
#include "SkosConcept.hpp"

class SkosConcept;

/*! \class SkosConceptScheme
 *  \brief Klasa modelująca schemat konceptów języka SKOS
 *
 * Klasa modeluje klasę ConceptScheme języka SKOS
 */
class SkosConceptScheme : public SkosClass
{
public:
  /*! \brief Konstruktor domyślny
   *
   * Konstruktor domyślny.
   * UWAGA!
   * Nie należy stosować tego konstruktora, został on stworzony tylko po
   * to, żeby móc korzystać z QStack w 
   * \link SkosModel SkosModel::clearEmptyClasses\endlink.
   */
  SkosConceptScheme(){};

  /*! \brief Konstruktor tworzący schemat konceptów o danym URL
   *
   * Konstruktor tworzący schemat konceptów o danym URL
   */
  SkosConceptScheme(QUrl p_url){setUrl(p_url);};

  /*! \brief Dodaje koncept do schematu w danej relacji
   *
   * Dodaje dany koncept do schematu w danej relacji
   * \param p_concept - koncept który ma zostać dodany do schematu
   * \param p_schemeRelation - typ relacji w której ma znajdować się koncept
   * względem schematu
   * \post Obiekt zawiera URL konceptu p_concept, na liście wybranej
   * przez p_schemeRelation
   */
  void addConcept(const SkosConcept &p_concept,
                  const ESchemeRelation &p_schemeRelation);

  /*! \brief Sprawdza czy dany koncept znajduje się w schemacie w danej relacji
   *
   * Sprawdza czy dany koncept znajduje się w schemacie w danej relacji
   * \param p_concept - koncept który ma zostać znaleziony
   * \param p_schemeRelation - typ relacji szukanego konceptu względem obiektu
   * \return True, jeśli koncept p_concept znajduje się w sechamcie w relacji,
   * p_schemeRelation, w przeciwnym razie zwracana jest wartość false
   */
  bool hasConcept(const SkosConcept& p_concept,
                  const ESchemeRelation &p_schemeRelation);

  /*! \brief Usuwa ze schematu dany koncept
   *
   * Usuwa ze schematu dany koncept o danej relacji
   * \param p_conceptToRemove - koncept, który ma zostać usunięty z obiektu
   * \param p_schemeRelation - typ relacji względem schematu w jakim znajduje
   * się usuwany koncept
   * \post Obiekt nie zawiera w relacji p_schemeRelation konceptu 
   * p_conceptToRemove
   */
  void removeConcept(const SkosConcept &p_conceptToRemove,
                     const ESchemeRelation &p_schemeRelation);

  /*! \brief Zwraca listę URL konceptów znajdujących się w  schemacie
   *
   * Zwraca listę URL konceptów znajdujących się w schemacie w 
   * danego typu relacji.
   * \param p_schemeRelation - typ relacji do którego ma należeć lista konceptów
   * \return Listę URL konceptów będących w relacji p_schemeRelation z obiektem
   */
  const QList<QUrl> &getConcepts(
    const ESchemeRelation &p_schemeRelation) const;
private:
  bool isConsistencyOk(const SkosConcept &p_concept);
  bool hasConcept(const SkosConcept& p_inconcept,
                  QList<QUrl> &p_internalConcepts);
  void removeConcept(const SkosConcept &p_conceptToRemove,
                     QList<QUrl> &p_internalConcepts);
  QList<QUrl> m_topConcepts;
  QList<QUrl> m_inSchemeConcepts;
};

#endif
