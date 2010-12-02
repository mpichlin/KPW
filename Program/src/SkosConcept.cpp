#include "SkosConcept.hpp"

#include <QDebug>

QUrl SkosConcept::getUrl() const
{
  return m_url;
}

bool SkosConcept::isPrefLabelOk(const Soprano::Node &p_prefLabel) const
{
  qDebug() << "SkosConcept::isPrefLabelOk(p_prefLabel="
           << p_prefLabel.toString() << ")";
  for(QList<Soprano::Node>::const_iterator l_iter = m_prefLabels.begin();
      l_iter != m_prefLabels.end(); ++l_iter)
  {
    if (l_iter->language() == p_prefLabel.language())
    {
      qDebug() << "SkosConcept::isPrefLabelOk() - prefered label in this"
               << "language already exists";
      return false;
    }
  }
  return true;
}

void SkosConcept::addPrefLabel(Soprano::Node p_prefLabel)
{
  qDebug() << "SkosConcept::addPrefLabel(p_prefLabel="
           << p_prefLabel.toString() << ")";
  if (isPrefLabelOk(p_prefLabel))
  {
    m_prefLabels.append(p_prefLabel);
  }
}

