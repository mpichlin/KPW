#ifndef SKOS_CONCEPT_SCHEME_HPP
#define SKOS_CONCEPT_SCHEME_HPP

#include "ESchemeRelation.hpp"

#include "SkosClass.hpp"
#include "SkosConcept.hpp"

class SkosConcept;

class SkosConceptScheme : public SkosClass
{
public:
  SkosConceptScheme(QUrl p_url){setUrl(p_url);};
  void addConcept(SkosConcept *p_topConcept,
                  const ESchemeRelation &p_schemeRelation);
  QList<SkosConcept*>::iterator findConcept(
    const SkosConcept& p_concept,
    const ESchemeRelation &p_schemeRelation);
private:
  bool isConsistencyOk(const SkosConcept &p_concept);
  QList<SkosConcept*>::iterator findConcept(
    const SkosConcept& p_inconcept,
    QList<SkosConcept*> p_internalConcepts);
  QList<SkosConcept*> m_topConcepts;
  QList<SkosConcept*> m_inSchemeConcepts;
};

#endif
