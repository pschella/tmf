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

#ifndef __TMF_EPOCH_H__
#define __TMF_EPOCH_H__

#include <tmf.h>

/*!
  \brief Convert equatorial coordinates from epoch J2000 to B1950

  Rotation matrix derived from equation 14.55 and the problem 14.6 in
  Spherical Astronomy by Robin M. Green
  Cambridge University Press 1985
  ISBN 0-521-31779-7

  \param alpha_B right ascension reffered to the B1950 standard epoch
  \param delta_B declination reffered to the B1950 standard epoch
  \param alpha_J right ascension reffered to the J2000 standard epoch
  \param delta_J declination reffered to the J2000 standard epoch
 */
void tmf_j20002b1950(real_t* alpha_B, real_t* delta_B,
    const real_t alpha_J, const real_t delta_J);

/*!
  \brief Convert equatorial coordinates from epoch B1950 to J2000

  Rotation matrix derived from equation 14.55 and the problem 14.6 in
  Spherical Astronomy by Robin M. Green
  Cambridge University Press 1985
  ISBN 0-521-31779-7

  \param alpha_J right ascension reffered to the J2000 standard epoch
  \param delta_J declination reffered to the J2000 standard epoch
  \param alpha_B right ascension reffered to the B1950 standard epoch
  \param delta_B declination reffered to the B1950 standard epoch
 */
void tmf_b19502j2000(real_t* alpha_J, real_t* delta_J,
    const real_t alpha_B, const real_t delta_B);

#endif // __TMF_EPOCH_H__

