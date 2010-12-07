#include "UrlPredicateMap.hpp"

#include <QDebug>

UrlPredicateMap::UrlPredicateMap()
{
  initializeMap();
}

void UrlPredicateMap::initializeMap()
{
  qDebug() << "UrlMap::initMap()";
  m_map[QUrl("http://www.w3.org/1999/02/22-rdf-syntax-ns#type")] = RdfType;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#prefLabel")] = PrefLabel;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#altLabel")] = AltLabel;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#hiddenLabel")] =
    HiddenLabel;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#related")] = Related;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#broader")] = Broader;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#narrower")] = Narrower;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#hasTopConcept")] =
    HasTopConcept;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#isTopConceptOf")] =
    IsTopConceptOf;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#inScheme")] = IsInScheme;
}

EUrlPredicate UrlPredicateMap::mapUrl(const QUrl &p_url)
{
  qDebug() << "UrlMap::mapUrl(p_url =" << p_url;
  std::map<QUrl, EUrlPredicate>::iterator l_it;
  l_it = m_map.find(p_url);
  if (l_it != m_map.end())
  {
    qDebug() << "UrlMap::mapUrl() - found EUrlPredicate =" << l_it->second;
    return l_it->second;
  }
  else
  {
    qDebug() << "UrlMap::mapUrl() - not found EUrlPredicate";
    return GeneralPredicate;
  }
}
