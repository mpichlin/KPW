#ifndef SKOS_CONCEPT_HPP
#define SKOS_CONCEPT_HPP

/*! \file SkosConcept.hpp
 *  \brief Zawiera definicję klasy SkosConcept
 *
 * Plik zawiera definicję klasy SkosConcept.
 */

#include "ESchemeRelation.hpp"

#include "SkosClass.hpp"
#include "SkosConceptScheme.hpp"
#include "ERelationType.hpp"

class SkosConceptScheme;

/*! \brief Klasa modelująca SKOSową klasę Concept
 *
 * Klasa modelująca SKOSową klasę Concept
 */
class SkosConcept : public SkosClass
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
  SkosConcept(){};

  /*! \brief Konstruktor tworzący koncept o danym URL
   *
   * Konstruktor tworzący koncept o danym URL
   */
  SkosConcept(QUrl p_url){setUrl(p_url);};

  /*! \brief Dodanie do relacji danego typu z danym konceptem
   *
   * Dodanie relacji danego typu z danym konceptem
   * \param p_relatedConcept - koncept, do którego będzie stworzona relacja
   * \param p_relationType - typ relacji jaka ma zostać utworzona
   * \pre p_relatedConcept musi istnieć
   * \post Do obiektu została dodana relacja typu p_relationType z konceptem
   * p_relatedConcept
   */
  int  addConceptRelation(SkosConcept *p_relatedConcept,
                          const ERelationType &p_relationType);

  /*! \brief Dodanie relacji do schematu konceptów
   *
   * Dodanie relacji danego typu do danego chematu konceptów
   * \param p_conceptScheme - schemat konceptów w którym obiekt ma mieć
   * relację
   * \param p_schemeRelation - typ relacji jaki ma zostać stworzony z danym
   * schematem
   * \pre p_conceptScheme musi istnieć
   * \post Do obiektu została dodana relacja typu p_schemeRelation w stosunku
   * do schematu konceptów określonego przez p_conceptScheme
   */
  void addToScheme(SkosConceptScheme *p_conceptScheme,
                   const ESchemeRelation &p_schemeRelation);

  /*! \brief Znajduje dany schemat w którym koncept jest w danego typu relacji
   *
   * Znajduje dany schemat w którym koncept jest w danego typu relacji
   * \param p_conceptScheme - schemat konceptów, który ma zostać znaleziony
   * \param p_schemeRelation - typ relacji obiektu wobec schematu
   * \return Iterator na schemat określony przez p_conceptScheme, w którym
   * koncept jest w relacji typu p_schemeRelation.
   */
  QList<SkosConceptScheme*>::iterator findInScheme(
    const SkosConceptScheme &p_conceptScheme,
    const ESchemeRelation &p_schemeRelation);

  /*! \brief Znajduje dany koncept w którym obiekt jest w danego typu relacji
   *
   * Znajduje dany koncept w którym obiekt jest w danego typu relacji
   * \param p_concept - koncept, który ma zostać znaleziony
   * \param p_relationType - typ relacji konceptu wobec obiektu
   * \return Iterator na koncept określony przez p_conceptScheme, który jest
   * w relacji typu p_relationType z obiektem
   */
  QList<SkosConcept*>::iterator findConceptInRelation(
    const SkosConcept &p_concept, 
    const ERelationType &p_relationType);

  /*! \brief Usuwa relację danego typu obiektu z danym konceptem
   *
   * Usuwa dany koncept z danego typu relacji z obiektem
   * \param p_conceptToRemove - koncept, z którym relacja ma zostać usunięta
   * \param p_relationType - typ usuwanej relacji
   * \post Obiekt nie posiada relacji typu p_relationType z konceptem
   * p_conceptToRemove
   */
  void removeConceptFromRelation(const SkosConcept &p_conceptToRemove,
                                 const ERelationType &p_relationType);

  /*! \brief Usuwa relację danego typu obiektu z danego schematu konceptów
   *
   * Usuwa relację danego typu obiektu z danego schematu konceptów
   * \param p_conceptScheme - schemat z którym ma zostać usunięta relacja
   * \param p_schemeRelation - typ relacji schematu p_conceptScheme z obiektem
   * \post Obiekt nie posiada relacji typu p_schemeRelation ze schematem 
   * konceptów p_conceptScheme
   */
  void removeConceptFromScheme(const SkosConceptScheme &p_conceptScheme,
                               const ESchemeRelation &p_schemeRelation);

  /*! \brief Zwraca stała referencję na listę wskaźników powiązanych konceptów
   *
   * Zwraca stałą referencję na listę wskaźników powiązanych konceptów
   * z obiektem, danym typem relacji
   * \param p_relationType - typ relacji konceptów, których ma zawierać
   * referencja
   * \return Stała referencja na listę konceptów będących z obiektem w relacji
   * typu p_relationType
   */
  const QList<SkosConcept*> &getRelatedConceptsList(
    const ERelationType &p_relationType) const;

  /*! \brief Zwraca stała referencję na listę wskaźników powiązanych schematów
   * konceptów
   *
   * Zwraca stałą referencję na listę wskaźników powiązanych schematów konceptów
   * z obiektem, danym typem relacji
   * \param p_schemeRelation - typ relacji schematów konceptół, któtre ma
   * zawierać referencja
   * \return Stała referencja na listę schematów konceptów będących z obiektem
   * w relacji typu p_schemeRelation
   */
  const QList<SkosConceptScheme*> &getConceptSchemesList(
    const ESchemeRelation &p_schemeRelation) const;
private:
  QList<SkosConceptScheme*>::iterator findInScheme(
    const SkosConceptScheme &p_conceptScheme,
    QList<SkosConceptScheme*> &p_internalSchemes);
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;
  bool isRelationAlreadyExists(const SkosConcept &p_concept);
  QList<SkosConcept*>::iterator findConceptInList(
    const SkosConcept &p_concept, 
    QList<SkosConcept*> &p_relationList);
  void removeConceptFromList(const SkosConcept &p_concept, 
                             QList<SkosConcept*> &p_relationList);
  void removeSchemeFromList(const SkosConceptScheme &p_conceptScheme, 
                            QList<SkosConceptScheme*> &p_schemeList);

  QList<SkosConcept*> m_broaderConcepts;
  QList<SkosConcept*> m_narrowerConcepts;
  QList<SkosConcept*> m_relatedConcepts;

  QList<SkosConceptScheme*> m_topInSchemes;
  QList<SkosConceptScheme*> m_inSchemes;
};

#endif
