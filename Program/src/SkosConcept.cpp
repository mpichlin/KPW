#include "SkosConcept.hpp"

#include <QDebug>

QUrl SkosConcept::getUrl() const
{
  return m_url;
}

bool SkosConcept::isLabelAlreadyExists(const Soprano::Node &p_label) const
{
  qDebug() << "SkosConcept::isLabelAlreadyExists(p_label="
           << p_label.toString() << ")";
  for (QList<Soprano::Node>::const_iterator l_iter = m_prefLabels.begin();
       l_iter != m_prefLabels.end(); ++l_iter)
  {
    if (*l_iter == p_label)
    {
      return true;
    }
  }
  for (QList<Soprano::Node>::const_iterator l_iter = m_altLabels.begin();
       l_iter != m_altLabels.end(); ++l_iter)
  {
    if (*l_iter == p_label)
    {
      return true;
    }
  }
  for (QList<Soprano::Node>::const_iterator l_iter = m_hiddenLabels.begin();
       l_iter != m_hiddenLabels.end(); ++l_iter)
  {
    if (*l_iter == p_label)
    {
      return true;
    }
  }
  return false;
}

bool SkosConcept::isPrefLabelOk(const Soprano::Node &p_prefLabel) const
{
  qDebug() << "SkosConcept::isPrefLabelOk(p_prefLabel="
           << p_prefLabel.toString() << ")";
  if(isLabelAlreadyExists(p_prefLabel))
  {
    qDebug() << "SkosConcept::isPrefLabelOk() - label already exists";
  }
  for(QList<Soprano::Node>::const_iterator l_iter = m_prefLabels.begin();
      l_iter != m_prefLabels.end(); ++l_iter)
  {
    if (l_iter->language() == p_prefLabel.language())
    {
      qDebug() << "SkosConcept::isPrefLabelOk() - prefered label in this"
               << "language already exists";
      return false;
    }
  }
  return true;
}

void SkosConcept::addPrefLabel(Soprano::Node p_prefLabel)
{
  qDebug() << "SkosConcept::addPrefLabel(p_prefLabel="
           << p_prefLabel.toString() << ")";
  if (isPrefLabelOk(p_prefLabel))
  {
    m_prefLabels.append(p_prefLabel);
  }
}

void SkosConcept::addAltLabel(Soprano::Node p_altLabel)
{
  qDebug() << "SkosConcept::addAltLabel(p_altLabel="
           << p_altLabel.toString() << ")";
  if (isLabelAlreadyExists(p_altLabel))
  {
    qDebug() << "SkosConcept::addAltLabel() - label already exists";
  }
  {
    m_altLabels.append(p_altLabel);
  }
}

void SkosConcept::addHiddenLabel(Soprano::Node p_hiddenLabel)
{
  qDebug() << "SkosConcept::addHiddenLabel(p_hiddenLabel="
           << p_hiddenLabel.toString() << ")";
  if (isLabelAlreadyExists(p_hiddenLabel))
  {
    qDebug() << "SkosConcept::addHiddenLabel() - label already exists";
  }
  {
    m_hiddenLabels.append(p_hiddenLabel);
  }
}

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
