#include "SkosConcept.hpp"

#include <QDebug>

QList<SkosConcept*>::iterator SkosConcept::findConceptInList(
  const SkosConcept &p_concept, 
  QList<SkosConcept*> &p_relationList)
{
  qDebug() << "SkosConcept::findConceptInList(p_concept="
           << p_concept.getUrl() << ", p_relationList)";
  for(QList<SkosConcept*>::iterator l_iter = p_relationList.begin();
      l_iter != p_relationList.end(); ++l_iter)
  {
    if ((*l_iter)->getUrl() == p_concept.getUrl())
    {
      return l_iter;
    }
  }
  qDebug() << "SkosConcept::findConceptInList() - concept not found";
  return p_relationList.end();
}

bool SkosConcept::isRelationAlreadyExists(const SkosConcept &p_concept)
{
  return ((findConceptInList(p_concept, m_broaderConcepts) != 
           m_broaderConcepts.end()) ||
          (findConceptInList(p_concept, m_narrowerConcepts) != 
           m_narrowerConcepts.end()) ||
          (findConceptInList(p_concept, m_relatedConcepts) != 
           m_relatedConcepts.end()));
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
        break;
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
  QList<SkosConceptScheme*> &p_internalSchemes)
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
    qDebug() << "SkosConcept::addToScheme() - concept is"
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
