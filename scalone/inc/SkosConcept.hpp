#ifndef SKOS_CONCEPT_HPP
#define SKOS_CONCEPT_HPP

/*! \file SkosConcept.hpp
 *  \brief Zawiera definicję klasy SkosConcept
 *
 * Plik zawiera definicję klasy SkosConcept.
 *
 * \author Michał Pichliński
 * \date 2010.12.01
 * \version 1.00.00
 */

#include "ESchemeRelation.hpp"
#include "SkosClass.hpp"
#include "SkosConceptScheme.hpp"
#include "ERelationType.hpp"

class SkosConceptScheme;

/*! \class SkosConcept
 * \brief Klasa modelująca SKOSową klasę Concept
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
  SkosConcept(const QUrl &p_url){setUrl(p_url);};

  /*! \brief Dodanie do relacji danego typu z danym konceptem
   *
   * Dodanie relacji danego typu z danym konceptem
   * \param p_relatedConcept - koncept, do którego będzie stworzona relacja
   * \param p_relationType - typ relacji jaka ma zostać utworzona
   * \pre p_relatedConcept musi istnieć
   * \post Do obiektu została dodana relacja typu p_relationType z konceptem
   * p_relatedConcept
   */
  int  addConceptRelation(const SkosConcept &p_relatedConcept,
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
  void addToScheme(const SkosConceptScheme &p_conceptScheme,
                   const ESchemeRelation &p_schemeRelation);

  /*! \brief Określa czy obiekt jest w danym schemacie konceptów w danej relacji
   *
   * Określa czy jest w danym schemacie konceptów w danej relacji
   * \param p_conceptScheme - schemat konceptów, w którym ma być obiekt
   * \param p_schemeRelation - typ relacji obiektu wobec schematu
   * \return true - jeśli obiekt znajduje się w schemacie p_conceptScheme,
   * w relacji p_schemeRelation; w przeciwnym wypadku false
   */
  bool isInScheme(const SkosConceptScheme &p_conceptScheme,
                  const ESchemeRelation &p_schemeRelation);

  /*! \brief Określa czy obiekt posiada daną relację z danym konceptem
   *
   * Określa czy obiekt posiada daną relację z danym konceptem
   * \param p_concept - koncept, który ma być powiązany
   * \param p_relationType - typ relacji konceptu wobec obiektu
   * \return true - jeśli obiekt posiada relację p_relationType względem
   * konceptu p_concept
   */
  bool isConceptRelated(const SkosConcept &p_concept, 
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

  /*! \brief Zwraca listę URL powiązanych konceptów
   *
   * Zwraca listę powiązanych konceptów z obiektem, danym typem relacji
   * \param p_relationType - typ relacji konceptów, których ma zawierać
   * referencja
   * \return Lista URL powiązanych konceptów relacją typu p_relationType
   */
  const QList<QUrl> &getRelatedConceptsList(
    const ERelationType &p_relationType) const;

  /*! \brief Zwraca listę URL schematów w którym znaduje się obiekt
   *
   * Zwraca listę powiązanych schematów konceptów z obiektem, danym typem 
   * relacji
   * \param p_schemeRelation - typ relacji schematów konceptów
   * \return Lista URL powiązanych konceptów relacją typu p_schemeRelation
   */
  const QList<QUrl> &getConceptSchemesList(
    const ESchemeRelation &p_schemeRelation) const;
private:
  bool isInScheme(const SkosConceptScheme &p_conceptScheme,
                  QList<QUrl> &p_internalSchemes);
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;
  bool isRelationAlreadyExists(const SkosConcept &p_concept);
  bool isConceptRelated(const SkosConcept &p_concept, 
                        QList<QUrl> &p_relationList);
  void removeConceptFromList(const SkosConcept &p_concept, 
                             QList<QUrl> &p_relationList);
  void removeSchemeFromList(const SkosConceptScheme &p_conceptScheme, 
                            QList<QUrl> &p_schemeList);

  QList<QUrl> m_broaderConcepts;
  QList<QUrl> m_narrowerConcepts;
  QList<QUrl> m_relatedConcepts;

  QList<QUrl> m_topInSchemes;
  QList<QUrl> m_inSchemes;
};

#endif
