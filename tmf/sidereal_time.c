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

// SYSTEM INCLUDES
#include <stdlib.h>
#include <math.h>

// PROJECT INCLUDES
#include <tmf.h>

real_t tmf_gmst(const real_t jd)
{
  const real_t T = (jd - 2451545.) / 36525.;

  return 4.8949612127 + 6.3003880989850 * (jd - 2451545.0) + 0.00000677071 * T * T - (T * T * T / 675616.95);
}

real_t tmf_gast(const real_t jd, const real_t jde)
{
  // Get true obliquity of the ecliptic
  const real_t epsilon = tmf_true_obliquity(jde);

  // Get nutation of the ecliptic
  const real_t Dphi = tmf_nutation(jde);

  // Get Greenwhich Mean Siderial Time and add equation of the equinoxes
  return tmf_gmst(jd) + Dphi * cos(epsilon);
}

real_t tmf_last(const real_t jd, const real_t jde, const real_t L)
{
  /* Get Greenwich Apparent Siderial Time
     and correct for observer's longitude */
  return tmf_gast(jd, jde) + L;
}

