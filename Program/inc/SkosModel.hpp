#ifndef SKOS_MODEL_HPP
#define SKOS_MODEL_HPP

#include "SkosConcept.hpp"
#include "SkosConceptScheme.hpp"

#include <QDebug>
class SkosModel
{
public:
  void addConcept(QUrl p_concept);
  void addConcept(SkosConcept p_concept);
  void addConceptScheme(SkosConceptScheme p_conceptScheme);
  void addLabel(Soprano::Node p_label, 
                const ELabelType &p_labelType,
                SkosClass p_skosClass);
  void removeLabel(const Soprano::Node &p_label, 
                   const ELabelType &p_labelType,
                   const SkosClass &p_skosClass);
  void addDefinition(Soprano::Node p_definition, 
                     SkosClass p_skosClass);
  void removeDefinition(Soprano::Node p_definition, 
                        SkosClass p_skosClass);
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
  QList<SkosConcept> getConcepts() const {return m_concepts;};
  QList<SkosConceptScheme> getConceptSchemes() const {return m_conceptSchemes;};
  void clearEmptyClasses();
private:
  bool isConsistencyOk(const SkosClass &p_skosClass);
  SkosClass * findSkosClass(const SkosClass &p_skosClass);
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
