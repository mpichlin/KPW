#include "SkosConcept.hpp"

#include <QDebug>

QUrl SkosConcept::getUrl() const
{
  return m_url;
}

void SkosConcept::addPrefLabel(Soprano::Node p_prefLabel)
{
  qDebug() << "SkosConcept::addPrefLabel(p_prefLabel)";
  m_prefLabels.append(p_prefLabel);
}
