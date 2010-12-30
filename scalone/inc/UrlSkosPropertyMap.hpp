#ifndef URL_SKOS_PROPERTY_MAP
#define URL_SKOS_PROPERTY_MAP

#include <map>
#include <QUrl>

enum ESkosProperty
{
  ENonSkosProperty  = 0,
  EPrefLabel        = 1,
  EAltLabel         = 2,
  EHiddenLabel      = 3,
  ERelated          = 4,
  EBroader          = 5,
  ENarrower         = 6,
  EHasTopConcept    = 7,
  EIsTopConceptOf   = 8,
  EIsInScheme       = 9,
  EDefinition       = 10
};

class UrlSkosPropertyMap
{
public:
  UrlSkosPropertyMap();
  ESkosProperty mapUrl(const QUrl &p_url);
private:
  void initializeMap();
  std::map<QUrl, ESkosProperty> m_map;
};
#endif
