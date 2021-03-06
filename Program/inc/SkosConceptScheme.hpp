#ifndef SKOS_CONCEPT_SCHEME_HPP
#define SKOS_CONCEPT_SCHEME_HPP

#include "ESchemeRelation.hpp"

#include "SkosClass.hpp"
#include "SkosConcept.hpp"

class SkosConcept;

class SkosConceptScheme : public SkosClass
{
public:
  SkosConceptScheme(){};
  SkosConceptScheme(QUrl p_url){setUrl(p_url);};
  void addConcept(SkosConcept *p_concept,
                  const ESchemeRelation &p_schemeRelation);
  QList<SkosConcept*>::iterator findConcept(
    const SkosConcept& p_concept,
    const ESchemeRelation &p_schemeRelation);
  void removeConcept(const SkosConcept &p_conceptToRemove,
                     const ESchemeRelation &p_schemeRelation);
  QList<SkosConcept*> getConcepts(
    const ESchemeRelation &p_schemeRelation) const;
private:
  bool isConsistencyOk(const SkosConcept &p_concept);
  QList<SkosConcept*>::iterator findConcept(
    const SkosConcept& p_inconcept,
    QList<SkosConcept*> &p_internalConcepts);
  void removeConcept(const SkosConcept &p_conceptToRemove,
                     QList<SkosConcept*> &p_internalConcepts);
  QList<SkosConcept*> m_topConcepts;
  QList<SkosConcept*> m_inSchemeConcepts;
};

#endif
