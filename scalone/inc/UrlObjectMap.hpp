#ifndef URL_OBJECT_MAP_HPP
#define URL_OBJECT_MAP_HPP

/*! \file UrlObjectMap.hpp
 *  \brief Zawiera definicję klasy UrlObjectMap
 *
 * Plik zawiera definicję klasy UrlObjectMap oraz typu
 * wyliczeniowego EUrlObject
 *
 * \author Michał Pichliński
 * \date 2010.12.02
 * \version 1.00.00
 */

#include <map>
#include <QUrl>

/*! \brief Typ określający obiekt z trójki rdf
 *
 * Typ wyliczeniowy pozwalający określi obiekt z trójki rdf. Wyróżnia się
 * następujące typy obiektów: ogólny obiekt, koncept, schemat konceptów
 */
enum EUrlObject
{
  GeneralObject = 0,
  Concept       = 1,
  ConceptScheme = 2
};

/*! \class UrlObjectMap
 * \brief Klasa mapując URL na typ obiektu
 *
 * Klasa mapująca URL na określenie typu obiektu trójki rdf.
 */
class UrlObjectMap
{
public:
  /*! \brief Domyślny konstruktor
   *
   * Domyślny konstruktor, w którym inicjalizowana jest mapa
   * URL -> typ obiektu z trójki rdf
   */
  UrlObjectMap();

  /*! \brief Mapuje URL na typ obiektu
   *
   * Mapuje URL na typ obiektu z trójki rdf
   * \param p_url - mapowany URL
   * \return Wynik mapowania URL na typ obiektu
   */
  EUrlObject mapUrl(const QUrl &p_url);
private:
  void initializeMap();
  std::map<QUrl, EUrlObject> m_map;
};

#endif
