#include "SkosParser.hpp"
#include <Soprano/Parser>

#include <QDebug>

void SkosParser::parseFileToStatements(
  const QString &p_fileName,
  const Soprano::RdfSerialization &p_fileType)
{
  qDebug() << "SkosParser::parseFileToStatement(p_fileName=" 
           << p_fileName <<", p_fileType=" 
           << p_fileType << ")";
   const Soprano::Parser *l_parser =
     Soprano::PluginManager::instance()->
       discoverParserForSerialization(Soprano::SerializationTurtle);
   
   Soprano::StatementIterator l_statementIterator;
   l_statementIterator = l_parser->parseFile(p_fileName, QUrl(),
                                             p_fileType);
   
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
    case AltLabel:
    {
      parseAltLabelDeclaration(p_statement);
      break;
    }
    case HiddenLabel:
    {
      parseHiddenLabelDeclaration(p_statement);
      break;
    }
    case Broader:
    {
      parseBroaderDeclaration(p_statement);
      break;
    }
    case Narrower:
    {
      parseNarrowerDeclaration(p_statement);
      break;
    }  
    case Related:
    {
      parseRelatedDeclaration(p_statement);
      break;
    }
    case HasTopConcept:
    {
      parseHasTopConcept(p_statement);
      break;
    }
    case IsTopConceptOf:
    {
      parseIsTopConceptOf(p_statement);
      break;
    }
    case IsInScheme:
    {
      parseInScheme(p_statement);
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
    case ConceptScheme:
    {
      m_model->addConceptScheme(p_statement.subject().uri());
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
  m_model->addLabel(p_statement.object(),
                    PrefferedLabelType,
                    p_statement.subject().uri());
}

void SkosParser::parseAltLabelDeclaration(
  const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseAltLabelDeclaration(p_statement="
           << p_statement << ")";
  m_model->addLabel(p_statement.object(),
                    AlternativeLabelType,
                    p_statement.subject().uri());
}

void SkosParser::parseHiddenLabelDeclaration(
  const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseHiddenLabelDeclaration(p_statement="
           << p_statement << ")";
  m_model->addLabel(p_statement.object(),
                    HiddenLabelType,
                    p_statement.subject().uri());
}

void SkosParser::parseBroaderDeclaration(
  const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseBroaderDeclaration(p_statement="
           << p_statement << ")";
  m_model->addConceptRelation(p_statement.subject().uri(),
                              p_statement.object().uri(),
                              BroaderRelation);
}

void SkosParser::parseNarrowerDeclaration(
  const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseNarrowerDeclaration(p_statement="
           << p_statement << ")";
  m_model->addConceptRelation(p_statement.subject().uri(),
                              p_statement.object().uri(),
                              NarrowerRelation);
}

void SkosParser::parseRelatedDeclaration(
  const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseNarrowerDeclaration(p_statement="
           << p_statement << ")";
  m_model->addConceptRelation(p_statement.subject().uri(),
                              p_statement.object().uri(),
                              RelatedRelation);
}

void SkosParser::parseHasTopConcept(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseHasTopConcept(p_statement="
           << p_statement << ")";
  m_model->addTopConceptToScheme(p_statement.object().uri(),
                                 p_statement.subject().uri());
}

void SkosParser::parseIsTopConceptOf(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseIsTopConceptOf(p_statement="
           << p_statement << ")";
  m_model->addTopConceptToScheme(p_statement.subject().uri(),
                                 p_statement.object().uri());
}

void SkosParser::parseInScheme(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseInScheme(p_statement="
           << p_statement << ")";
  m_model->addConceptToScheme(p_statement.subject().uri(),
                              p_statement.object().uri());

}
