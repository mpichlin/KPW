#ifndef SKOS_COLLECTION_HPP
#define SKOS_COLLECTION_HPP

#include "SkosClass.hpp"
#include "SkosConcept.hpp"

class SkosCollection : public SkosClass
{
public:
  SkosCollection(QUrl p_url){setUrl(p_url);};
  void addConcept(SkosConcept *p_concept);
  void removeConcept(const SkosConcept &p_concept);
  void addCollection(SkosCollection *p_collection);
  void removeCollection(const SkosCollection &p_collection);
  QList<SkosConcept*> getConcepts();
  QList<SkosCollection*> getCollections();
private:
  QList<SkosConcept*>::iterator findConcept(const SkosConcept &p_concept);
  QList<SkosCollection*>::iterator findCollection(
    const SkosCollection &p_collection);

  QList<SkosConcept*>    m_memberConcepts;
  QList<SkosCollection*> m_memberCollections;
};

#endif
