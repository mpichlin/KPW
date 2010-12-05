#ifndef SKOS_CONCEPT_HPP
#define SKOS_CONCEPT_HPP

#include "SkosClass.hpp"

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
private:
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;
  bool isRelationAlreadyExists(const SkosConcept &p_concept);

  QList<SkosConcept*> m_broaderConcepts;
  QList<SkosConcept*> m_narrowerConcepts;
  QList<SkosConcept*> m_relatedConcepts;
};

#endif
