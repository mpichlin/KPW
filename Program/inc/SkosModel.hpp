#ifndef SKOS_MODEL_HPP
#define SKOS_MODEL_HPP

#include "SkosConcept.hpp"
#include "SkosConceptScheme.hpp"

class SkosModel
{
public:
  void addConcept(SkosConcept p_concept);
  void addConceptScheme(SkosConceptScheme p_conceptScheme);
  void addLabel(Soprano::Node p_label, 
                const ELabelType &p_labelType,
                SkosClass p_skosClass);
  void addConceptRelation(const SkosConcept &p_baseConcept,
                          const SkosConcept &p_relatedConcept,
                          const ERelationType &p_relationType);
  void addTopConceptToScheme(QUrl p_concept, QUrl p_conceptScheme);
  void addConceptToScheme(QUrl p_concept, QUrl p_conceptScheme);
  QList<SkosConcept>::iterator findConcept(const SkosConcept &p_concept);
  QList<SkosConceptScheme>::iterator findConceptScheme(
    const SkosConceptScheme &p_conceptScheme);
  SkosClass * findSkosClass(const SkosClass &p_skosClass);
  void removeConcept(QUrl p_concept);
private:
  bool isConsistencyOk(const SkosClass &p_skosClass);

  QList<SkosConcept> m_concepts;
  QList<SkosConceptScheme> m_conceptSchemes;
};

#endif
