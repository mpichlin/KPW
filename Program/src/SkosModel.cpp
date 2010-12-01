#include "SkosModel.hpp"

#include <QDebug>

void SkosModel::addConcept(SkosConcept p_concept)
{
  qDebug() << "SkosModel::addConcept(p_concept" << p_concept.getUrl() << ")";
  m_concepts.append(p_concept);
}
