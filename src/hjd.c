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

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

/*!
  \brief Convert Julian day to the Heliocentric frame by correcting for the
  projected light travel time between the Earth and the Sun.

  \return hjd Julian day

  \param jd year
  \param alpha right ascension
  \param delta declination, positive if north of the celestial equator,
  \param utc (universal time coordinated) as Julian day
  \param ut1_utc difference UT1-UTC (as obtained from IERS bullitin A)
         if 0 a maximum error of 0.9 seconds is made.
  \param L observer's longitude (positive east, negative west
         from Greenwich)
  \param phi observer's latitude, positive if in the northern hemisphere,
         negative in the southern one
 */
double jd2hjd(const double jd, const double alpha, const double delta, const double utc, const double ut1_utc, const double L, const double phi)
{
  // Calculate Earth - Sun distance
  const double r = 1.;

  // Calculate right ascension and declination of the sun
  const double alpha_sun = 0.;
  const double delta_sun = 0.;

  return jd - (r / SPEED_OF_LIGHT) * (sin(delta) * sin(delta_sun)
      + cos(delta) * cos(delta_sun) * cos(alpha - alpha_sun));
}

