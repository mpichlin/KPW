#ifndef URL_PREDICATE_MAP_HPP
#define URL_PREDICATE_MAP_HPP

#include <map>
#include <QUrl>

enum EUrlPredicate
{
  GeneralPredicate = 0,
  RdfType          = 1,
  PrefLabel        = 2,
  AltLabel         = 3,
  HiddenLabel      = 4,
  Related          = 5,
  Broader          = 6,
  Narrower         = 7,
  HasTopConcept    = 8,
  IsTopConceptOf   = 9
};

class UrlPredicateMap
{
public:
  UrlPredicateMap();
  EUrlPredicate mapUrl(const QUrl &p_url);
private:
  void initializeMap();
  std::map<QUrl, EUrlPredicate> m_map;
};
#endif
