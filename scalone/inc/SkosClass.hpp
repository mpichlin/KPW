#ifndef SKOS_CLASS_HPP
#define SKOS_CLASS_HPP

/*! \file SkosClass.hpp
 *  \brief Zawiera definicję klasy SkosClass
 *
 * Plik zawiera definicję klasy SkosClass. Zawiera ona cechy wspólne wszystkich
 * klas języka SKOS.
 *
 * \author Michał Pichliński
 * \date 2010.12.05
 * \version 1.00.00
 */

#include "ELabelType.hpp"

#include <Soprano/Node>
#include <QUrl>
#include <QList>

/*! \class SkosClass
 *  \brief Klasa posiadająca cechy wspólne klas języka SKOS.
 *
 * Klasa modeluje cechy wspólne klas języka SKOS. Zawiera informacje na temat:
 * etykiet, definicji oraz URL SKOSowego obiektu.
 */
class SkosClass
{
public:
  /*! \brief Dodaje etykietę określonego typu
   *
   * Metoda dodająca etykietę określonego typu do obiektu 
   * \param p_label - dodawana etykieta
   * \param p_labelType - typ dodawanej etykiety
   * \pre Etykieta musi być spójna w kontekscie języka SKOS
   * \post Obiekt zawiera nową etykietę danego typu określoną przez parametry
   *       p_label, p_labelType
   */
  void addLabel(const Soprano::Node &p_label, 
                const ELabelType &p_labelType);

  /*! \brief Usuwa etykietę określonego typu
   *
   * Metoda usuwająca etykietę określonego typu z obiektu
   * \param p_label - etykieta która ma być usunięta
   * \param p_labelType - typ usuwanej etykiety
   * \pre Etykieta musi być wcześniej dodana do obiektu
   * \post Obiekt nie posiada etykiety określonej przez parametry p_label i
   * p_labelType
   */
  void removeLabel(const Soprano::Node &p_label, 
                   const ELabelType &p_labelType);

  /*! \brief Dodaje definicję
   * 
   * Dodaje definicję do obiektu
   * \param p_definition - definicja, która ma być dodana do obiektu
   * \pre Dodawana definicja nie może już istnieć w danym obiekcie
   * \post Obiekt zawiera nową definicję określoną przez p_definition
   */
  void addDefinition(const Soprano::Node &p_definition);

  /*! \brief Usuwa definicję
   *
   * Usuwa definicję z obiektu
   * \param p_definition - definicja, która ma być usunięta
   * \pre Usuwana definicja musi istnieć w danym obiekcie
   * \post Obiekt nie posiada etykiety określonej przez p_definition
   */
  void removeDefinition(const Soprano::Node &p_definition);

  /*! \brief Zwraca URL obiektu
   *
   * Zwraca URL obiektu
   * \return URL jednoznacznie opisujące obiekt
   */
  QUrl getUrl() const;

  /*! \brief Ustawia URL obiektu
   *
   * Ustawia URL obiektu
   * \param p_url - URL, które ma posiadać obiekt
   * \post URL obiektu zostaje ustawione na wartość określoną przez p_url
   */
  void setUrl(const QUrl &p_url);

  /*! \brief Zwraca listę etykiet określonego typu
   *
   * Zwraca listę wszystkich etykiet określonego typu z danego obiektu
   * \param p_labelType - typ etykiet który ma zostać zwrócony
   * \return Stałą referencję na listę wszystkich etykiet o typie określonym
   * przez p_labelType
   */
  const QList<Soprano::Node> &getLabelList(const ELabelType &p_labelType) 
    const;

  /*! \brief Określa czy obiekt danej klasy jest pusty
   * 
   * Określa czy obiekt danej klasy jest pusty, w sensie, że nie posiada
   * żadnej etykiety bądź definicji.
   * \return true - jeśli nie ma żadnej etykiety bądź definicji; w przeciwnym
   * wypadku zwraca false.
   */
  bool isEmpty() const;

  /*! \brief Zwraca listę definicji
   *
   * Zwraca listę wszystkich definicji przypisanych do danego obiektu
   * \return Stałą referencja na listę wszystkich definicji danego obiektu
   */
  const QList<Soprano::Node> &getDefinitions() const;

  /*! \brief Usuwa wszystkie etykiety
   *
   * Usuwa wszystkie etykiety przypisane do obiektu
   * \post Obiekt nie zawiera etykiet.
   */
  void clearLabels();
protected:
  /*! \brief Konstruktor domyślny
   *
   * Konstruktor domyślny jest chroniony, by uniemożliwić utworzenie
   * samodzielnego obiektu klasy SkosClass
   */
  SkosClass(){};
private:
  void addLabel(const Soprano::Node &p_label,
                QList<Soprano::Node> &p_labelList);
  bool isPrefLabelOk(const Soprano::Node &p_prefLabel) const;
  bool isLabelAlreadyExists(const Soprano::Node &p_label);
  bool isDefinitionOk(const Soprano::Node &p_definition);
  QList<Soprano::Node>::iterator findLabel(
    const Soprano::Node &p_label,
    QList<Soprano::Node> &p_labelList);
  QList<Soprano::Node>::iterator findDefinition(
    const Soprano::Node &p_definition);
  void removeLabel(const Soprano::Node &p_label,
                   QList<Soprano::Node> &p_labelList);

  QUrl m_url;
  QList<Soprano::Node> m_prefLabels;
  QList<Soprano::Node> m_altLabels;
  QList<Soprano::Node> m_hiddenLabels;
  QList<Soprano::Node> m_definitions;
};

#endif
