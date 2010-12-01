#include "UrlMap.hpp"

#include <QDebug>

UrlMap::UrlMap()
{
  initializeMap();
}

void UrlMap::initializeMap()
{
  qDebug() << "UrlMap::initMap()";
  m_map[QUrl("http://www.w3.org/1999/02/22-rdf-syntax-ns#type")] = RdfType;
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#Concept")] = Concept;
}

ESpecialUrl UrlMap::mapUrl(const QUrl &p_url)
{
  qDebug() << "UrlMap::mapUrl(p_url =" << p_url;
  std::map<QUrl, ESpecialUrl>::iterator l_it;
  l_it = m_map.find(p_url);
  if (l_it != m_map.end())
  {
    qDebug() << "UrlMap::mapUrl() - found ESpecialUrl =" << m_map[p_url];
    return m_map[p_url];
  }
  else
  {
    qDebug() << "UrlMap::mapUrl() - not found ESpecialUrl";
    return NonSpecialUrl;
  }
}
