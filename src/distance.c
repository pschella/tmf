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
  \brief Calculate angular distance `d' between two celestial bodies.

  The coordinates of the two objects can be given in the equatorial or
  ecliptical coordinate systems.
  Note however that all coordinates need to be in the same coordinate
  system.

  The angular distance is calculated using equations due to Mr Thierry
  Pauwels of the Royal Observatory of Belgium as given in:

  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \return deg degrees

  \param a1 either right ascension (alpha) or ecliptical longitude (lambda)
            of first object in radians
  \param d1 either declination (delta) or ecliptical latitude (beta) of
            first object in radians
  \param a2 either right ascension (alpha) or ecliptical longitude (lambda)
            of second object in radians
  \param d2 either declination (delta) or ecliptical latitude (beta) of
            second object in radians
 */
double angularseparation(const double a1, const double d1, const double a2, const double d2)
{
  const double cd1 = cos(d1);
  const double sd1 = sin(d1);
  const double cd2 = cos(d2);
  const double sd2 = sin(d2);
  const double c21 = cos(a2 - a1);
  const double s21 = sin(a2 - a1);

  const double x = cd1 * sd2 - sd1 * cd2 * c21;
  const double y = cd2 * s21;
  const double z = sd1 * sd2 + cd1 * cd2 * c21;

  return atan2(sqrt(x*x + y*y), z);
}

