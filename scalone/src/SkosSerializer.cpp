#include "SkosSerializer.hpp"
#include <QFile>
#include <QDebug>

void SkosSerializer::createStatementsFromModel()
{
  QList<SkosConcept> l_conceptsList = m_model->getConcepts();
  QList<SkosConceptScheme> l_conceptSchemesList = m_model->getConceptSchemes();
  serializeConcepts(l_conceptsList);
  serializeConceptSchemes(l_conceptSchemesList);
  serializeConceptRelations(l_conceptsList);
  serializeSchemesFromConcepts(l_conceptsList);
  serializeTopConceptsFromSchemes(l_conceptSchemesList);
  serializeLabelsFromConcepts(l_conceptsList);
  serializeLabelsFromSchemes(l_conceptSchemesList);
  serializeDefinitionsFromConcepts(l_conceptsList);
  serializeDefinitionsFromSchemes(l_conceptSchemesList);
}

void SkosSerializer::serializeStatemetsToFile(
  const QString &p_fileName,
  const Soprano::RdfSerialization &p_fileType)
{ 
  const Soprano::Serializer* serializer =
    Soprano::PluginManager::instance()->discoverSerializerForSerialization( 
      p_fileType);
  QFile l_outputFile(p_fileName);
  l_outputFile.open(QIODevice::WriteOnly);
  QTextStream l_stream(&l_outputFile);
  Soprano::Model* sopranoModel = Soprano::createModel();
  sopranoModel->addStatements(m_statements);
  serializer->serialize(sopranoModel->listStatements(), 
                        l_stream, 
                        p_fileType);
}

void SkosSerializer::serializeConcepts(
  const QList<SkosConcept> &p_conceptsList)
{
  for (QList<SkosConcept>::const_iterator l_iter = p_conceptsList.begin();
       l_iter != p_conceptsList.end(); ++l_iter)
  {
    m_statements.append(
      Soprano::Statement(
        Soprano::Node(l_iter->getUrl()),
        Soprano::Node(QUrl("http://www.w3.org/1999/02/22-rdf-syntax-ns#type")),
        Soprano::Node(QUrl("http://www.w3.org/2004/02/skos/core#Concept"))));
  }
}

void SkosSerializer::serializeConceptSchemes(
  const QList<SkosConceptScheme> &p_conceptSchemesList)
{
  for (QList<SkosConceptScheme>::const_iterator l_iter = 
         p_conceptSchemesList.begin();
       l_iter != p_conceptSchemesList.end();
       ++l_iter)
  {
    m_statements.append(
      Soprano::Statement(
        Soprano::Node(l_iter->getUrl()),
        Soprano::Node(QUrl("http://www.w3.org/1999/02/22-rdf-syntax-ns#type")),
        Soprano::Node(
          QUrl("http://www.w3.org/2004/02/skos/core#ConceptScheme"))));
  }
}

void SkosSerializer::serializeConceptRelations(
  const QList<SkosConcept> &p_conceptsList)
{
  for (QList<SkosConcept>::const_iterator l_iter = p_conceptsList.begin();
       l_iter != p_conceptsList.end(); ++l_iter)
  {
    serializeConceptRelationsList(
      l_iter,
      RelatedRelation,
      QUrl("http://www.w3.org/2004/02/skos/core#related"));
    serializeConceptRelationsList(
      l_iter,
      BroaderRelation,
      QUrl("http://www.w3.org/2004/02/skos/core#broader"));
    serializeConceptRelationsList(
      l_iter,
      NarrowerRelation,
      QUrl("http://www.w3.org/2004/02/skos/core#narrower"));
  }
}

void SkosSerializer::serializeConceptRelationsList(
  const QList<SkosConcept>::const_iterator &p_baseConceptIter,
  const ERelationType &p_relationType,
  const QUrl &p_relationUrl)
{
  QList<QUrl> l_relatedConcepts = 
    p_baseConceptIter->getRelatedConceptsList(p_relationType);
  for(QList<QUrl>::const_iterator l_relatedIter = 
        l_relatedConcepts.begin();
      l_relatedIter != l_relatedConcepts.end();
      ++l_relatedIter)
  {
    m_statements.append(Soprano::Statement(
                          Soprano::Node(p_baseConceptIter->getUrl()),
                          Soprano::Node(p_relationUrl),
                          Soprano::Node(*l_relatedIter)));
  }
}

void SkosSerializer::serializeSchemesFromConcepts(
  const QList<SkosConcept> &p_conceptsList)
{
  for (QList<SkosConcept>::const_iterator l_iter = p_conceptsList.begin();
       l_iter != p_conceptsList.end(); ++l_iter)
  {
    serializeSchemesList(
      l_iter,
      Top,
      QUrl("http://www.w3.org/2004/02/skos/core#topConceptOf"));
    serializeSchemesList(
      l_iter,
      InScheme,
      QUrl("http://www.w3.org/2004/02/skos/core#inScheme"));
  }  
}

void SkosSerializer::serializeSchemesList(
  const QList<SkosConcept>::const_iterator &p_baseConceptIter,
  const ESchemeRelation &p_schemeRelation,
  const QUrl &p_schemeRelationUrl)
{
  QList<QUrl> l_schemes = 
    p_baseConceptIter->getConceptSchemesList(p_schemeRelation);
  for(QList<QUrl>::const_iterator l_schemesIter = 
        l_schemes.begin();
      l_schemesIter != l_schemes.end();
      ++l_schemesIter)
  {
    m_statements.append(Soprano::Statement(
                          Soprano::Node(p_baseConceptIter->getUrl()),
                          Soprano::Node(p_schemeRelationUrl),
                          Soprano::Node(*l_schemesIter)));
  }
}

