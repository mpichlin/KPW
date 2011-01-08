#include "SkosModel.hpp"

#include <QDebug>
#include <QStack>

void SkosModel::addConcept(const QUrl &p_concept)
{
  qDebug() << "SkosModel::addConcept(p_concept =" << p_concept << ")";
  if (isConsistencyOk(p_concept))
  {
    m_concepts.append(SkosConcept(p_concept));
  }
  else
  {
    qDebug() << "SkosModel::addConcept() - Concept is not consistent";
  }
}

void SkosModel::addConcept(const SkosConcept &p_concept)
{
  qDebug() << "SkosModel::addConcept(p_concept =" << p_concept.getUrl() << ")";
  if (isConsistencyOk(p_concept.getUrl()) && !p_concept.isEmpty())
  {
    m_concepts.append(p_concept);
  }
  else
  {
    qDebug() << "SkosModel::addConcept() - Concept is not consistent";
  }
}

void SkosModel::addConceptScheme(const SkosConceptScheme &p_conceptScheme)
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
  if (l_baseConceptIter == m_concepts.end() || 
      l_relatedConceptIter == m_concepts.end()) 
  {
    qDebug() << "SkosModel::addConceptRelation()"
             << "- one of concepts does not exists";
    return;
  }
  if (!isRelationConsistencyOk(p_baseConcept, p_relatedConcept, p_relationType))
  {
    qDebug() << "SkosModel::addConceptRelation() - relation is not consistent";
  }
  else
  {
    switch (p_relationType)
    {
      case BroaderRelation:
      {
        if((l_baseConceptIter->addConceptRelation(*l_relatedConceptIter,
                                                  BroaderRelation) == 0))
        {
          l_relatedConceptIter->addConceptRelation(*l_baseConceptIter,
                                                   NarrowerRelation);
        }
        break;
      }
      case NarrowerRelation:
      {
        if((l_baseConceptIter->addConceptRelation(*l_relatedConceptIter, 
                                                  NarrowerRelation)) == 0)
        {
          l_relatedConceptIter->addConceptRelation(*l_baseConceptIter,
                                                   BroaderRelation);
        }
        break;
      }
      case RelatedRelation:
      {
        if((l_baseConceptIter->addConceptRelation(*l_relatedConceptIter, 
                                                  RelatedRelation)) == 0)
        {
          l_relatedConceptIter->addConceptRelation(*l_baseConceptIter,
                                                   RelatedRelation);
        }
        break;
      }
    }
  }
}

bool SkosModel::isConsistencyOk(const QUrl &p_skosClassUrl)
{
  if (findConcept(p_skosClassUrl) != m_concepts.end())
  {
    return false;
  }
  if (findConceptScheme(p_skosClassUrl) != m_conceptSchemes.end())
  {
    return false;
  }
  return true;
}

void SkosModel::addLabel(const Soprano::Node &p_label, 
                         const ELabelType &p_labelType,
                         const QUrl &p_skosClassUrl)
{
  qDebug() << "SkosModel::addLabel(p_label =" << p_label.toString()
           << ", p_labelType =" << p_labelType << ", p_skosClass ="
           << p_skosClassUrl;
  SkosClass *l_skosClassPtr = findSkosClass(p_skosClassUrl);
  if (l_skosClassPtr == NULL)
  {
    qDebug() << "SkosModel::addLabel() - class does not exists";
  }
  else
  {
    l_skosClassPtr->addLabel(p_label, p_labelType);
  }
}

void SkosModel::removeLabel(const Soprano::Node &p_label, 
                            const ELabelType &p_labelType,
                            const QUrl &p_skosClassUrl)
{
  qDebug() << "SkosModel::remove(p_label =" << p_label.toString()
           << ", p_labelType =" << p_labelType << ", p_skosClass ="
           << p_skosClassUrl;
  SkosClass *l_skosClassPtr = findSkosClass(p_skosClassUrl);
  if (l_skosClassPtr == NULL)
  {
    qDebug() << "SkosModel::removeLabel() - class does not exists";
  }
  else
  {
    l_skosClassPtr->removeLabel(p_label, p_labelType);
  }
}

