#ifndef SKOS_LABEL_HPP
#define SKOS_LABEL_HPP

#include <QString>

struct SkosLabel
{
  SkosLabel(QString p_value, QString p_language):
    value(p_value),
    language(p_language){};
  QString value;
  QString language;
};

#endif
