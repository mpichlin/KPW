#ifndef SKOS_CONCEPT_HPP
#define SKOS_CONCEPT_HPP

#include <Soprano/Node>
#include <QUrl>
#include <QList>

enum ERelationType
{
  RelatedRelation  = 0,
  BroaderRelation  = 1,
  NarrowerRelation = 2
};

class SkosConcept
{
public:
  SkosConcept(QUrl p_url):m_url(p_url){};
  QUrl getUrl() const;
  void addPrefLabel(Soprano::Node p_prefLabel);
  void addAltLabel(Soprano::Node p_altLabel);
  void addHiddenLabel(Soprano::Node p_hiddenLabel);
  int  addConceptRelation(SkosConcept *p_relatedConcept,
                          const ERelationType &p_relationType);
private:
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;
  bool isRelationAlreadyExists(const SkosConcept &p_concept);
  QUrl m_url;
  QList<Soprano::Node> m_prefLabels;
  QList<Soprano::Node> m_altLabels;
  QList<Soprano::Node> m_hiddenLabels;
  QList<SkosConcept*> m_broaderConcepts;
  QList<SkosConcept*> m_narrowerConcepts;
  QList<SkosConcept*> m_relatedConcepts;
};

#endif
