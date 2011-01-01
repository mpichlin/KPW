#ifndef SKOS_MODEL_HPP
#define SKOS_MODEL_HPP

#include "SkosConcept.hpp"
#include "SkosConceptScheme.hpp"

#include <QDebug>
class SkosModel
{
public:
  void addConcept(const QUrl &p_concept);
  void addConcept(const SkosConcept &p_concept);
  void addConceptScheme(const SkosConceptScheme &p_conceptScheme);
  void addLabel(const Soprano::Node &p_label, 
                const ELabelType &p_labelType,
                const QUrl &p_classUrl);
  void removeLabel(const Soprano::Node &p_label, 
                   const ELabelType &p_labelType,
                   const QUrl &p_classUrl);
  void addDefinition(const Soprano::Node &p_definition, 
                     const QUrl &p_classUrl);
  void removeDefinition(const Soprano::Node &p_definition, 
                        const QUrl &p_classUrl);
  void addConceptRelation(const SkosConcept &p_baseConcept,
                          const SkosConcept &p_relatedConcept,
                          const ERelationType &p_relationType);
  void removeConceptRelation(const SkosConcept &p_baseConcept,
                             const SkosConcept &p_relatedConcept,
                             const ERelationType &p_relationType);
  void addConceptToScheme(const SkosConcept &p_concept,
                          const SkosConceptScheme &p_conceptScheme,
                          const ESchemeRelation &p_schemeRelation);
  QList<SkosConcept>::iterator findConcept(const SkosConcept &p_concept);
  QList<SkosConceptScheme>::iterator findConceptScheme(
    const SkosConceptScheme &p_conceptScheme);
  void removeConcept(const SkosConcept &p_concept);
  void removeConceptScheme(const SkosConceptScheme &p_conceptScheme);
  const QList<SkosConcept> &getConcepts() const {return m_concepts;};
  const QList<SkosConceptScheme> &getConceptSchemes() const
    {return m_conceptSchemes;};
  void clearEmptyClasses();
private:
  bool isConsistencyOk(const QUrl &p_classUrl);
  SkosClass * findSkosClass(const QUrl &p_classUrl);
  bool isRelationConsistencyOk(const SkosConcept &p_baseConcept,
                               const SkosConcept &p_relatedConcept,
                               const ERelationType &p_relationType) const;
  bool isRelationConsistencyOk(
    const QList<SkosConcept *> &p_baseRelationListType1,
    const QList<SkosConcept *> &p_baseRelationListType2,
    const QList<SkosConcept *> &p_relatedRelationListType1,
    const QList<SkosConcept *> &p_relatedRelationListType2) const;
  bool isTwoListsHaveAtLeastOneCommonElement(
    const QList<SkosConcept *> &l_firstList,
    const QList<SkosConcept *> &l_secondList) const;

  QList<SkosConcept> m_concepts;
  QList<SkosConceptScheme> m_conceptSchemes;
};

#endif
