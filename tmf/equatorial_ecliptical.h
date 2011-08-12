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

#ifndef __TMF_EQUATORIAL_ECLIPTICAL_H__
#define __TMF_EQUATORIAL_ECLIPTICAL_H__

#include <tmf.h>

/*!
  \brief Conversion of equatorial coordinates to ecliptical coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param lambda ecliptical (or celestial) longitude, measured from the
         vernal equinox along the ecliptic in radians
  \param beta ecliptical (or celestial) latitude, positive if north of the
         ecliptic, negative if south in radians
  \param alpha right ascension in radians (B1950.0 equinox)
  \param delta declination in radians (B1950.0 equinox)
  \param jde Julian Date of TD (or equivalently TT)
 */
void tmf_equatorial2ecliptic(real_t* lambda, real_t* beta,
    const real_t alpha, const real_t delta,
    const real_t jde);

/*!
  \brief Conversion of ecliptical coordinates to equatorial coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param alpha right ascension in radians (B1950.0 equinox)
  \param delta declination in radians (B1950.0 equinox)
  \param lambda ecliptical (or celestial) longitude, measured from the
         vernal equinox along the ecliptic in radians
  \param beta ecliptical (or celestial) latitude, positive if north of the
         ecliptic, negative if south in radians
  \param jde Julian Date of TD (or equivalently TT)
 */
void tmf_ecliptic2equatorial(real_t* alpha, real_t* delta,
    const real_t lambda, const real_t beta,
    const real_t jde);

#endif // __TMF_EQUATORIAL_ECLIPTICAL_H__

