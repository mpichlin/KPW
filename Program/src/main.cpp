#include "SkosParser.hpp"
#include "SkosModel.hpp"

int main()
{
  SkosModel g_skosModel;
  SkosParser g_skosParser(&g_skosModel);
  g_skosParser.parseFile("example.tur");
  return 0;
}
