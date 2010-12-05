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
