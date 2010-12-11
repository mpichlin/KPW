#include "SkosParser.hpp"
#include "SkosSerializer.hpp"
#include "SkosModel.hpp"

int main()
{
  SkosModel g_skosModel;
  SkosParser g_skosParser(&g_skosModel);
  g_skosParser.parseFile("example.tur", Soprano::SerializationTurtle);
/*
  g_skosModel.removeConceptScheme(QUrl("http://example.org/ns/ConceptScheme"));
  g_skosModel.removeConcept(QUrl("http://example.org/ns/AnotherConcept"));
  g_skosModel.removeLabel(Soprano::Node("Ukryty smok","pl"), 
                          HiddenLabelType,
                          QUrl("http://example.org/ns/MyConcept"));
  g_skosModel.removeLabel(Soprano::Node("Ukryty smok","pl"), 
                          HiddenLabelType,
                          QUrl("http://example.org/ns/MyConcept"));
*/
  SkosSerializer g_skosSerializer(&g_skosModel);
  g_skosSerializer.serialize(QString(), Soprano::SerializationRdfXml);
  return 0;
}
