#ifndef URL_OBJECT_MAP_HPP
#define URL_OBJECT_MAP_HPP

#include <map>
#include <QUrl>

enum EUrlObject
{
  GeneralObject = 0,
  Concept       = 1,
  ConceptScheme = 2
};

class UrlObjectMap
{
public:
  UrlObjectMap();
  EUrlObject mapUrl(const QUrl &p_url);
private:
  void initializeMap();
  std::map<QUrl, EUrlObject> m_map;
};
#endif
