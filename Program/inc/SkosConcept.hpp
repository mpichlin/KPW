#ifndef SKOS_CONCEPT_HPP
#define SKOS_CONCEPT_HPP

#include <Soprano/Node>
#include <QUrl>
#include <QList>

class SkosConcept
{
public:
  SkosConcept(QUrl p_url):m_url(p_url){};
  QUrl getUrl() const;
  void addPrefLabel(Soprano::Node p_prefLabel);
private:
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  QUrl m_url;
  QList<Soprano::Node> m_prefLabels;
};

#endif
