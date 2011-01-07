#include "SkosConcept.hpp"

#include <QDebug>

bool SkosConcept::isConceptRelated(const SkosConcept &p_concept, 
                                   QList<QUrl> &p_relationList)
{
  qDebug() << "SkosConcept::isConceptRelated(p_concept="
           << p_concept.getUrl() << ", p_relationList)";
  for(QList<QUrl>::iterator l_iter = p_relationList.begin();
      l_iter != p_relationList.end(); ++l_iter)
  {
    if (*l_iter == p_concept.getUrl())
    {
      return true;
    }
  }
  qDebug() << "SkosConcept::findConceptInList() - concept not found";
  return false;
}

bool SkosConcept::isRelationAlreadyExists(const SkosConcept &p_concept)
{
  return (isConceptRelated(p_concept, m_broaderConcepts) ||
          isConceptRelated(p_concept, m_narrowerConcepts) ||
          isConceptRelated(p_concept, m_relatedConcepts));
}

int SkosConcept::addConceptRelation(const SkosConcept &p_relatedConcept,
                                    const ERelationType &p_relationType)
{
  qDebug() << "SkosConcept::addConceptRelation(p_relatedConcept="
           << p_relatedConcept.getUrl() << ", p_relationType="
           << p_relationType << ")";
  if (isRelationAlreadyExists(p_relatedConcept))
  {
    qDebug() << "SkosConcept::addConceptRelation() - relation already exists";
    return 1;
  }
  else
  {
    switch (p_relationType)
    {
      case RelatedRelation:
      {
        m_relatedConcepts.append(p_relatedConcept.getUrl());
        break;
      }    
      case BroaderRelation:
      {
        m_broaderConcepts.append(p_relatedConcept.getUrl());
        break;
      }
      case NarrowerRelation:
      {
        m_narrowerConcepts.append(p_relatedConcept.getUrl());
        break;
      }
    }
    qDebug() << "SkosConcept::addConceptRelation() - concept relation added";
    return 0;
  }
}

bool SkosConcept::isInScheme(const SkosConceptScheme &p_conceptScheme,
                             const ESchemeRelation &p_schemeRelation)
{
  switch (p_schemeRelation)
  {
    case Top:
    {
      return isInScheme(p_conceptScheme, m_topInSchemes);
      break;
    }
    case InScheme:
    {
      return isInScheme(p_conceptScheme, m_inSchemes);
      break;
    }
  }
}

bool SkosConcept::isInScheme(const SkosConceptScheme &p_conceptScheme,
                             QList<QUrl> &p_internalSchemes)
{
  for(QList<QUrl>::iterator l_internalSchemesIter =
        p_internalSchemes.begin();
      l_internalSchemesIter != p_internalSchemes.end();
      ++l_internalSchemesIter)
  {
    if (*l_internalSchemesIter == p_conceptScheme.getUrl())
    {
      return true;
    }
  }
  return false;
}


