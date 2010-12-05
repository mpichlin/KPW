#ifndef SKOS_CONCEPT_SCHEME_HPP
#define SKOS_CONCEPT_SCHEME_HPP

#include "SkosClass.hpp"
#include "SkosConcept.hpp"

class SkosConcept;

class SkosConceptScheme : public SkosClass
{
public:
  SkosConceptScheme(QUrl p_url){setUrl(p_url);};
  void addTopConcept(SkosConcept *p_topConcept);
private:
  QList<SkosConcept*>::iterator findTopConcept(
    const SkosConcept& p_topConcept);
  QList<SkosConcept*> m_topConcepts;
};

#endif