QList<SkosConcept>::iterator SkosModel::findConcept(
  const SkosConcept &p_concept)
{
  qDebug() << "SkosModel::findConcept(p_concept ="
           << p_concept.getUrl() << ")";
  for (QList<SkosConcept>::iterator l_iter = m_concepts.begin();
       l_iter != m_concepts.end(); ++l_iter)
  {
    if (l_iter->getUrl() == p_concept.getUrl())
    {
      qDebug() << "SkosModel::findConcept() - found concept:" 
               << p_concept.getUrl();
      return l_iter;
    }
  }
  qDebug() << "SkosModel::findConcept() - concept not found:" 
           << p_concept.getUrl();
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

SkosClass * SkosModel::findSkosClass(const QUrl &p_skosClassUrl)
{
  QList<SkosConcept>::iterator l_conceptsIter = 
    findConcept(p_skosClassUrl);
  if (l_conceptsIter != m_concepts.end())
  {
    return &*l_conceptsIter;
  }
  QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
    findConceptScheme(p_skosClassUrl);
  if (l_conceptSchemesIter != m_conceptSchemes.end())
  {
    return &*l_conceptSchemesIter;
  }
  return NULL;
}

void SkosModel::addConceptToScheme(const SkosConcept &p_concept,
                                   const SkosConceptScheme &p_conceptScheme,
                                   const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosModel::addConceptToScheme(p_concept="
           << p_concept.getUrl() << ", p_conceptScheme=" 
           << p_conceptScheme.getUrl() << "p_schemeRelation="
           << p_schemeRelation << ")";
  QList<SkosConcept>::iterator l_conceptsIter = findConcept(p_concept);
  QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
    findConceptScheme(p_conceptScheme);
  if ((l_conceptsIter == m_concepts.end()) || 
      (l_conceptSchemesIter == m_conceptSchemes.end()))
  {
    qDebug() << "SkosModel::addConceptToScheme() - concept or scheme"
             << "does not exists";
  }
  else
  {
    l_conceptSchemesIter->addConcept(*l_conceptsIter, p_schemeRelation);
    l_conceptsIter->addToScheme(*l_conceptSchemesIter, p_schemeRelation);
  }
}

void SkosModel::removeConcept(const SkosConcept &p_concept)
{
  qDebug() << "SkosModel::removeConcept(p_concept=" << p_concept.getUrl()
           << ")";
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

void SkosModel::removeConceptScheme(const SkosConceptScheme &p_conceptScheme)
{
  qDebug() << "SkosModel::removeConceptScheme(p_conceptScheme="
           << p_conceptScheme.getUrl() << ")";
  for (QList<SkosConcept>::iterator l_conceptsIter = m_concepts.begin(); 
       l_conceptsIter != m_concepts.end(); ++ l_conceptsIter)
  {
    l_conceptsIter->removeConceptFromScheme(p_conceptScheme, Top);
    l_conceptsIter->removeConceptFromScheme(p_conceptScheme, InScheme);
  }
  QList<SkosConceptScheme>::iterator l_conceptSchemesIter = 
    findConceptScheme(p_conceptScheme);
  if (l_conceptSchemesIter == m_conceptSchemes.end())
  {
    qDebug() << "SkosModel::removeConceptScheme() - concept scheme does"
             << " not exists";
  }
  else
  {
    m_conceptSchemes.erase(l_conceptSchemesIter);
    qDebug() << "SkosModel::removeConceptScheme() - successfuly removed"
             << "from Model";
  }
}

void SkosModel::clearEmptyClasses()
{
  qDebug() << "SkosModel::clearEmptyClasses()";
  QStack<SkosConcept> l_conceptsToDelete;
  for (QList<SkosConcept>::iterator l_conceptsIt = m_concepts.begin();
       l_conceptsIt != m_concepts.end();
       ++l_conceptsIt)
  {
    if (l_conceptsIt->isEmpty())
    {
      qDebug() << "SkosModel::clearEmptyClasses() - adding concept to remove:"
               << l_conceptsIt->getUrl();
      l_conceptsToDelete.push(SkosConcept(*l_conceptsIt));
    }
  }
  while (!l_conceptsToDelete.isEmpty())
  {
    removeConcept(l_conceptsToDelete.pop());
  }
  QStack<SkosConceptScheme> l_conceptSchemesToDelete;
  for (QList<SkosConceptScheme>::iterator l_conceptSchemesIt =
         m_conceptSchemes.begin();
       l_conceptSchemesIt != m_conceptSchemes.end();
       ++l_conceptSchemesIt)
  {
    if (l_conceptSchemesIt->isEmpty())
    {
      qDebug() << "SkosModel::clearEmptyClasses() - added to remove  concept"
               << "scheme:" << l_conceptSchemesIt->getUrl();
      l_conceptSchemesToDelete.push(*l_conceptSchemesIt);
    }
  }
  while (!l_conceptSchemesToDelete.isEmpty())
  {
    removeConceptScheme(l_conceptSchemesToDelete.pop());
  }
  qDebug() << "SkosModel::clearEmptyClasses() - all empty classes has been"
           << "removed";
}

bool SkosModel::isRelationConsistencyOk(const SkosConcept &p_baseConcept,
                                        const SkosConcept &p_relatedConcept,
                                        const ERelationType &p_relationType) 
{
  if (p_baseConcept.getUrl() != p_relatedConcept.getUrl() &&
      !findConcept(p_baseConcept)->isConceptRelated(p_relatedConcept, 
                                                    p_relationType))
  {
    switch (p_relationType)
    {
      case RelatedRelation:
      {
        return isRelationConsistencyOk(
          p_baseConcept.getRelatedConceptsList(NarrowerRelation),
          p_baseConcept.getRelatedConceptsList(BroaderRelation),
          p_relatedConcept.getRelatedConceptsList(NarrowerRelation),
          p_relatedConcept.getRelatedConceptsList(BroaderRelation));
      }
      case BroaderRelation:
      {
        return isRelationConsistencyOk(
          p_baseConcept.getRelatedConceptsList(RelatedRelation),
          p_baseConcept.getRelatedConceptsList(NarrowerRelation),
          p_relatedConcept.getRelatedConceptsList(RelatedRelation),
          p_relatedConcept.getRelatedConceptsList(NarrowerRelation));
      }
      case NarrowerRelation:
      {
        bool l_answer = true;
        QList<QUrl> l_visitedConcepts;
        checkNarrowerConsistency(p_baseConcept, p_relatedConcept,
                                 l_visitedConcepts, l_answer);
        return l_answer;
      }
    }
  }
  return false;
}

bool SkosModel::isRelationConsistencyOk(
  const QList<QUrl> &p_baseRelationListType1,
  const QList<QUrl> &p_baseRelationListType2,
  const QList<QUrl> &p_relatedRelationListType1,
  const QList<QUrl> &p_relatedRelationListType2)
{
  return (!((isTwoListsHaveAtLeastOneCommonElement(
              p_relatedRelationListType1,
              p_baseRelationListType2)) ||
            (isTwoListsHaveAtLeastOneCommonElement(
              p_relatedRelationListType2,
              p_baseRelationListType1))));
}

bool SkosModel::isTwoListsHaveAtLeastOneCommonElement(
  const QList<QUrl> &l_firstList,
  const QList<QUrl> &l_secondList) const
{
  for (QList<QUrl>::const_iterator l_firstListIter = 
         l_firstList.begin();
       l_firstListIter != l_firstList.end();
       ++l_firstListIter)
  {
    for(QList<QUrl>::const_iterator l_secondListIter =
          l_secondList.begin();
        l_secondListIter != l_secondList.end();
        ++l_secondListIter)
    {
      if (*l_firstListIter == *l_secondListIter)
      {
        return true;
      }
    }
  }
  return false;
} 

void SkosModel::addDefinition(const Soprano::Node &p_definition, 
                              const QUrl &p_skosClassUrl)
{
  SkosClass *l_skosClassPtr = findSkosClass(p_skosClassUrl);
  if (l_skosClassPtr == NULL)
  {
    qDebug() << "SkosModel::addDefinition() - class does not exists";
  }
  else
  {
    l_skosClassPtr->addDefinition(p_definition);
  }
}

void SkosModel::removeDefinition(const Soprano::Node &p_definition, 
                                 const QUrl &p_skosClassUrl)
{
  SkosClass *l_skosClassPtr = findSkosClass(p_skosClassUrl);
  if (l_skosClassPtr == NULL)
  {
    qDebug() << "SkosModel::removeDefinition() - class does not exists";
  }
  else
  {
    l_skosClassPtr->removeDefinition(p_definition);
  }
}

void SkosModel::removeConceptRelation(const SkosConcept &p_baseConcept,
                                      const SkosConcept &p_relatedConcept,
                                      const ERelationType &p_relationType)
{
  qDebug() << "SkosModel::removeConceptRelation(p_baseConcept ="
           << p_baseConcept.getUrl() << ", p_relatedConcept"
           << p_relatedConcept.getUrl() << ", p_relationType"
           << p_relationType << ")";
  QList<SkosConcept>::iterator l_baseConceptIter = findConcept(p_baseConcept);
  QList<SkosConcept>::iterator l_relatedConceptIter = 
    findConcept(p_relatedConcept);
  if ((l_baseConceptIter != m_concepts.end()) && 
      (l_relatedConceptIter != m_concepts.end()))
  {
    l_baseConceptIter->removeConceptFromRelation(p_relatedConcept,
                                                 p_relationType);
    switch (p_relationType)
    {
      case RelatedRelation:
      {
        l_relatedConceptIter->removeConceptFromRelation(p_baseConcept,
                                                        RelatedRelation);
        break;
      }
      case BroaderRelation:
      {
        l_relatedConceptIter->removeConceptFromRelation(p_baseConcept,
                                                        NarrowerRelation);
        break;
      }
      case NarrowerRelation:
      {
        l_relatedConceptIter->removeConceptFromRelation(p_baseConcept,
                                                        BroaderRelation);
        break;
      }
    }    
  }
}

void SkosModel::changeUrl(const QUrl &p_classUrl, const QUrl &p_newUrl)
{
  qDebug() << "SkosModel::changeUrl(p_classUrl =" << p_classUrl
           << ", p_newUrl=" << p_newUrl << ")";
  SkosConcept l_oldConcept(p_classUrl);
  SkosConcept l_newConcept(p_newUrl);
  SkosConceptScheme l_oldScheme(p_classUrl);
  SkosConceptScheme l_newScheme(p_newUrl);
  for(QList<SkosConcept>::iterator l_conceptsIter = m_concepts.begin();
      l_conceptsIter !=  m_concepts.end(); ++l_conceptsIter)
  {
    changeUrl(l_conceptsIter, l_oldConcept, l_newConcept, RelatedRelation);
    changeUrl(l_conceptsIter, l_oldConcept, l_newConcept, BroaderRelation);
    changeUrl(l_conceptsIter, l_oldConcept, l_newConcept, NarrowerRelation);
    changeUrl(l_conceptsIter, l_oldScheme, l_newScheme, Top);
    changeUrl(l_conceptsIter, l_oldScheme, l_newScheme, InScheme);
  }
  for(QList<SkosConceptScheme>::iterator l_schemesIter = 
        m_conceptSchemes.begin();
      l_schemesIter !=  m_conceptSchemes.end(); ++l_schemesIter)
  {
    changeUrl(l_schemesIter, l_oldConcept, l_newConcept, Top);
    changeUrl(l_schemesIter, l_oldConcept, l_newConcept, InScheme);
  }
  SkosClass *l_skosClassPtr = findSkosClass(p_classUrl);
  if (l_skosClassPtr != NULL)
  {
    l_skosClassPtr->setUrl(p_newUrl);
  }
}

void SkosModel::changeUrl(const QList<SkosConcept>::iterator &p_concept,
                          const SkosConcept &p_old,
                          const SkosConcept &p_new,
                          const ERelationType &p_relationType)
{
  if(p_concept->isConceptRelated(p_old, p_relationType))
  {
    p_concept->removeConceptFromRelation(p_old, p_relationType);
    p_concept->addConceptRelation(p_new, p_relationType);
  }
}

void SkosModel::changeUrl(const QList<SkosConcept>::iterator &p_concept,
                          const SkosConceptScheme &p_old,
                          const SkosConceptScheme &p_new,
                          const ESchemeRelation &p_schemeRelation)
{
  if(p_concept->isInScheme(p_old, p_schemeRelation))
  {
    p_concept->removeConceptFromScheme(p_old, p_schemeRelation);
    p_concept->addToScheme(p_new, p_schemeRelation);
  }
}

void SkosModel::changeUrl(const QList<SkosConceptScheme>::iterator &p_scheme,
                          const SkosConcept &p_old,
                          const SkosConcept &p_new,
                          const ESchemeRelation &p_schemeRelation)
{
  if(p_scheme->hasConcept(p_old, p_schemeRelation))
  {
    p_scheme->removeConcept(p_old, p_schemeRelation);
    p_scheme->addConcept(p_new, p_schemeRelation);
  }
}

void SkosModel::checkNarrowerConsistency(const SkosConcept &p_base,
                                         const SkosConcept &p_narrower,
                                         QList<QUrl> &p_visitedConcepts,
                                         bool &p_answer)
{
  if (p_visitedConcepts.contains(p_narrower.getUrl()))
    return;
  p_visitedConcepts.append(p_narrower.getUrl());
  QList<SkosConcept>::iterator l_basePtr = findConcept(p_base);
  QList<SkosConcept>::iterator l_narrowerPtr = findConcept(p_narrower);
  if ((l_basePtr == m_concepts.end()) || (l_narrowerPtr == m_concepts.end()))
  {
    p_answer = false;
      return;
  }
  QList<QUrl> l_broaderOfNarrower = 
    l_narrowerPtr->getRelatedConceptsList(BroaderRelation);
  for (QList<QUrl>::iterator l_iter = l_broaderOfNarrower.begin();
       l_iter != l_broaderOfNarrower.end(); ++l_iter)
  {
    checkNarrowerConsistency(p_base, *l_iter, p_visitedConcepts, p_answer);
  }
  QList<QUrl> l_narrowerOfNarrower = 
    l_narrowerPtr->getRelatedConceptsList(NarrowerRelation);
  for (QList<QUrl>::iterator l_iter = l_narrowerOfNarrower.begin();
       l_iter != l_narrowerOfNarrower.end(); ++l_iter)
  {
    checkNarrowerConsistency(p_base, *l_iter, p_visitedConcepts, p_answer);
  }
  QList<QUrl> l_broaderOfBase = 
    l_basePtr->getRelatedConceptsList(BroaderRelation);
  for (QList<QUrl>::iterator l_iter = l_broaderOfBase.begin();
       l_iter != l_broaderOfBase.end(); ++l_iter)
  {
    if (*l_iter == p_narrower.getUrl())
    {
      p_answer =false;
      return;
    }
  }
}
