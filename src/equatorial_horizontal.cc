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

using namespace std;

/*!
  \brief Conversion of equatorial coordinates to horizontal coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param A azimuth, measured westward from the south
  \param h altitude, positive above the horizon, negative below
  \param H hour angle (e.g. last - alpha where alpha is the right ascension
         and last the local apparent siderial time)
  \param delta declination, positive if north of the celestial equator,
         negative if south
  \param observer's latitude, positive if in the northern hemisphere,
         negative in the southern one
 */
void tmf::equatorial2horizontal(double& A, double& h,
    const double& H, const double& delta, const double& phi)
{
  const double sH = sin(H);
  const double cH = cos(H);
  const double sd = sin(delta);
  const double cd = cos(delta);
  const double td = tan(delta);
  const double sp = sin(phi);
  const double cp = cos(phi);

  A = atan(sH / (cH * sp - td * cp));

  h = asin(sp * sd + cp * cd * cH);
}

/*!
  \brief Conversion of equatorial coordinates to horizontal coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  \param H hour angle (e.g. last - alpha where alpha is the right ascension
         and last the local apparent siderial time)
  \param delta declination, positive if north of the celestial equator,
         negative if south
  \param A azimuth, measured westward from the south
  \param h altitude, positive above the horizon, negative below
  \param observer's latitude, positive if in the northern hemisphere,
         negative in the southern one
 */
void tmf::horizontal2equatorial(double& H, double& delta,
    const double& A, const double& h, const double& phi)
{
  const double sA = sin(A);
  const double cA = cos(A);
  const double sp = sin(phi);
  const double cp = cos(phi);
  const double sh = sin(h);
  const double ch = cos(h);
  const double th = tan(h);

  H = atan(sA / (cA * sp + th * cp));

  delta = asin(sp * sh - cp * ch * cA);
}

