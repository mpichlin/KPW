#ifndef SKOS_MODEL_HPP
#define SKOS_MODEL_HPP

#include "SkosConcept.hpp"

class SkosModel
{
public:
  void addConcept(SkosConcept p_concept);
  void addPrefLabelToConcept(Soprano::Node p_prefLabel,
                             QUrl p_concept);
  void addAltLabelToConcept(Soprano::Node p_altLabel,
                             QUrl p_concept);
  void addHiddenLabelToConcept(Soprano::Node p_hiddenLabel,
                               QUrl p_concept);
  void addBroaderConcept(QUrl p_broaderConcept, QUrl p_concept); 
  void addNarrowerConcept(QUrl p_narrowerConcept, QUrl p_concept); 
  void addRelatedConcept(QUrl p_relatedConcept, QUrl p_concept); 
  QList<SkosConcept>::iterator findConcept(const QUrl &p_concept);
private:
  QList<SkosConcept> m_concepts;
};

#endif
