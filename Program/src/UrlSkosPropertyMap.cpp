#include "UrlSkosPropertyMap.hpp"

#include <QDebug>

UrlSkosPropertyMap::UrlSkosPropertyMap()
{
  initializeMap();
}

void UrlSkosPropertyMap::initializeMap()
{
  qDebug() << "UrlMap::initMap()";
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#prefLabel")] = EPrefLabel;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#altLabel")] = EAltLabel;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#hiddenLabel")] =
    EHiddenLabel;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#related")] = ERelated;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#broader")] = EBroader;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#narrower")] = ENarrower;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#hasTopConcept")] =
    EHasTopConcept;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#topConceptOf")] =
    EIsTopConceptOf;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#inScheme")] = EIsInScheme;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#definition")] = EDefinition;
}

ESkosProperty UrlSkosPropertyMap::mapUrl(const QUrl &p_url)
{
  qDebug() << "UrlMap::mapUrl(p_url =" << p_url;
  std::map<QUrl, ESkosProperty>::iterator l_it;
  l_it = m_map.find(p_url);
  if (l_it != m_map.end())
  {
    qDebug() << "UrlMap::mapUrl() - found ESkosPropertyUrl =" << l_it->second;
    return l_it->second;
  }
  else
  {
    qDebug() << "UrlMap::mapUrl() - not found ESkosPropertyUrl";
    return ENonSkosProperty;
  }
}
