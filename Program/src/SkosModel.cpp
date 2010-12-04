#include "SkosModel.hpp"

#include <QDebug>

void SkosModel::addConcept(SkosConcept p_concept)
{
  qDebug() << "SkosModel::addConcept(p_concept =" << p_concept.getUrl() << ")";
  bool l_ifConceptAlreadyExists = false;
  if (findConcept(p_concept.getUrl()) == m_concepts.end())
  {
    m_concepts.append(p_concept);
  }
  else
  {
    qDebug() << "SkosModel::addConcept() - Concept already exists";
  }
}

void SkosModel::addPrefLabelToConcept(Soprano::Node p_prefLabel,
                                      QUrl p_concept)
{
  qDebug() << "SkosModel::addPrefLabelToConcept(p_prefLabel=" <<
    p_prefLabel.toString() << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_iter = findConcept(p_concept);
  if (l_iter == m_concepts.end())
  {
    qDebug() << "SkosModel::addPrefLabelToConcept() - Concept does not exists";
  }
  else
  {
    l_iter->addPrefLabel(p_prefLabel);
  }
}

void SkosModel::addAltLabelToConcept(Soprano::Node p_altLabel,
                                     QUrl p_concept)
{
  qDebug() << "SkosModel::addAltLabelToConcept(p_altLabel=" <<
    p_altLabel.toString() << ", p_concept=" << p_concept << ")";
  QList<SkosConcept>::iterator l_iter = findConcept(p_concept);
  if (l_iter == m_concepts.end())
  {
    qDebug() << "SkosModel::addAltLabelToConcept() - Concept does not exists";
  }
  else
  {
      l_iter->addAltLabel(p_altLabel);
  }

}

QList<SkosConcept>::iterator SkosModel::findConcept(
  const QUrl &p_concept)
{
  for (QList<SkosConcept>::iterator l_iter = m_concepts.begin();
       l_iter != m_concepts.end(); ++l_iter)
  {
    if (l_iter->getUrl() == p_concept)
    {
      return l_iter;
    }
  }
  return m_concepts.end();
}
