#ifndef SKOS_MODEL_HPP
#define SKOS_MODEL_HPP

#include "SkosConcept.hpp"
#include "SkosConceptScheme.hpp"

class SkosModel
{
public:
  void addConcept(SkosConcept p_concept);
  void addConceptScheme(SkosConceptScheme p_conceptScheme);
  void addPrefLabel(Soprano::Node p_prefLabel,
                    QUrl p_skosClass);
  void addAltLabel(Soprano::Node p_altLabel,
                             QUrl p_skosClass);
  void addHiddenLabel(Soprano::Node p_hiddenLabel,
                               QUrl p_skosClass);
  void addBroaderConcept(QUrl p_broaderConcept, QUrl p_concept); 
  void addNarrowerConcept(QUrl p_narrowerConcept, QUrl p_concept); 
  void addRelatedConcept(QUrl p_relatedConcept, QUrl p_concept); 
  QList<SkosConcept>::iterator findConcept(const QUrl &p_concept);
  QList<SkosConceptScheme>::iterator findConceptScheme(
    const QUrl &p_conceptScheme);
  SkosClass * findSkosClass(const QUrl &p_skosClass);
private:
  bool isConsistencyOk(const SkosClass &p_skosClass);

  QList<SkosConcept> m_concepts;
  QList<SkosConceptScheme> m_conceptSchemes;
};

#endif
