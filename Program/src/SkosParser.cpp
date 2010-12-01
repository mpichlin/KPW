#include "SkosParser.hpp"
#include <Soprano/Parser>
#include <Soprano/Soprano>

#include <QDebug>

void SkosParser::parseFileToStatements(const QString &p_fileName)
{
  qDebug() << "SkosParser::parseFileToStatement(p_fileName=" 
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
    qWarning() << "SkosParser::parseStatements - empty statement list";
  }
  for (QList<Soprano::Statement>::iterator iter = m_statements.begin();
       iter != m_statements.end(); ++iter)
  {
    parseStatement(*iter);
  }
}

void SkosParser::parseStatement(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseStatement(p_statement="
           << p_statement << ")";
//QString l_predicate = p_statement.predicate().toString();
  ESpecialUrl l_specialUrl = m_urlMap.mapUrl(p_statement.predicate().uri());
  switch (l_specialUrl)
  {
  case RdfType:
  {
    parseClassDeclaration(p_statement);
    break;
  }
  }
  /*
  if (l_predicate == "http://www.w3.org/1999/02/22-rdf-syntax-ns#type")
  {
    parseClassDeclaration(p_statement);
  }
  if (l_predicate ==
  */
}

void SkosParser::parseClassDeclaration(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseClassDeclaration(p_statement="
           << p_statement << ")";
  ESpecialUrl l_specialUrl = m_urlMap.mapUrl(p_statement.object().uri());
  switch (l_specialUrl)
  {
  case Concept:
  {
    m_model->addConcept(p_statement.subject().uri());
    break;
  }
  }
/*
    if (l_object == )
  {
    m_model->addConcept(p_statement.subject().uri());
  }
*/
}
