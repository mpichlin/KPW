#include "SkosSerializer.hpp"

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
}

void SkosSerializer::serializeStatemetsToFile()
{ 
  const Soprano::Serializer* serializer =
    Soprano::PluginManager::instance()->discoverSerializerForSerialization( 
      Soprano::SerializationTurtle);
  QTextStream stream(stdout);
  Soprano::Model* sopranoModel = Soprano::createModel();
  sopranoModel->addStatements(m_statements);
  serializer->serialize(sopranoModel->listStatements(), 
                        stream, 
                        Soprano::SerializationTurtle);
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
  QList<SkosConcept*> l_relatedConcepts = 
    p_baseConceptIter->getRelatedConceptsList(p_relationType);
  for(QList<SkosConcept*>::const_iterator l_relatedIter = 
        l_relatedConcepts.begin();
      l_relatedIter != l_relatedConcepts.end();
      ++l_relatedIter)
  {
    m_statements.append(Soprano::Statement(
                          Soprano::Node(p_baseConceptIter->getUrl()),
                          Soprano::Node(p_relationUrl),
                          Soprano::Node((*l_relatedIter)->getUrl())));
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
  QList<SkosConceptScheme*> l_schemes = 
    p_baseConceptIter->getConceptSchemesList(p_schemeRelation);
  for(QList<SkosConceptScheme*>::const_iterator l_schemesIter = 
        l_schemes.begin();
      l_schemesIter != l_schemes.end();
      ++l_schemesIter)
  {
    m_statements.append(Soprano::Statement(
                          Soprano::Node(p_baseConceptIter->getUrl()),
                          Soprano::Node(p_schemeRelationUrl),
                          Soprano::Node((*l_schemesIter)->getUrl())));
  }
}

void SkosSerializer::serializeTopConceptsFromSchemes(
  const QList<SkosConceptScheme> &p_schemesList)
{
  for (QList<SkosConceptScheme>::const_iterator l_iter = p_schemesList.begin();
       l_iter != p_schemesList.end(); ++l_iter)
  {
    QList<SkosConcept*> l_concepts = l_iter->getConcepts(Top);
    for(QList<SkosConcept*>::const_iterator l_conceptsIter = 
          l_concepts.begin();
        l_conceptsIter != l_concepts.end();
      ++l_conceptsIter)
    {
      m_statements.append(
        Soprano::Statement(
          Soprano::Node(l_iter->getUrl()),
          Soprano::Node(
            QUrl("http://www.w3.org/2004/02/skos/core#hasTopConcept")),
          Soprano::Node((*l_conceptsIter)->getUrl())));
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
