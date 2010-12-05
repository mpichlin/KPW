#ifndef SKOS_CONCEPT_HPP
#define SKOS_CONCEPT_HPP

#include "SkosClass.hpp"
#include "SkosConceptScheme.hpp"

class SkosConceptScheme;

enum ERelationType
{
  RelatedRelation  = 0,
  BroaderRelation  = 1,
  NarrowerRelation = 2
};

class SkosConcept : public SkosClass
{
public:
  SkosConcept(QUrl p_url){setUrl(p_url);};
  int  addConceptRelation(SkosConcept *p_relatedConcept,
                          const ERelationType &p_relationType);
  void addAsTopInScheme(SkosConceptScheme *p_conceptScheme);
private:
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;
  bool isRelationAlreadyExists(const SkosConcept &p_concept);
  QList<SkosConceptScheme*>::iterator findConceptAsTopInScheme(
    const SkosConceptScheme &p_conceptScheme);

  QList<SkosConcept*> m_broaderConcepts;
  QList<SkosConcept*> m_narrowerConcepts;
  QList<SkosConcept*> m_relatedConcepts;

  QList<SkosConceptScheme*> m_topInSchemes;
};

#endif
