#include "SkosModel.hpp"

#include <QDebug>

void SkosModel::addConcept(SkosConcept p_concept)
{
  qDebug() << "SkosModel::addConcept(p_concept" << p_concept.getUrl() << ")";
  m_concepts.append(p_concept);
}

void SkosModel::addPrefLabelToConcept(Soprano::Node p_prefLabel,
                                      QUrl p_concept)
{
  qDebug() << "SkosModel::addPrefLabelToConcept(p_prefLabel=" <<
    p_prefLabel.toString() << ", p_concept=" << p_concept << ")";
  for (QList<SkosConcept>::iterator l_iter = m_concepts.begin();
       l_iter != m_concepts.end(); ++l_iter)
  {
    if (l_iter->getUrl() == p_concept)
    {
      l_iter->addPrefLabel(p_prefLabel);
    }
  }
}
