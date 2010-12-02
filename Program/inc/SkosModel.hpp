#ifndef SKOS_MODEL_HPP
#define SKOS_MODEL_HPP

#include "SkosConcept.hpp"

class SkosModel
{
public:
  void addConcept(SkosConcept p_concept);
  void addPrefLabelToConcept(Soprano::Node p_prefLabel,
                             QUrl p_concept);
private:
  QList<SkosConcept> m_concepts;
};

#endif
