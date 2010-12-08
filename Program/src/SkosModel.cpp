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

void SkosModel::addConceptRelation(const SkosConcept &p_baseConcept,
                                   const SkosConcept &p_relatedConcept,
                                   const ERelationType &p_relationType)
{
  qDebug() << "SkosModel::addConceptRelation(p_baseConcept="
           << p_baseConcept.getUrl() << ", p_relatedConcept="
           << p_relatedConcept.getUrl() << ", p_relationType="
           << p_relationType << ")";
  QList<SkosConcept>::iterator l_baseConceptIter = findConcept(p_baseConcept);
  QList<SkosConcept>::iterator l_relatedConceptIter = 
    findConcept(p_relatedConcept);
  if ((l_baseConceptIter == m_concepts.end()) ||
      (l_relatedConceptIter == m_concepts.end()))
  {
    qDebug() << "SkosModel::addConceptRelation()"
             << "- at least one of concepts does not exists";
  }
  else
  {
    switch (p_relationType)
    {
      case BroaderRelation:
      {
        if((l_baseConceptIter->addConceptRelation(&*l_relatedConceptIter,
                                                  BroaderRelation) == 0))
        {
          l_relatedConceptIter->addConceptRelation(&*l_baseConceptIter,
                                                   NarrowerRelation);
        }
        break;
      }
      case NarrowerRelation:
      {
        if((l_baseConceptIter->addConceptRelation(&*l_relatedConceptIter, 
                                                  NarrowerRelation)) == 0)
        {
          l_relatedConceptIter->addConceptRelation(&*l_baseConceptIter,
                                                   BroaderRelation);
        }
        break;
      }
      case RelatedRelation:
      {
        if((l_baseConceptIter->addConceptRelation(&*l_relatedConceptIter, 
                                                  RelatedRelation)) == 0)
        {
          l_relatedConceptIter->addConceptRelation(&*l_baseConceptIter,
                                                   RelatedRelation);
        }
        break;
      }
    }
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

void SkosModel::addLabel(Soprano::Node p_label, 
                         const ELabelType &p_labelType,
                         SkosClass p_skosClass)
{
  qDebug() << "SkosModel::addLabel(p_label =" << p_label.toString()
           << ", p_labelType =" << p_labelType << ", p_skosClass ="
           << p_skosClass.getUrl();
  SkosClass *l_skosClassPtr = findSkosClass(p_skosClass);
  if (l_skosClassPtr == NULL)
  {
    qDebug() << "SkosModel::addLabel() - cllas does not exists";
  }
  else
  {
    l_skosClassPtr->addLabel(p_label, p_labelType);
  }
}

QList<SkosConcept>::iterator SkosModel::findConcept(
  const SkosConcept &p_concept)
{
  for (QList<SkosConcept>::iterator l_iter = m_concepts.begin();
       l_iter != m_concepts.end(); ++l_iter)
  {
    if (l_iter->getUrl() == p_concept.getUrl())
    {
      return l_iter;
    }
  }
  return m_concepts.end();
}

QList<SkosConceptScheme>::iterator SkosModel::findConceptScheme(
  const SkosConceptScheme &p_conceptScheme)
{
  for (QList<SkosConceptScheme>::iterator l_iter = m_conceptSchemes.begin();
       l_iter != m_conceptSchemes.end(); ++l_iter)
  {
    if (l_iter->getUrl() == p_conceptScheme.getUrl())
    {
      return l_iter;
    }
  }
  return m_conceptSchemes.end();
}

SkosClass * SkosModel::findSkosClass(const SkosClass &p_skosClass)
{
  QList<SkosConcept>::iterator l_conceptsIter = 
    findConcept(p_skosClass.getUrl());
  if (l_conceptsIter != m_concepts.end())
  {
    return &*l_conceptsIter;
  }
  QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
    findConceptScheme(p_skosClass.getUrl());
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
