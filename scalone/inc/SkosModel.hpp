#ifndef SKOS_MODEL_HPP
#define SKOS_MODEL_HPP

/*! \file SkosModel.hpp
 *  \brief Zawiera definicję klasy SkosModel
 *
 * Plik zawiera definicję klasy SkosModel
 *
 * \author Michał Pichliński
 * \date 2010.12.02
 * \version 1.00.00
 */

#include "SkosConcept.hpp"
#include "SkosConceptScheme.hpp"

/*! \class SkosModel
 * \brief Klasa będąca modelem informacyjnym stworzonym w oparciu o język SKOS
 *
 * Klasa będąca modelem informacyjnym stworzonym w oparciu o język SKOS. Obiekt
 * tej klasy zawiera spójny model w sensie języka SKOS i dba o to, by tej
 * spójności nienaruszyć.
 */
class SkosModel
{
public:
  /*! \brief Dodaje koncept na podstawie URL
   *
   * Dodaje koncept na podstawie URL. Dodawanie tym sposobem, nie sprawdza, czy
   * koncept jest pusty (tzn. nie ma żadnej etykiety, bądź definicji).
   * Metoda ta powinna być używana wyłącznie przez SkosParser.
   * \param p_concept - URL konceptu
   * \post W modelu znajduje się pusty koncept o URL p_concept.
   */
  void addConcept(const QUrl &p_concept);
  
  /*! \brief Dodaje koncept
   *
   * Dodaje koncept do modelu. Przy dodawaniu sprawdzane jest czy koncept nie
   * jest pusty. Puste koncepty nie będą dodawane do modelu.
   * \param p_concept - koncept który ma zostać dodany
   * \pre p_concept powinno nie być puste
   * \post Do modelu zostaje dodany niepusty koncept p_concept
   */
  void addConcept(const SkosConcept &p_concept);

  /*! \brief Dodaje schemat konceptów
   *
   * Dodaje schemat konceptów do modelu.
   * \param p_conceptScheme - schemat konceptów, który ma zostać dodany
   * \post schemat p_conceptScheme znajduje się w modelu
   */
  void addConceptScheme(const SkosConceptScheme &p_conceptScheme);

  /*! \brief Dodaje etykietę danego typu do danego obiektu
   *
   * Dodaje etykietę danego typu do danego obiektu klasy SkosClass.
   * W trakcie dodawania sprawdzana jest spójność etykiety.
   * \param p_label - etykieta, która ma być dodana
   * \param p_labelType - typ etykiety
   * \param p_classUrl - URL obiektu klasy SkosClass do którego ma zostać
   * dodana etykieta
   * \pre Obiekt do którego ma być dodana etykieta musi istnieć
   * \post Do obiektu o URL p_classUrl zostaje dodana etykieta p_label o typie
   * p_labelType
   */
  void addLabel(const Soprano::Node &p_label, 
                const ELabelType &p_labelType,
                const QUrl &p_classUrl);

  /*! \brief Usuwa etykietę danego typu z danego obiektu
   *
   * Usuwa etykietę danego typu z danego obiektu klasy SkosClass
   * \param p_label - etykieta, która ma zostać usunięta z obiektu
   * \param p_labelType - typ usuwanej etykiety
   * \param p_classUrl - URL obiektu, z którego zostanie usunięta etykieta
   * \pre Obiekt o URL p_classUrl musi istnieć
   * \post Obiekt o URL p_classUrl nie zawiera etykiety p_label typu p_labelType
   */
  void removeLabel(const Soprano::Node &p_label, 
                   const ELabelType &p_labelType,
                   const QUrl &p_classUrl);

  /*! \brief Dodaje definicję do danego obiektu
   *
   * Dodaje definicję do danego obiektu
   * \param p_definition - dodawana definicja
   * \param p_classUrl - URL obiektu, do którego ma zostać dodana definicja
   * \pre Obiekt o URL p_classUrl musi istnieć
   * \post Obiekt o URL p_classUrl zawiera definicję p_definition
   */
  void addDefinition(const Soprano::Node &p_definition, 
                     const QUrl &p_classUrl);

  /*! \brief Usuwa daną definicję z danego obiektu
   *
   * Usuwa daną definicję z danego obiektu
   * \param p_definition - definicja, która ma zostać usunięta
   * \param p_classUrl - URL obiektu, z którego ma zostać usunięta definicja
   * \pre Obiekt o URL p_classUrl musi istnieć
   * \post Obiekt o URL p_classUrl nie zawiera etykiety p_definition
   */
  void removeDefinition(const Soprano::Node &p_definition, 
                        const QUrl &p_classUrl);

  /*! \brief Dodaje relację pomiędzy konceptami
   *
   * Dodaje relację danego typu pomiędzy dwoma konceptami. Dodanie
   * relacji za pomocą tej metody powoduje automatyczne dopisanie relacji w 
   * drugą stronę, przykładowo: jeśli dodamy między konceptem A i B relację
   * Broader, to zostanie również dodana relacja między B i A typu Narrower.
   * Dodatkowo sprawdzana jest spójność, czy dodawana relacja nie narusza
   * poprawności modelu.
   * \param p_baseConcept - koncept bazowy do którego jest dodawana relacja
   * \param p_relatedConcept - koncept powiązany z konceptem bazowym daną
   * relacją
   * \param p_relationType - typ relacji jaką jest powiązany koncept bazowy z
   * konceptem powiązanym
   * \pre Koncepty p_baseConcept i p_relatedConcept muszą istnieć
   * \post Zostaje utworzona relacja typu p_relationType pomiędzy konceptem
   * p_baseConcept a p_relatedConcept, oraz relacja przeciwstawnego typu do
   * p_relationType pomiędzy p_relatedConcept a p_baseConcept
   */
  void addConceptRelation(const SkosConcept &p_baseConcept,
                          const SkosConcept &p_relatedConcept,
                          const ERelationType &p_relationType);
  
