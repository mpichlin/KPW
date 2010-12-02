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
  EUrlPredicate l_specialUrl =
    m_predicateMap.mapUrl(p_statement.predicate().uri());
  switch (l_specialUrl)
  {
    case RdfType:
    {
      parseClassDeclaration(p_statement);
      break;
    }
    case PrefLabel:
    {
      parsePrefLabelDeclaration(p_statement);
      break;
    }
    case GeneralPredicate:
    {
      qDebug() << "SkosParser::parseStatement() - GeneralPredicate";
    }
  }
}

void SkosParser::parseClassDeclaration(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseClassDeclaration(p_statement="
           << p_statement << ")";
  EUrlObject l_specialUrl = m_objectMap.mapUrl(p_statement.object().uri());
  switch (l_specialUrl)
  {
    case Concept:
    {
      m_model->addConcept(p_statement.subject().uri());
      break;
    }
    case GeneralObject:
    {
      qDebug() << "SkosParser::parseStatement() - GeneralObject";
    }
  }
}

void SkosParser::parsePrefLabelDeclaration(
  const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parsePrefLabelDeclaration(p_statement="
           << p_statement << ")";
  m_model->addPrefLabelToConcept(p_statement.object(),
                                 p_statement.subject().uri());
}
