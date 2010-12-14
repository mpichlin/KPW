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
       discoverParserForSerialization(p_fileType);
   
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
    parseStatementToClass(*iter);
  }
  for (QList<Soprano::Statement>::iterator iter = m_statements.begin();
       iter != m_statements.end(); ++iter)
  {
    parseStatementToProperty(*iter);
  }
  m_model->clearEmptyClasses();
}

void SkosParser::parseStatementToClass(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseStatementToClass(p_statement="
           << p_statement << ")";
  if (p_statement.predicate() ==
      QUrl("http://www.w3.org/1999/02/22-rdf-syntax-ns#type"))
  {
    parseClassDeclaration(p_statement);
  }
}

void SkosParser::parseStatementToProperty(const Soprano::Statement &p_statement)
{
  ESkosProperty l_skosProperty =
    m_skosPropertyMap.mapUrl(p_statement.predicate().uri());
  switch (l_skosProperty)
  {
    case EPrefLabel:
    {
      parsePrefLabelDeclaration(p_statement);
      break;
    }
    case EAltLabel:
    {
      parseAltLabelDeclaration(p_statement);
      break;
    }
    case EHiddenLabel:
    {
      parseHiddenLabelDeclaration(p_statement);
      break;
    }
    case EBroader:
    {
      parseBroaderDeclaration(p_statement);
      break;
    }
    case ENarrower:
    {
      parseNarrowerDeclaration(p_statement);
      break;
    }  
    case ERelated:
    {
      parseRelatedDeclaration(p_statement);
      break;
    }
    case EHasTopConcept:
    {
      parseHasTopConcept(p_statement);
      break;
    }
    case EIsTopConceptOf:
    {
      parseIsTopConceptOf(p_statement);
      break;
    }
    case EIsInScheme:
    {
      parseInScheme(p_statement);
      break;
    }
    case ENonSkosProperty:
    {
      qDebug() << "SkosParser::parseStatement() - ENonSkosProperty";
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
  m_model->addConceptToScheme(p_statement.object().uri(),
                              p_statement.subject().uri(),
                              Top);
}

void SkosParser::parseIsTopConceptOf(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseIsTopConceptOf(p_statement="
           << p_statement << ")";
  m_model->addConceptToScheme(p_statement.subject().uri(),
                              p_statement.object().uri(),
                              Top);
}

void SkosParser::parseInScheme(const Soprano::Statement &p_statement)
{
  qDebug() << "SkosParser::parseInScheme(p_statement="
           << p_statement << ")";
  m_model->addConceptToScheme(p_statement.subject().uri(),
                              p_statement.object().uri(),
                              InScheme);
}
