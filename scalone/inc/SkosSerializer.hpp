#ifndef SKOS_SERIALIZER_HPP
#define SKOS_SERIALIZER_HPP

/*! \file SkosSerializer.hpp
 *  \brief Zawiera definicję klasy SkosSerializer
 *
 * Plik zawiera definicję klasy SkosSerializer.
 *
 * \author Michał Pichliński
 * \date 2010.12.11
 * \version 1.00.00
 */

#include "SkosModel.hpp"
#include <Soprano/Serializer>
#include <Soprano/Soprano>

/*! \class SkosSerializer
 * \brief Klasa odpowiadająca za tworzenie  plików zawierających dane zapisane
 * w języku SKOS
 *
 * Klasa odpowiadająca za tworzenie plików zawierających dane zapisane
 * w języku SKOS na podstawie modelu. Jest to nakładka na serializer dostarczony
 * przez bibliotekę Soprano RDF Framework, z modyfikacją pozwalającą na
 * interpretację języka SKOS.
 */
class SkosSerializer
{
public:
  /*! \brief Konstruktor z określonym modelem
   *
   * Konstruktor w którym podawany jest wskaźnik na model, na podstawie, którego
   * będzie tworzny plik
   * \param p_model - wskaźnik na model na podstawie, którego ma zostać 
   * zapełniony danymi plik wyjściowy
   * \post Stworzony obiekt serializera, który  wypełni plik danymi z modelu na,
   * który wskazuje p_model
   */
  SkosSerializer(SkosModel *p_model):m_model(p_model){};

  /*! \brief Tworzy plik danego typu o danej nazwie
   *
   * Tworzy plik danego typu o danej nazwie na podstawie modelu zawartego w
   * obiekcie serializera
   * \param p_fileName - nazwa pliku, do którego zostanie zapisany model
   * \param p_fileType - typ pliku, który zostanie utworzony
   * \post Powstaje plik o nazwie p_fileName, typu p_fileType, zawierający
   * model podstawiony w konstruktorze obiektu serializera
   */
  void serialize(const QString &p_fileName,
                 const Soprano::RdfSerialization &p_fileType)
    {
      createStatementsFromModel();
      serializeStatemetsToFile(p_fileName, p_fileType);
    };
private:
  void createStatementsFromModel();
  void serializeStatemetsToFile(const QString &p_fileName,
                                const Soprano::RdfSerialization &p_fileType);
  void serializeConcepts(const QList<SkosConcept> &p_conceptsList);
  void serializeConceptSchemes(
    const QList<SkosConceptScheme> &p_conceptSchemesList);
  void serializeConceptRelations(
    const QList<SkosConcept> &p_conceptsList);
  void serializeConceptRelationsList(
    const QList<SkosConcept>::const_iterator &p_baseConceptIter,
    const ERelationType &p_relationType,
    const QUrl &p_relationUrl);
  void serializeSchemesFromConcepts(const QList<SkosConcept> &p_conceptsList);
  void serializeSchemesList(
    const QList<SkosConcept>::const_iterator &p_baseConceptIter,
    const ESchemeRelation &p_schemeRelation,
    const QUrl &p_schemeRelationUrl);
  void serializeTopConceptsFromSchemes(
    const QList<SkosConceptScheme> &p_schemesList);
  void serializeLabelsFromConcepts(const QList<SkosConcept> &p_conceptsList);
  void serializeLabelsFromSchemes(
    const QList<SkosConceptScheme> &p_conceptSchemesList);
  void serializeDefinitionsFromConcepts(
    const QList<SkosConcept> &p_conceptsList);
  void serializeDefinitionsFromSchemes(
    const QList<SkosConceptScheme> &p_conceptSchemesList);
  void serializeLabelType(
    const QList<SkosConcept>::const_iterator &p_conceptIter,
    const ELabelType &p_labelType,
    const QUrl &p_labelTypeUrl);
  void serializeLabelType(
    const QList<SkosConceptScheme>::const_iterator &p_schemeIter,
    const ELabelType &p_labelType,
    const QUrl &p_labelTypeUrl);
  SkosModel *m_model;
  QList<Soprano::Statement> m_statements;
};

#endif
