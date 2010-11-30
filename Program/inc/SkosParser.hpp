#ifndef SKOS_PARSER_HPP
#define SKOS_PARSER_HPP

#include <QList>
#include <Soprano/Statement>

class SkosParser
{
public:
  SkosParser();
  void parseFile(QString p_fileName)
  {
    parseFileToStatements(p_fileName);
    parseStatements();
  }
private:
  void parseFileToStatements(QString p_fileName);
  void parseStatements();
  void parseStatement(Soprano::Statement p_statement);
  QList<Soprano::Statement> m_statements;
};
#endif
