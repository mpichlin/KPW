#ifndef E_SCHEME_RELATION_HPP
#define E_SCHEME_RELATION_HPP

/*! \file ESchemeRelation.hpp
 *  \brief Zawiera definicję typu wyliczeniowego ESchemeRelation
 *
 * Plik zawiera definicję typu wyliczeniowego ESchemeRelation
 *
 * \author Michał Pichliński
 * \date 2010.12.11
 * \version 1.00.00
 */

/*! \brief Typy relacji koncept - schemat
 *
 * Typ wyliczeniowy określający typy relacji koncept - schemat. Możliwe typy to:
 * najwyższy w schemacie, w schemacie
 */
enum ESchemeRelation
{
  Top      = 0,
  InScheme = 1
};

#endif
