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
  void addAltLabel(Soprano::Node p_altLabel);
  void addHiddenLabel(Soprano::Node p_hiddenLabel);
private:
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;
  QUrl m_url;
  QList<Soprano::Node> m_prefLabels;
  QList<Soprano::Node> m_altLabels;
  QList<Soprano::Node> m_hiddenLabels;
};

#endif
