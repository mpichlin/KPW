#ifndef SKOS_CONCEPT_SCHEME_HPP
#define SKOS_CONCEPT_SCHEME_HPP

#include "SkosClass.hpp"

class SkosConceptScheme : public SkosClass
{
public:
  SkosConceptScheme(QUrl p_url){setUrl(p_url);};
};

#endif
