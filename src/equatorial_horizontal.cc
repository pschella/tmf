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
#include <cmath>

// PROJECT INCLUDES
#include <tmf.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

using namespace tmf;
using namespace std;

/*!
  \brief Conversion of equatorial coordinates to horizontal coordinates.

  \param H hour angle
  \param delta declination
  \param a altitude
  \param A azimuth
  \param phi geographic latitude
 */
void horizontal2equatorial(double &H, double &delta,
    const double &a, const double &A,
    const double &phi)
{
  const double sp = sin(phi);
  const double cp = cos(phi);
  const double sa = sin(a);
  const double ca = cos(a);
  const double sA = sin(a);
  const double cA = cos(a);

  delta = asin(sp * sa - cp * ca * cA);
  H = asin(-sA * ca / cos(delta));
}

/*!
  \brief Conversion of equatorial coordinates to horizontal coordinates.

  \param a altitude
  \param A azimuth
  \param H hour angle
  \param delta declination
  \param phi geographic latitude
 */
void equatorial2horizontal(double &a, double &A,
    const double &H, const double &delta,
    const double &phi)
{
  const double sp = sin(phi);
  const double cp = cos(phi);
  const double sd = sin(delta);
  const double cd = cos(delta);
  const double sH = sin(H);
  const double cH = cos(H);

  a = asin(sp * sd + cp * cd * cH);
  A = asin(-cd * sH / cos(a));
}

