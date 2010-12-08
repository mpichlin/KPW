#ifndef SKOS_CLASS_HPP
#define SKOS_CLASS_HPP

#include "ELabelType.hpp"

#include <Soprano/Node>
#include <QUrl>
#include <QList>

class SkosClass
{
public:
  SkosClass(){};
  SkosClass(const QUrl &p_url):m_url(p_url){};
  void addLabel(Soprano::Node p_label, 
                const ELabelType &p_labelType);
  void removeLabel(const Soprano::Node &p_label, 
                   const ELabelType &p_labelType);
  QUrl getUrl() const;
  void setUrl(const QUrl &p_url);
  QList<Soprano::Node> getLabelList(const ELabelType &p_labelType) const;
private:
  void addLabel(Soprano::Node p_label,
                QList<Soprano::Node> &p_labelList);
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label);
  QList<Soprano::Node>::iterator findLabel(
    const Soprano::Node &p_label,
    QList<Soprano::Node> &p_labelList);
  void removeLabel(const Soprano::Node &p_label,
                   QList<Soprano::Node> &p_labelList);

  QUrl m_url;
  QList<Soprano::Node> m_prefLabels;
  QList<Soprano::Node> m_altLabels;
  QList<Soprano::Node> m_hiddenLabels;
};

#endif
