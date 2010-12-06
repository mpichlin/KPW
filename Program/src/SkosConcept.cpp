#include "SkosConcept.hpp"

#include <QDebug>

bool SkosConcept::isRelationAlreadyExists(const SkosConcept &p_concept)
{
  for(QList<SkosConcept*>::iterator l_iter = m_broaderConcepts.begin();
      l_iter != m_broaderConcepts.end(); ++l_iter)
  {
    if ((*l_iter)->getUrl() == p_concept.getUrl())
    {
      return true;
    }
  }
  for(QList<SkosConcept*>::iterator l_iter = m_narrowerConcepts.begin();
      l_iter != m_narrowerConcepts.end(); ++l_iter)
  {
    if ((*l_iter)->getUrl() == p_concept.getUrl())
    {
      return true;
    }
  }
  for(QList<SkosConcept*>::iterator l_iter = m_relatedConcepts.begin();
      l_iter != m_relatedConcepts.end(); ++l_iter)
  {
    if ((*l_iter)->getUrl() == p_concept.getUrl())
    {
      return true;
    }
  }
  return false;
}

int SkosConcept::addConceptRelation(SkosConcept *p_relatedConcept,
                                    const ERelationType &p_relationType)
{
  qDebug() << "SkosConcept::addConceptRelation(p_relatedConcept="
           << p_relatedConcept->getUrl() << ", p_relationType="
           << p_relationType << ")";
  if (isRelationAlreadyExists(*p_relatedConcept))
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
        m_relatedConcepts.append(p_relatedConcept);
      }    
      case BroaderRelation:
      {
        m_broaderConcepts.append(p_relatedConcept);
        break;
      }
      case NarrowerRelation:
      {
        m_narrowerConcepts.append(p_relatedConcept);
        break;
      }
    }
    return 0;
  }
}

QList<SkosConceptScheme*>::iterator SkosConcept::findInScheme(
  const SkosConceptScheme &p_conceptScheme,
  const ESchemeRelation &p_schemeRelation)
{
  switch (p_schemeRelation)
  {
    case Top:
    {
      return findInScheme(p_conceptScheme, m_topInSchemes);
      break;
    }
    case InScheme:
    {
      return findInScheme(p_conceptScheme, m_inSchemes);
      break;
    }
  }
}

QList<SkosConceptScheme*>::iterator SkosConcept::findInScheme(
  const SkosConceptScheme &p_conceptScheme,
  QList<SkosConceptScheme*> p_internalSchemes)
{
  for(QList<SkosConceptScheme*>::iterator l_internalSchemesIter =
        p_internalSchemes.begin();
      l_internalSchemesIter != p_internalSchemes.end();
      ++l_internalSchemesIter)
  {
    if ((*l_internalSchemesIter)->getUrl() == p_conceptScheme.getUrl())
    {
      return l_internalSchemesIter;
    }
  }
  return p_internalSchemes.end();
}


void SkosConcept::addToScheme(SkosConceptScheme *p_conceptScheme,
                              const ESchemeRelation &p_schemeRelation)
{
  qDebug() << "SkosConcept::addToScheme(p_conceptScheme="
           << p_conceptScheme->getUrl() << ", p_schemeRelation="
           << p_schemeRelation << ")";
  if ((findInScheme(*p_conceptScheme, m_topInSchemes) != m_topInSchemes.end()) 
      ||
      (findInScheme(*p_conceptScheme, m_inSchemes) != m_inSchemes.end()))
  {
    qDebug() << "SkosConcept::addAsTopInScheme() - concept is"
             << "already in this scheme";
  }
  else
  {
    switch (p_schemeRelation)
    {
      case Top:
      {
        m_topInSchemes.append(p_conceptScheme);
        break;
      }
      case InScheme:
      {
        m_inSchemes.append(p_conceptScheme);
        break;
      }
    }
  }
}
