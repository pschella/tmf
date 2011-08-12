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

#ifndef __TMF_SIDEREAL_TIME_H__
#define __TMF_SIDEREAL_TIME_H__

#include <tmf.h>

/*!
  \brief Get Greanwich Mean Sidereal Time (GMST) in degrees from UT1.

  Direct implementation of the method described in chapter 12 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  Coefficients converted to radians with identical numerical precission

  \return theta Greanwich Mean Sidereal Time in radians

  \param jd Julian Date of UT1
 */
real_t tmf_gmst(const real_t jd);

/*!
  \brief Get Greenwich Apparent Sidereal Time (GAST) in degrees from UT1.

  Direct implementation of the method described in chapter 12 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \return theta Greenwich Apparent Sidereal Time in radians

  \param jd Julian Date of UT1
  \param jde Julian Date of TD (or equivalently TT)
 */
real_t tmf_gast(const real_t jd, const real_t jde);

/*!
  \brief Get Local Apparent Sidereal Time (LAST) in degrees from UT1.

  Direct implementation of the method described in chapter 12 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  Modified slightly to measure longitude positive east in accordance with
  IAU convention instead of positive west.

  \return theta Local Aparrent Sidereal Time in radians

  \param jd Julian Date of UT1
  \param jde Julian Date of TD (or equivalently TT)
  \param L observer's longitude (positive east, negative west
         from Greenwich)
 */
real_t tmf_last(const real_t jd, const real_t jde, const real_t L);

#endif // __TMF_SIDEREAL_TIME_H__

