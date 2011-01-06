#ifndef E_RELATION_TYPE_HPP
#define E_RELATION_TYPE_HPP

/*! \file ERelationType.hpp
 *  \brief Zawiera definicję typu wyliczeniowego ERelationType
 *
 * Plik zawiera definicję typu wyliczeniowego ERelationType
 *
 * \author Michał Pichliński
 * \date 2010.12.11
 * \version 1.00.00
 */

/*! \brief Typy Relacji
 *
 * Typ wyliczeniowy określający typy relacji. Możliwe typy relacji to:
 * szersze, węższe, powiązane.
 */
enum ERelationType
{
  RelatedRelation  = 0,
  BroaderRelation  = 1,
  NarrowerRelation = 2
};

#endif
