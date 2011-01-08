#include "SkosCollection.hpp"

#include <QDebug>

void SkosCollection::addConcept(const SkosConcept &p_concept)
{
  if (!hasConcept(p_concept))
  {
    m_memberConcepts.append(p_concept.getUrl());
  }
  else
  {
    qDebug() << "SkosCollection::addConcept() - concept already added";
  }
}

void SkosCollection::removeConcept(const SkosConcept &p_concept)
{
  QList<QUrl>::iterator l_conceptToRemove;
  for (l_conceptToRemove = m_memberConcepts.begin();
       l_conceptToRemove != m_memberConcepts.end(); ++l_conceptToRemove)
  {
    if (*l_conceptToRemove == p_concept.getUrl())
    {
      break;
    }
  }
  if (l_conceptToRemove != m_memberConcepts.end())
  {
    m_memberConcepts.erase(l_conceptToRemove);
  }
  else
  {
    qDebug() << "SkosCollection::removeConcept() - no such concept";
  }
}

void SkosCollection::addCollection(const SkosCollection &p_collection)
{
  if (!hasCollection(p_collection))
  {
    m_memberCollections.append(p_collection.getUrl());
  }
  else
  {
    qDebug() << "SkosCollection::addCollection() - collection already added";
  }
}

void SkosCollection::removeCollection(const SkosCollection &p_collection)
{
  QList<QUrl>::iterator l_collectionToRemove;
  for (l_collectionToRemove = m_memberCollections.begin();
       l_collectionToRemove != m_memberCollections.end();
       ++l_collectionToRemove)
  {
    if (*l_collectionToRemove == p_collection.getUrl())
    {
      break;
    }
  }
  if (l_collectionToRemove != m_memberCollections.end())
  {
    m_memberCollections.erase(l_collectionToRemove);
  }
  else
  {
    qDebug() << "SkosCollection::removeCollection() - no such collection";
  }
}

bool  SkosCollection::hasConcept(const SkosConcept &p_concept)
{
  for (QList<QUrl>::iterator l_iter = m_memberConcepts.begin();
       l_iter != m_memberConcepts.end();
       ++l_iter)
  {
    if (p_concept.getUrl() == *l_iter)
    {
      return true;
    }
  }
  return false;
}

bool SkosCollection::hasCollection(
  const SkosCollection &p_collection)
{
  for (QList<QUrl>::iterator l_iter = m_memberCollections.begin();
       l_iter != m_memberCollections.end();
       ++l_iter)
  {
    if (p_collection.getUrl() == *l_iter)
    {
      return true;
    }
  }
  return false;
}

QList<QUrl> SkosCollection::getConcepts()
{
  return m_memberConcepts;
}

QList<QUrl> SkosCollection::getCollections()
{
  return m_memberCollections;
}
