#include "SkosModel.hpp"

#include <QDebug>

void SkosModel::addConcept(SkosConcept p_concept)
{
  qDebug() << "SkosModel::addConcept(p_concept =" << p_concept.getUrl() << ")";
  if (findConcept(p_concept.getUrl()) == m_concepts.end())
  {
    m_concepts.append(p_concept);
  }
  else
  {
    qDebug() << "SkosModel::addConcept() - Concept already exists";
  }
}

void SkosModel::addPrefLabelToConcept(Soprano::Node p_prefLabel,
                                      QUrl p_concept)
{
  qDebug() << "SkosModel::addPrefLabelToConcept(p_prefLabel=" <<
    p_prefLabel.toString() << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_iter = findConcept(p_concept);
  if (l_iter == m_concepts.end())
  {
    qDebug() << "SkosModel::addPrefLabelToConcept() - Concept does not exists";
  }
  else
  {
    l_iter->addPrefLabel(p_prefLabel);
  }
}

void SkosModel::addAltLabelToConcept(Soprano::Node p_altLabel,
                                     QUrl p_concept)
{
  qDebug() << "SkosModel::addAltLabelToConcept(p_altLabel=" <<
    p_altLabel.toString() << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_iter = findConcept(p_concept);
  if (l_iter == m_concepts.end())
  {
    qDebug() << "SkosModel::addAltLabelToConcept() - Concept does not exists";
  }
  else
  {
      l_iter->addAltLabel(p_altLabel);
  }
}

void SkosModel::addHiddenLabelToConcept(Soprano::Node p_hiddenLabel,
                                        QUrl p_concept)
{
  qDebug() << "SkosModel::addHiddenLabelToConcept(p_hiddenLabel=" <<
    p_hiddenLabel.toString() << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_iter = findConcept(p_concept);
  if (l_iter == m_concepts.end())
  {
    qDebug() << "SkosModel::addHiddenLabelToConcept()"
             << "- Concept does not exists";
  }
  else
  {
      l_iter->addHiddenLabel(p_hiddenLabel);
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