  /*! \brief Usuwa relację danego typu pomiędzy wybranymi konceptami
   *
   * Usuwa relację danego typu pomiędzy wybranymi konceptami. Jednocześnie
   * usuwa powiązaną relację w drugą stronę: przykładowo usunięcie B broader A
   * spowoduje usunięcie relacji A narrower B.
   * \pre Muszą istnieć koncepty p_baseConcept i p_relatedConcept oraz relacja
   * pomiędzy nimi
   * \post Nie ma relacji p_relationType pomiedzy p_baseConcept a 
   * p_relatedConcept, oraz relację powiązaną w drugą stronę
   */
  void removeConceptRelation(const SkosConcept &p_baseConcept,
                             const SkosConcept &p_relatedConcept,
                             const ERelationType &p_relationType);

  /*! \brief Dodaje koncept do schematu konceptów w danej relacji
   * 
   * Dodaje koncept do schematu konceptów w danej realacji.
   * \param p_concept - koncept dodawany do schematu
   * \param p_conceptScheme - schemat konceptów do którego zostanie dodany
   * koncept
   * \param p_schemeRelation - typ relacji konceptu względem schematu
   * \pre p_concept i p_conceptScheme muszą istnieć w modelu
   * \post p_conceptScheme zawiera koncept p_concept w relacji p_schemeRelation
   */
  void addConceptToScheme(const SkosConcept &p_concept,
                          const SkosConceptScheme &p_conceptScheme,
                          const ESchemeRelation &p_schemeRelation);

  /*! \brief Znajduje koncept w modelu
   *
   * Znajduje koncept w modelu
   * \param p_concept - szukany koncept
   * \return Iterator wskazujący na koncept p_concept w modelu
   */
  QList<SkosConcept>::iterator findConcept(const SkosConcept &p_concept);

  /*! \brief Znajduje schemat konceptów w modelu
   *
   * Znajduje schemat konceptów w modelu
   * \param p_conceptScheme - szukany schemat konceptów
   * \return Iterator wskazujący na schemat konceptów p_conceptScheme w modelu
   */
  QList<SkosConceptScheme>::iterator findConceptScheme(
    const SkosConceptScheme &p_conceptScheme);

  /*! \brief Usuwa koncept z modelu
   *
   * Usuwa koncept z modelu. Wraz z nim usuwane są wszystkie jego relacje.
   * \param p_concept - koncept do usunięcia
   * \post Model nie zawiera konceptu p_concept
   */
  void removeConcept(const SkosConcept &p_concept);

  /*! Usuwa schemat konceptów z modelu.
   *
   * Usuwa schemat konceptów z modelu. Wraz z nim usuwane są wszystkie jego
   * relacje.
   * \param p_conceptScheme - schemat konceptów, który ma zostać usunięty z
   * modelu
   * \post Model nie zawiera schematu konceptów p_conceptScheme
   */
  void removeConceptScheme(const SkosConceptScheme &p_conceptScheme);

  /*! \brief Zwraca listę wszystkich konceptów w modelu
   *
   * Zwraca listę wszystkich konceptów w modelu,
   * \return Stała referencja na listę konceptów znajdujących się w modelu
   */
  const QList<SkosConcept> &getConcepts() const {return m_concepts;};
  
  /*! \brief Zwraca listę wszystkich schematów konceptów
   *
   * Zwraca listę wszystkich schematów konceptów
   * \return Stała referencja na listę konceptów znajdujących się w modelu
   */
  const QList<SkosConceptScheme> &getConceptSchemes() const
    {return m_conceptSchemes;};

  /*! \brief Usuwa wszystkie puste obiekty klas SKOSowych w modelu
   *
   * Usuwa wszystkie puste obiekty klas SKOSowych w modelu
   * \post Wszystkie obiekty klas, które nie zawierają, jakiejkolwiek etykiety
   * bądź definicji zostają usunięte
   */
  void clearEmptyClasses();

  /*! \brief Zmienia URL obiektu SKOSowej klasy
   *
   * Zmienia URL obiektu SKOSowej klasy
   * \param p_classUrl - URL obiektu, który ma zostać zmieniony
   * \param p_newUrl - nowa wartość URL dla obiektu
   * \pre Obiekt określony p_classUrl musi istnieć w modelu
   * \post Obiekt p_classUrl ma teraz URL p_newUrl
   */
  void changeUrl(const QUrl &p_classUrl, const QUrl &p_newUrl);
private:
  bool isConsistencyOk(const QUrl &p_classUrl);
  SkosClass * findSkosClass(const QUrl &p_classUrl);
  bool isRelationConsistencyOk(const SkosConcept &p_baseConcept,
                               const SkosConcept &p_relatedConcept,
                               const ERelationType &p_relationType) const;
  bool isRelationConsistencyOk(
    const QList<QUrl> &p_baseRelationListType1,
    const QList<QUrl> &p_baseRelationListType2,
    const QList<QUrl> &p_relatedRelationListType1,
    const QList<QUrl> &p_relatedRelationListType2) const;
  bool isTwoListsHaveAtLeastOneCommonElement(
    const QList<QUrl> &l_firstList,
    const QList<QUrl> &l_secondList) const;

  QList<SkosConcept> m_concepts;
  QList<SkosConceptScheme> m_conceptSchemes;
};

#endif
