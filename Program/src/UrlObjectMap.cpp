#include "UrlObjectMap.hpp"

#include <QDebug>

UrlObjectMap::UrlObjectMap()
{
  initializeMap();
}

void UrlObjectMap::initializeMap()
{
  qDebug() << "UrlMap::initMap()";
  m_map[QUrl("http://www.w3.org/2004/02/skos/core#Concept")] = Concept;
}

EUrlObject UrlObjectMap::mapUrl(const QUrl &p_url)
{
  qDebug() << "UrlMap::mapUrl(p_url =" << p_url;
  std::map<QUrl, EUrlObject>::iterator l_it;
  l_it = m_map.find(p_url);
  if (l_it != m_map.end())
  {
    qDebug() << "UrlMap::mapUrl() - found EUrlObject =" << l_it->second;
    return l_it->second;
  }
  else
  {
    qDebug() << "UrlMap::mapUrl() - not found EUrlObject";
    return GeneralObject;
  }
}
