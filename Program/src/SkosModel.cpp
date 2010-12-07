#include "SkosModel.hpp"

#include <QDebug>

void SkosModel::addConcept(SkosConcept p_concept)
{
  qDebug() << "SkosModel::addConcept(p_concept =" << p_concept.getUrl() << ")";
  if (isConsistencyOk(p_concept))
  {
    m_concepts.append(p_concept);
  }
  else
  {
    qDebug() << "SkosModel::addConcept() - Concept is not consistent";
  }
}

void SkosModel::addConceptScheme(SkosConceptScheme p_conceptScheme)
{
  qDebug() << "SkosModel::addConceptScheme(p_conceptScheme =" 
           << p_conceptScheme.getUrl() << ")";
  if (findConceptScheme(p_conceptScheme.getUrl()) == m_conceptSchemes.end())
  {
    m_conceptSchemes.append(p_conceptScheme);
  }
  else
  {
    qDebug() << "SkosModel::addConceptScheme()"
             << "- ConceptScheme is not consistent ";
  }
}

bool SkosModel::isConsistencyOk(const SkosClass &p_skosClass)
{
  if (findConcept(p_skosClass.getUrl()) != m_concepts.end())
  {
    return false;
  }
  if (findConceptScheme(p_skosClass.getUrl()) != m_conceptSchemes.end())
  {
    return false;
  }
  return true;
}

void SkosModel::addPrefLabel(Soprano::Node p_prefLabel,
                             QUrl p_skosClass)
{
  qDebug() << "SkosModel::addPrefLabel(p_prefLabel=" <<
    p_prefLabel.toString() << ", p_skosClass=" << p_skosClass << ")";
  if (findSkosClass(p_skosClass) == NULL)
  {
    qDebug() << "SkosModel::addPrefLabel() - Skos class does not exists";
  }
  else
  {
    findSkosClass(p_skosClass)->addPrefLabel(p_prefLabel);
  }
}

void SkosModel::addAltLabel(Soprano::Node p_altLabel,
                            QUrl p_skosClass)
{
  qDebug() << "SkosModel::addAltLabel(p_altLabel=" <<
    p_altLabel.toString() << ", p_skosClass=" << p_skosClass << ")";
  if (findSkosClass(p_skosClass) == NULL)
  {
    qDebug() << "SkosModel::addAltLabel() - Skos class does not exists";
  }
  else
  {
    findSkosClass(p_skosClass)->addAltLabel(p_altLabel);
  }
}

void SkosModel::addHiddenLabel(Soprano::Node p_hiddenLabel,
                               QUrl p_skosClass)
{
  qDebug() << "SkosModel::addHiddenLabel(p_hiddenLabel=" <<
    p_hiddenLabel.toString() << ", p_skosClass=" << p_skosClass << ")";
  if (findSkosClass(p_skosClass) == NULL)
  {
    qDebug() << "SkosModel::addHiddenLabel()"
             << "- Skos class does not exists";
  }
  else
  {
      findSkosClass(p_skosClass)->addHiddenLabel(p_hiddenLabel);
  }
}

void SkosModel::addBroaderConcept(QUrl p_broaderConcept, QUrl p_concept)
{
  qDebug() << "SkosModel::addBroaderConcept(p_broaderConcept=" <<
    p_broaderConcept << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_baseConceptIter = findConcept(p_concept);
  QList<SkosConcept>::iterator l_broaderConceptIter = 
    findConcept(p_broaderConcept);
  if ((l_baseConceptIter == m_concepts.end()) ||
      (l_broaderConceptIter == m_concepts.end()))
  {
    qDebug() << "SkosModel::addBroaderConcept()"
             << "- at least one of concepts does not exists";
  }
  else
  {
    if((l_baseConceptIter->addConceptRelation(&*l_broaderConceptIter,
                                              BroaderRelation) == 0))
    {
      l_broaderConceptIter->addConceptRelation(&*l_baseConceptIter,
                                               NarrowerRelation);
    }
  }
}

void SkosModel::addNarrowerConcept(QUrl p_narrowerConcept, QUrl p_concept)
{
  qDebug() << "SkosModel::addNarrowerConcept(p_narrowerConcept=" <<
    p_narrowerConcept << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_baseConceptIter = findConcept(p_concept);
  QList<SkosConcept>::iterator l_narrowerConceptIter = 
    findConcept(p_narrowerConcept);
  if ((l_baseConceptIter == m_concepts.end()) ||
      (l_narrowerConceptIter == m_concepts.end()))
  {
    qDebug() << "SkosModel::addNarrowerConcept()"
             << "- at least one of concepts does not exists";
  }
  else
  {
    if((l_baseConceptIter->addConceptRelation(&*l_narrowerConceptIter, 
                                              NarrowerRelation)) == 0)
    {
      l_narrowerConceptIter->addConceptRelation(&*l_baseConceptIter,
                                                BroaderRelation);
    }
  }
} 

