#ifndef SKOS_SERIALIZER_HPP
#define SKOS_SERIALIZER_HPP

#include "SkosModel.hpp"
#include <Soprano/Serializer>
#include <Soprano/Soprano>

class SkosSerializer
{
public:
  SkosSerializer(SkosModel *p_model):m_model(p_model){};
  void serialize(const QString &p_fileName,
                 const Soprano::RdfSerialization &p_fileType)
    {
      createStatementsFromModel();
      serializeStatemetsToFile();
    };
private:
  void createStatementsFromModel();
  void serializeStatemetsToFile();
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
    const QList<SkosConceptScheme> &p_conceptsList);
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
