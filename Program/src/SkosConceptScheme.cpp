#include "SkosConceptScheme.hpp"

#include <QDebug>

void SkosConceptScheme::addTopConcept(SkosConcept *p_topConcept)
{
  QList<SkosConcept*>::iterator l_topConceptsIter = 
    findTopConcept(*p_topConcept);
  if (l_topConceptsIter == m_topConcepts.end())
  {
    m_topConcepts.append(p_topConcept);
  }
  else
  {
    qDebug() << "SkosConceptScheme::addTopConcept() - Concept already exists";
  }
}

QList<SkosConcept*>::iterator SkosConceptScheme::findTopConcept(
  const SkosConcept& p_topConcept)
{
  for (QList<SkosConcept*>::iterator l_topConceptsIter =  
         m_topConcepts.begin(); 
       l_topConceptsIter != m_topConcepts.end();
       ++l_topConceptsIter)
  {
    if ((*l_topConceptsIter)->getUrl() == p_topConcept.getUrl())
    {
      return l_topConceptsIter;
    }
  }
  return m_topConcepts.end();
}
