#include "SkosConceptScheme.hpp"

#include <QDebug>

void SkosConceptScheme::addConcept(const SkosConcept &p_concept,
                                   const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosConceptScheme::addConcept(p_topConcept="
           << p_concept.getUrl() << ")";
  if (isConsistencyOk(p_concept))
  {
    switch (p_schemeRelation)
    {
      case Top:
      {
        m_topConcepts.append(p_concept.getUrl());
        break;
      }
      case InScheme:
      {
        m_inSchemeConcepts.append(p_concept.getUrl());
        break;
      }
    }
  }
  else
  {
    qDebug() << "SkosConceptScheme::addConcept() - Concept already exists";
  }
}

bool SkosConceptScheme::hasConcept(const SkosConcept& p_concept,
                                   const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosConceptScheme::hasConcept(p_inSchemeConcept="
           << p_concept.getUrl() << ", p_schemeRelation=" 
           << p_schemeRelation << ")";
  switch (p_schemeRelation)
  {
    case Top:
    {
      return hasConcept(p_concept, m_topConcepts);
    }
    case InScheme:
    {
      return hasConcept(p_concept, m_inSchemeConcepts);
    }
  }
}

bool SkosConceptScheme::hasConcept(const SkosConcept &p_concept,
                                   QList<QUrl> &p_internalConcepts)
{
  qDebug() << "SkosConceptScheme::hasConcept(p_inSchemeConcept="
           << p_concept.getUrl() << ", p_internalConcepts)";
  for (QList<QUrl>::iterator l_internalConceptsIter =  
         p_internalConcepts.begin(); 
       l_internalConceptsIter != p_internalConcepts.end();
       ++l_internalConceptsIter)
  {
    if (*l_internalConceptsIter == p_concept.getUrl())
    {
      return true;
    }
  }
  return false;
}

bool SkosConceptScheme::isConsistencyOk(const SkosConcept &p_concept)
{
  return (!hasConcept(p_concept, m_inSchemeConcepts) &&
          !hasConcept(p_concept, m_topConcepts));
}

void SkosConceptScheme::removeConcept(const SkosConcept &p_conceptToRemove,
                                      QList<QUrl> &p_internalConcepts)
{
  QList<QUrl>::iterator l_internalConceptsIter;
  for (l_internalConceptsIter = p_internalConcepts.begin();
       l_internalConceptsIter != p_internalConcepts.end();
       ++l_internalConceptsIter)
  {
    if (*l_internalConceptsIter == p_conceptToRemove.getUrl())
    {
      break;
    }
  }
  if (l_internalConceptsIter == p_internalConcepts.end())
  {
    qDebug() << "SkosConceptScheme::removeConcept() - no such"
             << "concept in scheme";
  }
  else
  {
    p_internalConcepts.erase(l_internalConceptsIter);
  }
}

void SkosConceptScheme::removeConcept(const SkosConcept &p_conceptToRemove,
                                      const ESchemeRelation &p_schemeRelation)
{
  switch (p_schemeRelation)
  {
    case Top:
    {
      return removeConcept(p_conceptToRemove, m_topConcepts);
    }
    case InScheme:
    {
      return removeConcept(p_conceptToRemove, m_inSchemeConcepts);
    }
  }
}

const QList<QUrl> &SkosConceptScheme::getConcepts(
  const ESchemeRelation &p_schemeRelation) const
{
  switch (p_schemeRelation)
  {
    case Top:
    {
      return m_topConcepts;
    }
    case InScheme:
    {
      return m_inSchemeConcepts;
    }
  }
  return m_topConcepts;
}
