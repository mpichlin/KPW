#include "SkosConcept.hpp"

QUrl SkosConcept::getUrl() const
{
  return m_url;
}

void SkosConcept::addPrefLabel(Soprano::Node p_prefLabel)
{
  m_prefLabels.append(p_prefLabel);
}
