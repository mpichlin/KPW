#ifndef SKOS_PARSER_HPP
#define SKOS_PARSER_HPP

/*! \file SkosParser.hpp
 *  \brief Zawiera definicję klasy SkosParser
 *
 * Plik zawiera definicję klasy SkosParser.
 *
 * \author Michał Pichliński
 * \date 2010.11.30
 * \version 1.00.00
 */

#include <QList>
#include <Soprano/Statement>
#include <Soprano/Soprano>

#include "SkosModel.hpp"
#include "UrlSkosPropertyMap.hpp"
#include "UrlObjectMap.hpp"

/*! \class SkosParser
 * \brief Klasa odpowiadająca za parsowanie plików zawierających dane zapisane
 * w języku SKOS
 *
 * Klasa odpowiadająca za parsowanie plików zawierających dane zapisane
 * w języku SKOS. Jest to nakładka na parser dostarczony przez bibliotekę
 * Soprano RDF Framework, z modyfikacją pozwalającą na interpretację
 * języka SKOS.
 */
class SkosParser
{
public:
  /*! Konstruktor z określonym modelem
   *
   * Konstruktor w którym podawany jest wskaźnik na model, który będzie
   * uzupełniony na podstawie parsowanego pliku
   * \param p_model - wskaźnik na model który ma zostać zapełniony danymi z
   * parsowanego pliku
   * \post Stworzony obiekt parsera, który przy parsowaniu wypełni model na
   * który wskazuje p_model
   */
  SkosParser(SkosModel *p_model):m_model(p_model){};

  /*! \brief Parsuje plik danego typu o danej nazwie
   *
   * Parsuje plik danego typu o danej nazwie. W trakcie parsowania uzupełniany
   * jest model na który wskazuje obiekt parsera.
   * \param p_fileName - nazwa parsowanego pliku
   * \param p_fileType - typ parsowanego pliku
   * \pre Parsowany plik musi istnieć, być poprawny oraz jego typ musi być
   * właściwie określony
   * \post Model na który wskazuje obiekt parsera zostaje uzupełniony danymi
   * z pliku p_fileName
   */
  void parseFile(const QString &p_fileName, 
                 const Soprano::RdfSerialization &p_fileType)
  {
    parseFileToStatements(p_fileName, p_fileType);
    parseStatements();
  }
private:
  void parseFileToStatements(const QString& p_fileName,
                             const Soprano::RdfSerialization &p_fileType);
  void parseStatements();
  void parseStatementToClass(const Soprano::Statement &p_statement);
  void parseStatementToProperty(const Soprano::Statement &p_statement);
  void parseClassDeclaration(const Soprano::Statement &p_statement);
  void parsePrefLabelDeclaration(const Soprano::Statement &p_statement);
  void parseAltLabelDeclaration(const Soprano::Statement &p_statement);
  void parseHiddenLabelDeclaration(const Soprano::Statement &p_statement);
  void parseBroaderDeclaration(const Soprano::Statement &p_statement);
  void parseNarrowerDeclaration(const Soprano::Statement &p_statement);
  void parseRelatedDeclaration(const Soprano::Statement &p_statement);
  void parseHasTopConcept(const Soprano::Statement &p_statement);
  void parseIsTopConceptOf(const Soprano::Statement &p_statement);
  void parseInScheme(const Soprano::Statement &p_statement);
  void parseDefinition(const Soprano::Statement &p_statement);

  SkosModel *m_model;
  QList<Soprano::Statement> m_statements;
  UrlSkosPropertyMap m_skosPropertyMap;
  UrlObjectMap m_objectMap;
};
#endif
