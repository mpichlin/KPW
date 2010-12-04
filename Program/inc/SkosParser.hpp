#ifndef SKOS_PARSER_HPP
#define SKOS_PARSER_HPP

#include <QList>
#include <Soprano/Statement>

#include "SkosModel.hpp"
#include "UrlPredicateMap.hpp"
#include "UrlObjectMap.hpp"

class SkosParser
{
public:
  SkosParser(SkosModel *p_model):m_model(p_model){};
  void parseFile(QString p_fileName)
  {
    parseFileToStatements(p_fileName);
    parseStatements();
  }
private:
  void parseFileToStatements(const QString& p_fileName);
  void parseStatements();
  void parseStatement(const Soprano::Statement &p_statement);
  void parseClassDeclaration(const Soprano::Statement &p_statement);
  void parsePrefLabelDeclaration(const Soprano::Statement &p_statement);
  void parseAltLabelDeclaration(const Soprano::Statement &p_statement);
  void parseHiddenLabelDeclaration(const Soprano::Statement &p_statement);
  SkosModel *m_model;
  QList<Soprano::Statement> m_statements;
  UrlPredicateMap m_predicateMap;
  UrlObjectMap m_objectMap;
};
#endif
