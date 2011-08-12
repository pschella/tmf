/**************************************************************************
 *  This file is part of the Transmogrify library.                        *
 *  Copyright (C) 2010 Pim Schellart <P.Schellart@astro.ru.nl>            *
 *                                                                        *
 *  This library is free software: you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation, either version 3 of the License, or     *
 *  (at your option) any later version.                                   *
 *                                                                        * 
 *  This library is distributed in the hope that it will be useful,       *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU General Public License for more details.                          *
 *                                                                        *
 *  You should have received a copy of the GNU General Public License     *
 *  along with this library. If not, see <http://www.gnu.org/licenses/>.  *
 **************************************************************************/

#ifndef __TMF_EQUATORIAL_GALACTIC_H__
#define __TMF_EQUATORIAL_GALACTIC_H__

#include <tmf.h>

/*!
  \brief Conversion of equatorial coordinates to galactic coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param l galactic longitude in radians
  \param b galactic latitutde in radians
  \param alpha right ascension in radians (B1950.0 equinox)
  \param delta declination in radians (B1950.0 equinox)
 */
void tmf_equatorial2galactic(real_t* l, real_t* b,
    const real_t alpha, const real_t delta);

/*!
  \brief Conversion of galactic coordinates to equatorial coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param alpha right ascension in radians (B1950.0 equinox)
  \param delta declination in radians (B1950.0 equinox)
  \param l galactic longitude in radians
  \param b galactic latitutde in radians
 */
void tmf_galactic2equatorial(real_t* alpha, real_t* delta,
    const real_t l, const real_t b);

#endif // __TMF_EQUATORIAL_GALACTIC_H__

