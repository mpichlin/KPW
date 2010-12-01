#ifndef SKOS_PARSER_HPP
#define SKOS_PARSER_HPP

#include <QList>
#include <Soprano/Statement>

#include "SkosModel.hpp"
#include "UrlMap.hpp"

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
  SkosModel *m_model;
  QList<Soprano::Statement> m_statements;
  UrlMap m_urlMap;
};
#endif
