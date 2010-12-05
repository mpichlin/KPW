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

QList<SkosConceptScheme*>::iterator SkosConcept::findConceptAsTopInScheme(
  const SkosConceptScheme &p_conceptScheme)
{
  for(QList<SkosConceptScheme*>::iterator l_topInSchemesIter =
        m_topInSchemes.begin();
      l_topInSchemesIter != m_topInSchemes.end();
      ++l_topInSchemesIter)
  {
    if ((*l_topInSchemesIter)->getUrl() == p_conceptScheme.getUrl())
    {
      return l_topInSchemesIter;
    }
  }
  return m_topInSchemes.end();
}

void SkosConcept::addAsTopInScheme(SkosConceptScheme *p_conceptScheme)
{
  qDebug() << "SkosConcept::addAsTopInScheme(p_conceptScheme="
           << p_conceptScheme->getUrl() << ")";
  QList<SkosConceptScheme*>::iterator l_topInSchemesIter =
    findConceptAsTopInScheme(*p_conceptScheme);
  if (l_topInSchemesIter == m_topInSchemes.end())
  {
    m_topInSchemes.append(p_conceptScheme);
  }
  else
  {
    qDebug() << "SkosConcept::addAsTopInScheme() - concept is"
             << "already in scheme";
  }
}
