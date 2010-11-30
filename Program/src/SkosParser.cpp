#include "SkosParser.hpp"
#include <Soprano/Parser>
#include <Soprano/Soprano>

#include <QDebug>

SkosParser::SkosParser()
{
}

void SkosParser::parseFileToStatements(QString p_fileName)
{
  qDebug() << "SkosParser::parseFileToStatement(p_fileName:" 
           << p_fileName <<")";
   const Soprano::Parser *l_parser =
     Soprano::PluginManager::instance()->
       discoverParserForSerialization(Soprano::SerializationTurtle);
   
   Soprano::StatementIterator l_statementIterator;
   l_statementIterator = l_parser->parseFile(p_fileName, QUrl(),
                                             Soprano::SerializationTurtle);
   
   m_statements = l_statementIterator.allStatements();
   
   qDebug() << m_statements[0].predicate().toString();
};

void SkosParser::parseStatements()
{
  qDebug() << "SkosParser::parseStatements()";
  if (m_statements.empty())
  {
    qWarning() << "SkosParser::parseStatements() - empty statement list";
  }
  for (QList<Soprano::Statement>::iterator iter = m_statements.begin();
       iter != m_statements.end(); ++iter)
  {
    parseStatement(*iter);
  }
}

void SkosParser::parseStatement(Soprano::Statement p_statement)
{
  qDebug() << "SkosParser::parseStatement(p_statement: "
           << p_statement << ")";
}
