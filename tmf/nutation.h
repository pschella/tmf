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

#ifndef __TMF_NUTATION_H__
#define __TMF_NUTATION_H__

#include <tmf.h>

/*!
  \brief Get Nutation and Obliquity of the Ecliptic at given instant

  The nutation is due to the action of the Moon and can be described as
  a sum of periodic terms.
  Nutation is partioned into a component parallel to and one perpendicular
  to the ecliptic.
  The component allong the ecliptic is called the ``nutation in longitude''
  and affects the celestial longitude of all heavenly bodies.
  The component perpendicular to the ecliptic is called the ``nutation of
  obliquity'' and affects the obliquity of the equator to the ecliptic,
  it does not affect the longitude of heavenly bodies.

  Direct implementation of the method described in chapter 22 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param jde Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
         equivalently Terrestrial Time (TT))
 */
real_t tmf_nutation(const real_t jde);

/*!
  \brief Get Obliquity of the Ecliptic at given instant

  The nutation is due to the action of the Moon and can be described as
  a sum of periodic terms.
  Nutation is partioned into a component parallel to and one perpendicular
  to the ecliptic.
  The component allong the ecliptic is called the ``nutation in longitude''
  and affects the celestial longitude of all heavenly bodies.
  The component perpendicular to the ecliptic is called the ``nutation of
  obliquity'' and affects the obliquity of the equator to the ecliptic,
  it does not affect the longitude of heavenly bodies.

  Direct implementation of the method described in chapter 22 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param jde Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
         equivalently Terrestrial Time (TT))
 */
real_t tmf_obliquity(const real_t jde);

/*!
  \brief Get mean obliquity of the ecliptic

  Direct implementation of the method described in chapter 22 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \return epsilon_0 mean obliquity of the ecliptic in radians

  \param jde Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
         equivalently Terrestrial Time (TT))
 */
real_t tmf_mean_obliquity(const real_t jde);

/*!
  \brief Get true obliquity of the ecliptic

  Direct implementation of the method described in chapter 22 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \return epsilon true obliquity of the ecliptic in radians

  \param jde Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
         equivalently Terrestrial Time (TT))
 */
real_t tmf_true_obliquity(const real_t jde);

#endif // __TMF_NUTATION_H__

