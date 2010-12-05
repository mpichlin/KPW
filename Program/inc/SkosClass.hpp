#ifndef SKOS_CLASS_HPP
#define SKOS_CLASS_HPP

#include <Soprano/Node>
#include <QUrl>
#include <QList>

class SkosClass
{
public:
  void addPrefLabel(Soprano::Node p_prefLabel);
  void addAltLabel(Soprano::Node p_altLabel);
  void addHiddenLabel(Soprano::Node p_hiddenLabel);
  QUrl getUrl() const;
  void setUrl(const QUrl &p_url);
private:
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label) const;

  QUrl m_url;
  QList<Soprano::Node> m_prefLabels;
  QList<Soprano::Node> m_altLabels;
  QList<Soprano::Node> m_hiddenLabels;
};

#endif
