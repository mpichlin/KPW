#ifndef SKOS_CONCEPT_HPP
#define SKOS_CONCEPT_HPP

#include "ESchemeRelation.hpp"

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
  void addToScheme(SkosConceptScheme *p_conceptScheme,
                   const ESchemeRelation &p_schemeRelation);
  QList<SkosConceptScheme*>::iterator findInScheme(
    const SkosConceptScheme &p_conceptScheme,
    const ESchemeRelation &p_schemeRelation);
  QList<SkosConcept*>::iterator findConceptInRelation(
    const SkosConcept &p_concept, 
    const ERelationType &p_relationType);
  void removeConceptFromRelation(const SkosConcept &p_conceptToRemove,
                                 const ERelationType &p_relationType);
  void removeConceptFromScheme(const SkosConceptScheme &p_conceptScheme,
                               const ESchemeRelation &p_schemeRelation);
private:
  QList<SkosConceptScheme*>::iterator findInScheme(
    const SkosConceptScheme &p_conceptScheme,
    QList<SkosConceptScheme*> &p_internalSchemes);
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;
  bool isRelationAlreadyExists(const SkosConcept &p_concept);
  QList<SkosConcept*>::iterator findConceptInList(
    const SkosConcept &p_concept, 
    QList<SkosConcept*> &p_relationList);
  void removeConceptFromList(const SkosConcept &p_concept, 
                             QList<SkosConcept*> &p_relationList);
  void removeSchemeFromList(const SkosConceptScheme &p_conceptScheme, 
                            QList<SkosConceptScheme*> &p_schemeList);


  QList<SkosConcept*> m_broaderConcepts;
  QList<SkosConcept*> m_narrowerConcepts;
  QList<SkosConcept*> m_relatedConcepts;

  QList<SkosConceptScheme*> m_topInSchemes;
  QList<SkosConceptScheme*> m_inSchemes;
};

#endif
