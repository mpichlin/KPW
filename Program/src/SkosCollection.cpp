#include "SkosCollection.hpp"

#include <QDebug>

void SkosCollection::addConcept(SkosConcept *p_concept)
{
  if (findConcept(*p_concept) == m_memberConcepts.end())
  {
    m_memberConcepts.append(p_concept);
  }
  else
  {
    qDebug() << "SkosCollection::addConcept() - concept already added";
  }
}

void SkosCollection::removeConcept(const SkosConcept &p_concept)
{
  QList<SkosConcept*>::iterator l_conceptToRemove = findConcept(p_concept);
  if (l_conceptToRemove != m_memberConcepts.end())
  {
    m_memberConcepts.erase(l_conceptToRemove);
  }
  else
  {
    qDebug() << "SkosCollection::removeConcept() - no such concept";
  }
}

void SkosCollection::addCollection(SkosCollection *p_collection)
{
  if (findCollection(*p_collection) == m_memberCollections.end())
  {
    m_memberCollections.append(p_collection);
  }
  else
  {
    qDebug() << "SkosCollection::addCollection() - collection already added";
  }
}

void SkosCollection::removeCollection(const SkosCollection &p_collection)
{
  QList<SkosCollection*>::iterator l_collectionToRemove = 
    findCollection(p_collection);
  if (l_collectionToRemove != m_memberCollections.end())
  {
    m_memberCollections.erase(l_collectionToRemove);
  }
  else
  {
    qDebug() << "SkosCollection::removeCollection() - no such collection";
  }
}

QList<SkosConcept*>::iterator  SkosCollection::findConcept(
    const SkosConcept &p_concept)
{
  for (QList<SkosConcept*>::iterator l_iter = m_memberConcepts.begin();
       l_iter != m_memberConcepts.end();
       ++l_iter)
  {
    if (p_concept.getUrl() == (*l_iter)->getUrl())
    {
      return l_iter;
    }
  }
  return m_memberConcepts.end();
}

QList<SkosCollection*>::iterator SkosCollection::findCollection(
  const SkosCollection &p_collection)
{
  for (QList<SkosCollection*>::iterator l_iter = m_memberCollections.begin();
       l_iter != m_memberCollections.end();
       ++l_iter)
  {
    if (p_collection.getUrl() == (*l_iter)->getUrl())
    {
      return l_iter;
    }
  }
  return m_memberCollections.end();
}

QList<SkosConcept*> SkosCollection::getConcepts()
{
  return m_memberConcepts;
}

QList<SkosCollection*> SkosCollection::getCollections()
{
  return m_memberCollections;
}