void SkosConcept::addToScheme(const SkosConceptScheme &p_conceptScheme,
                              const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosConcept::addToScheme(p_conceptScheme="
           << p_conceptScheme.getUrl() << ", p_schemeRelation="
           << p_schemeRelation << ")";
  if (isInScheme(p_conceptScheme, m_topInSchemes) ||
      isInScheme(p_conceptScheme, m_inSchemes))
  {
    qDebug() << "SkosConcept::addToScheme() - concept is"
             << "already in this scheme";
  }
  else
  {
    switch (p_schemeRelation)
    {
      case Top:
      {
        m_topInSchemes.append(p_conceptScheme.getUrl());
        break;
      }
      case InScheme:
      {
        m_inSchemes.append(p_conceptScheme.getUrl());
        break;
      }
    }
  }
}

void SkosConcept::removeConceptFromRelation(
  const SkosConcept &p_conceptToRemove,
  const ERelationType &p_relationType)
{
  qDebug() << "SkosConcept::removeConceptFromRelation(p_conceptToRemove="
           << p_conceptToRemove.getUrl() << ", p_relationType="
           << p_relationType << ")";
  switch (p_relationType)
  {
    case RelatedRelation:
    {
      return removeConceptFromList(p_conceptToRemove, m_relatedConcepts);
    }
    case BroaderRelation:
    {
      return removeConceptFromList(p_conceptToRemove, m_broaderConcepts);
    }
    case NarrowerRelation:
    {
      return removeConceptFromList(p_conceptToRemove, m_narrowerConcepts);
    }
  }
}

void SkosConcept::removeConceptFromList(
    const SkosConcept &p_concept, 
    QList<QUrl> &p_relationList)
{
  QList<QUrl>::iterator l_relationListIter;
  for (l_relationListIter = p_relationList.begin();
       l_relationListIter != p_relationList.end(); ++l_relationListIter)
  {
    if (*l_relationListIter == p_concept.getUrl())
    {
      // cannot erease while iterating
      break;
    }
  }
  if (l_relationListIter == p_relationList.end())
  {
    qDebug() << "SkosConcept::removeConceptFromList() - no such concept";
  }
  else
  {
    p_relationList.erase(l_relationListIter);
  }
}
  
bool SkosConcept::isConceptRelated(const SkosConcept &p_concept, 
                                   const ERelationType &p_relationType)
{
  switch (p_relationType)
  {
    case RelatedRelation:
    {
      return isConceptRelated(p_concept, m_relatedConcepts);
    }
    case BroaderRelation:
    {
      return isConceptRelated(p_concept, m_broaderConcepts);
    }
    case NarrowerRelation:
    {
      return isConceptRelated(p_concept, m_narrowerConcepts);
    }
  }
  return false;
}

void SkosConcept::removeConceptFromScheme(
  const SkosConceptScheme &p_conceptScheme,
  const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosConcept::removeConceptFromScheme(p_conceptScheme="
           << p_conceptScheme.getUrl() << ", p_schemeRelation="
           << p_schemeRelation << ")";
  switch (p_schemeRelation)
  {
    case Top:
    {
      return removeSchemeFromList(p_conceptScheme, m_topInSchemes);
    }
    case InScheme:
    {
      return removeSchemeFromList(p_conceptScheme, m_inSchemes);
    }
  }
}

void SkosConcept::removeSchemeFromList(
  const SkosConceptScheme &p_conceptScheme, 
  QList<QUrl> &p_schemeList)
{
  QList<QUrl>::iterator l_schemeListIter;
  for (l_schemeListIter = p_schemeList.begin(); 
       l_schemeListIter != p_schemeList.end(); ++l_schemeListIter)
  {
    if (*l_schemeListIter == p_conceptScheme.getUrl())
    {
      break;
    }
  }
  if (l_schemeListIter == p_schemeList.end())
  {
    qDebug() << "SkosConcept::removeSchemeFromList() - no such scheme";
  }
  else
  {
    p_schemeList.erase(l_schemeListIter);
  }
}

const QList<QUrl> &SkosConcept::getRelatedConceptsList(
  const ERelationType &p_relationType) const
{
  qDebug() << "SkosConcept::getRelatedConceptList(p_relationType ="
           << p_relationType << ")";
  switch (p_relationType)
  {
    case BroaderRelation:
    {
      return m_broaderConcepts;
    }
    case NarrowerRelation:
    {
      return m_narrowerConcepts;
    }
    case RelatedRelation:
    {
      return m_relatedConcepts;
    }
  }
  return m_broaderConcepts;
}

const QList<QUrl> &SkosConcept::getConceptSchemesList(
  const ESchemeRelation &p_schemeRelation) const
{
  switch (p_schemeRelation)
  {
    case Top:
    {
      return m_topInSchemes;
    }
    case InScheme:
    {
      return m_inSchemes;
    }
  }
  return m_topInSchemes;
}
