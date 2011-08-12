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
#include <math.h>

// PROJECT INCLUDES
#include <tmf.h>

real_t tmf_jd2hjd(const real_t jd, const real_t alpha, const real_t delta, const real_t utc, const real_t ut1_utc, const real_t L, const real_t phi)
{
  // Calculate Earth - Sun distance
  const real_t r = 1.;

  // Calculate right ascension and declination of the sun
  const real_t alpha_sun = 0.;
  const real_t delta_sun = 0.;

  return jd - (r / SPEED_OF_LIGHT) * (sin(delta) * sin(delta_sun)
      + cos(delta) * cos(delta_sun) * cos(alpha - alpha_sun));
}

