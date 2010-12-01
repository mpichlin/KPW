#ifndef URL_MAP_HPP
#define URL_MAP_HPP

#include <map>
#include <QUrl>

enum ESpecialUrl
{
  NonSpecialUrl = 0,
  RdfType       = 1,
  Concept       = 2
};

class UrlMap
{
public:
  UrlMap();
  ESpecialUrl mapUrl(const QUrl &p_url);
private:
  void initializeMap();
  std::map<QUrl, ESpecialUrl> m_map;
};
#endif
