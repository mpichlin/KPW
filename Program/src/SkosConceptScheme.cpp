#include "SkosConceptScheme.hpp"

#include <QDebug>

void SkosConceptScheme::addConcept(SkosConcept *p_concept,
                                   const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosConceptScheme::addConcept(p_topConcept="
           << p_concept->getUrl() << ")";
  if (isConsistencyOk(*p_concept))
  {
    switch (p_schemeRelation)
    {
      case Top:
      {
        m_topConcepts.append(p_concept);
        break;
      }
      case InScheme:
      {
        m_inSchemeConcepts.append(p_concept);
        break;
      }
    }
  }
  else
  {
    qDebug() << "SkosConceptScheme::addConcept() - Concept already exists";
  }
}

QList<SkosConcept*>::iterator SkosConceptScheme::findConcept(
  const SkosConcept& p_concept, const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosConceptScheme::findConcept(p_inSchemeConcept="
           << p_concept.getUrl() << ", p_schemeRelation=" 
           << p_schemeRelation << ")";
  switch (p_schemeRelation)
  {
    case Top:
    {
      return findConcept(p_concept, m_topConcepts);
    }
    case InScheme:
    {
      return findConcept(p_concept, m_inSchemeConcepts);
    }
  }
}

QList<SkosConcept*>::iterator SkosConceptScheme::findConcept(
  const SkosConcept &p_concept,
  QList<SkosConcept*> &p_internalConcepts)
{
  qDebug() << "SkosConceptScheme::findConcept(p_inSchemeConcept="
           << p_concept.getUrl() << ", p_internalConcepts)";
  for (QList<SkosConcept*>::iterator l_internalConceptsIter =  
         p_internalConcepts.begin(); 
       l_internalConceptsIter != p_internalConcepts.end();
       ++l_internalConceptsIter)
  {
    if ((*l_internalConceptsIter)->getUrl() == p_concept.getUrl())
    {
      return l_internalConceptsIter;
    }
  }
  return p_internalConcepts.end();
}

bool SkosConceptScheme::isConsistencyOk(const SkosConcept &p_concept)
{
  return ((findConcept(p_concept, m_inSchemeConcepts) 
           == m_inSchemeConcepts.end()) &&
          (findConcept(p_concept, m_topConcepts) 
           == m_topConcepts.end()));
}
