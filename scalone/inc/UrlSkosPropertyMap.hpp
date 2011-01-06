#ifndef URL_SKOS_PROPERTY_MAP
#define URL_SKOS_PROPERTY_MAP

/*! \file UrlSkosPropertyMap.hpp
 *  \brief Zawiera definicję klasy UrlSkosPropertyMap
 *
 * Plik zawiera definicję klasy UrlSkosPropertyMap oraz typu
 * wyliczeniowego ESkosProperty
 *
 * \author Michał Pichliński
 * \date 2010.12.02
 * \version 1.00.00
 */

#include <map>
#include <QUrl>

/*! \brief Typ określający właściwość klasy SKOSowej
 *
 * Typ wyliczeniowy pozwalający określić typ właściwości SKOSowej klasy
 */
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

/*! \class UrlSkosPropertyMap
 * \brief Klasa mapująca URL na właściwość SKOSową
 * 
 * Klasa mapująca URL na wartość typu wyliczeniowego określającego
 * właściwość klasy języka SKOS
 */
class UrlSkosPropertyMap
{
public:
  /*! \brief Domyślny konstruktor
   *
   * Domyślny konstruktor, w którym inicjalizowana jest mapa
   * URL -> właściwość klasy SKOSowej
   */
  UrlSkosPropertyMap();

  /*! \brief Mapuje URL na właściwość
   *
   * Mapuje URL na właściwość klasy SKOS
   * \param p_url - mapowany URL
   * \return Wynik mapowania URL na właściowość klasy SKOS
   */
  ESkosProperty mapUrl(const QUrl &p_url);
private:
  void initializeMap();
  std::map<QUrl, ESkosProperty> m_map;
};
#endif
