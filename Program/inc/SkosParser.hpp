#ifndef SKOS_PARSER_HPP
#define SKOS_PARSER_HPP

#include <QList>
#include <Soprano/Statement>
#include <Soprano/Soprano>

#include "SkosModel.hpp"
#include "UrlPredicateMap.hpp"
#include "UrlObjectMap.hpp"

class SkosParser
{
public:
  SkosParser(SkosModel *p_model):m_model(p_model){};
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
  void parseStatement(const Soprano::Statement &p_statement);
  void parseClassDeclaration(const Soprano::Statement &p_statement);
  void parsePrefLabelDeclaration(const Soprano::Statement &p_statement);
  void parseAltLabelDeclaration(const Soprano::Statement &p_statement);
  void parseHiddenLabelDeclaration(const Soprano::Statement &p_statement);
  void parseBroaderDeclaration(const Soprano::Statement &p_statement);
  void parseNarrowerDeclaration(const Soprano::Statement &p_statement);
  void parseRelatedDeclaration(const Soprano::Statement &p_statement);
  void parseHasTopConcept(const QUrl &p_concept, 
                          const QUrl &p_conceptScheme);
  void parseIsTopConceptOf(const QUrl &p_conceptScheme,
                           const QUrl &p_concept);
  SkosModel *m_model;
  QList<Soprano::Statement> m_statements;
  UrlPredicateMap m_predicateMap;
  UrlObjectMap m_objectMap;
};
#endif