void SkosModel::addRelatedConcept(QUrl p_relatedConcept, QUrl p_concept)
{
  qDebug() << "SkosModel::addRelatedConcept(p_relatedConcept=" <<
    p_relatedConcept << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_baseConceptIter = findConcept(p_concept);
  QList<SkosConcept>::iterator l_relatedConceptIter = 
    findConcept(p_relatedConcept);
  if ((l_baseConceptIter == m_concepts.end()) ||
      (l_relatedConceptIter == m_concepts.end()))
  {
    qDebug() << "SkosModel::addRelatedConcept()"
             << "- at least one of concepts does not exists";
  }
  else
  {
    if((l_baseConceptIter->addConceptRelation(&*l_relatedConceptIter, 
                                              RelatedRelation)) == 0)
    {
      l_relatedConceptIter->addConceptRelation(&*l_baseConceptIter,
                                               RelatedRelation);
    }
  }
} 

QList<SkosConcept>::iterator SkosModel::findConcept(
  const QUrl &p_concept)
{
  for (QList<SkosConcept>::iterator l_iter = m_concepts.begin();
       l_iter != m_concepts.end(); ++l_iter)
  {
    if (l_iter->getUrl() == p_concept)
    {
      return l_iter;
    }
  }
  return m_concepts.end();
}

QList<SkosConceptScheme>::iterator SkosModel::findConceptScheme(
  const QUrl &p_conceptScheme)
{
  for (QList<SkosConceptScheme>::iterator l_iter = m_conceptSchemes.begin();
       l_iter != m_conceptSchemes.end(); ++l_iter)
  {
    if (l_iter->getUrl() == p_conceptScheme)
    {
      return l_iter;
    }
  }
  return m_conceptSchemes.end();
}

SkosClass * SkosModel::findSkosClass(const QUrl &p_skosClass)
{
  QList<SkosConcept>::iterator l_conceptsIter = findConcept(p_skosClass);
  if (l_conceptsIter != m_concepts.end())
  {
    return &*l_conceptsIter;
  }
  QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
    findConceptScheme(p_skosClass);
  if (l_conceptSchemesIter != m_conceptSchemes.end())
  {
    return &*l_conceptSchemesIter;
  }
  return NULL;
}

void SkosModel::addTopConceptToScheme(QUrl p_concept, QUrl p_conceptScheme)
{
  qDebug() << "SkosModel::addTopConceptToScheme(p_concept="
           << p_concept << ", p_conceptScheme=" << p_conceptScheme << ")";
  QList<SkosConcept>::iterator l_conceptsIter = findConcept(p_concept);
  QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
    findConceptScheme(p_conceptScheme);
  if ((l_conceptsIter == m_concepts.end()) ||
      (l_conceptSchemesIter == m_conceptSchemes.end()))
  {
    qDebug() << "SkosModel::addTopConceptToScheme() - one of Classes does"
             << "not exists";
  }
  else
  {
    l_conceptSchemesIter->addConcept(&*l_conceptsIter, Top);
    l_conceptsIter->addToScheme(&*l_conceptSchemesIter, Top);
  }
}

void SkosModel::addConceptToScheme(QUrl p_concept, QUrl p_conceptScheme)
{
  qDebug() << "SkosModel::addConceptToScheme(p_concept="
           << p_concept << ", p_conceptScheme=" << p_conceptScheme << ")";
  QList<SkosConcept>::iterator l_conceptsIter = findConcept(p_concept);
  QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
    findConceptScheme(p_conceptScheme);
  if ((l_conceptsIter == m_concepts.end()) ||
      (l_conceptSchemesIter == m_conceptSchemes.end()))
  {
    qDebug() << "SkosModel::addConceptToScheme() - one of Classes does"
             << "not exists";
  }
  else
  {
    l_conceptSchemesIter->addConcept(&*l_conceptsIter, InScheme);
    l_conceptsIter->addToScheme(&*l_conceptSchemesIter, InScheme);
  }
}

void SkosModel::removeConcept(QUrl p_concept)
{
  qDebug() << "SkosModel::removeConcept(p_concept=" << p_concept << ")";
  for (QList<SkosConcept>::iterator l_conceptsIter = m_concepts.begin(); 
       l_conceptsIter != m_concepts.end(); ++ l_conceptsIter)
  {
    l_conceptsIter->removeConceptFromRelation(p_concept, RelatedRelation);
    l_conceptsIter->removeConceptFromRelation(p_concept, BroaderRelation);
    l_conceptsIter->removeConceptFromRelation(p_concept, NarrowerRelation);
  }
  for (QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
         m_conceptSchemes.begin(); 
       l_conceptSchemesIter != m_conceptSchemes.end(); ++ l_conceptSchemesIter)
  {
    l_conceptSchemesIter->removeConcept(p_concept, Top);
    l_conceptSchemesIter->removeConcept(p_concept, InScheme);
  }
  QList<SkosConcept>::iterator l_conceptsIter = findConcept(p_concept);
  if (l_conceptsIter == m_concepts.end())
  {
    qDebug() << "SkosModel::removeConcept() - concept does not exists";
  }
  else
  {
    m_concepts.erase(l_conceptsIter);
    qDebug() << "SkosModel::removeConcept() - successfuly removed from Model";
  }
}
