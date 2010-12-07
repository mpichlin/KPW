#include "SkosParser.hpp"
#include "SkosModel.hpp"

int main()
{
  SkosModel g_skosModel;
  SkosParser g_skosParser(&g_skosModel);
  g_skosParser.parseFile("example.tur", Soprano::SerializationTurtle);
  g_skosModel.removeConcept(QUrl("http://example.org/ns/AnotherConcept"));
  return 0;
}
