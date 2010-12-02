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
