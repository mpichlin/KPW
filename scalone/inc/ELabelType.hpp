#ifndef E_LABEL_TYPE_HPP
#define E_LABEL_TYPE_HPP

/*! \file ELabelType.hpp
 *  \brief Zawiera definicję typu wyliczeniowego ELabelType
 *
 * Plik zawiera definicję typu wyliczeniowego ELabelType
 *
 * \author Michał Pichliński
 * \date 2010.12.11
 * \version 1.00.00
 */

/*! \brief Typy Etykiet
 *
 * Typ wyliczeniowy określający typy etykiet. Możliwe typy to etykieta:
 *  preferowana, alternatywna, ukryta
 */
enum ELabelType
{
  PrefferedLabelType   = 0,
  AlternativeLabelType = 1,
  HiddenLabelType      = 2
};

#endif