void SkosSerializer::serializeTopConceptsFromSchemes(
  const QList<SkosConceptScheme> &p_schemesList)
{
  for (QList<SkosConceptScheme>::const_iterator l_iter = p_schemesList.begin();
       l_iter != p_schemesList.end(); ++l_iter)
  {
    QList<QUrl> l_concepts = l_iter->getConcepts(Top);
    for(QList<QUrl>::const_iterator l_conceptsIter = 
          l_concepts.begin();
        l_conceptsIter != l_concepts.end();
      ++l_conceptsIter)
    {
      m_statements.append(
        Soprano::Statement(
          Soprano::Node(l_iter->getUrl()),
          Soprano::Node(
            QUrl("http://www.w3.org/2004/02/skos/core#hasTopConcept")),
          Soprano::Node((*l_conceptsIter))));
    }
  }  
}

void SkosSerializer::serializeDefinitionsFromSchemes(
  const QList<SkosConceptScheme> &p_conceptSchemesList)
{
  for (QList<SkosConceptScheme>::const_iterator l_schemesIter =
         p_conceptSchemesList.begin();
       l_schemesIter != p_conceptSchemesList.end(); ++l_schemesIter)
  {
    QList<Soprano::Node> l_definitions = l_schemesIter->getDefinitions();
    for(QList<Soprano::Node>::const_iterator l_definitionsIter = 
          l_definitions.begin();
        l_definitionsIter != l_definitions.end();
        ++l_definitionsIter)
    {
      m_statements.append(
        Soprano::Statement(
          Soprano::Node(l_schemesIter->getUrl()),
          Soprano::Node(
            QUrl("http://www.w3.org/2004/02/skos/core#definition")),
          *l_definitionsIter));
    }
  }  
}

void SkosSerializer::serializeDefinitionsFromConcepts(
  const QList<SkosConcept> &p_conceptsList)
{
  for (QList<SkosConcept>::const_iterator l_conceptsIter =
         p_conceptsList.begin();
       l_conceptsIter != p_conceptsList.end(); ++l_conceptsIter)
  {
    qDebug() << "SkosSerializer::serializeDefinitionsFromConcepts - "
             << "finding definitions in concept"
             << l_conceptsIter->getUrl();
    QList<Soprano::Node> l_definitions = l_conceptsIter->getDefinitions();
    for(QList<Soprano::Node>::const_iterator l_definitionsIter = 
          l_definitions.begin();
        l_definitionsIter != l_definitions.end();
        ++l_definitionsIter)
    {
        qDebug() << "SkosSerializer::serializeDefinitionsFromConcepts -"
                 << "append definition:" << *l_definitionsIter;
      m_statements.append(
        Soprano::Statement(
          Soprano::Node(l_conceptsIter->getUrl()),
          Soprano::Node(
            QUrl("http://www.w3.org/2004/02/skos/core#definition")),
          *l_definitionsIter));
    }
  }  
}

void SkosSerializer::serializeLabelsFromConcepts(
  const QList<SkosConcept> &p_conceptsList)
{
  for (QList<SkosConcept>::const_iterator l_iter = p_conceptsList.begin();
       l_iter != p_conceptsList.end();
       ++l_iter)
  {
    serializeLabelType(
      l_iter,
      PrefferedLabelType,
      QUrl("http://www.w3.org/2004/02/skos/core#prefLabel"));
    serializeLabelType(
      l_iter,
      AlternativeLabelType,
      QUrl("http://www.w3.org/2004/02/skos/core#altLabel"));
    serializeLabelType(
      l_iter,
      HiddenLabelType,
      QUrl("http://www.w3.org/2004/02/skos/core#hiddenLabel"));
  }
}

void SkosSerializer::serializeLabelsFromSchemes(
  const QList<SkosConceptScheme> &p_schemesList)
{
  for (QList<SkosConceptScheme>::const_iterator l_iter = p_schemesList.begin();
       l_iter != p_schemesList.end();
       ++l_iter)
  {
    serializeLabelType(
      l_iter,
      PrefferedLabelType,
      QUrl("http://www.w3.org/2004/02/skos/core#prefLabel"));
    serializeLabelType(
      l_iter,
      AlternativeLabelType,
      QUrl("http://www.w3.org/2004/02/skos/core#altLabel"));
    serializeLabelType(
      l_iter,
      HiddenLabelType,
      QUrl("http://www.w3.org/2004/02/skos/core#hiddenLabel"));
  }
}

void SkosSerializer::serializeLabelType(
  const QList<SkosConcept>::const_iterator &p_conceptIter,
  const ELabelType &p_labelType,
  const QUrl &p_labelTypeUrl)
{
  QList<Soprano::Node> l_labels = 
    p_conceptIter->getLabelList(p_labelType);
  for(QList<Soprano::Node>::const_iterator l_labelsIter = 
        l_labels.begin();
      l_labelsIter != l_labels.end();
      ++l_labelsIter)
  {
    m_statements.append(Soprano::Statement(
                          Soprano::Node(p_conceptIter->getUrl()),
                          Soprano::Node(p_labelTypeUrl),
                          *l_labelsIter));
  }
}

void SkosSerializer::serializeLabelType(
  const QList<SkosConceptScheme>::const_iterator &p_schemeIter,
  const ELabelType &p_labelType,
  const QUrl &p_labelTypeUrl)
{
  QList<Soprano::Node> l_labels = 
    p_schemeIter->getLabelList(p_labelType);
  for(QList<Soprano::Node>::const_iterator l_labelsIter = 
        l_labels.begin();
      l_labelsIter != l_labels.end();
      ++l_labelsIter)
  {
    m_statements.append(Soprano::Statement(
                          Soprano::Node(p_schemeIter->getUrl()),
                          Soprano::Node(p_labelTypeUrl),
                          *l_labelsIter));
  }
}
