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
  \brief Converts spherical coordinates to Cartesian coordinates

  \param x x-coordinate
  \param y y-coordinate
  \param z z-coordinate
  \param rho radius
  \param theta inclination angle from z-axis
  \param phi azimuth angle from x-axis
 */
void spherical2cartesian(real_t* x, real_t* y, real_t* z,
    const real_t rho, const real_t theta, const real_t phi)
{
  const real_t st = sin(theta);
  const real_t sp = sin(phi);
  const real_t cp = cos(phi);
  const real_t ct = cos(theta);

  *x = rho * st * cp;
  *y = rho * st * sp;
  *z = rho * ct;
}

/*!
  \brief Converts Cartesian coordinates to spherical coordinates

  \param rho radius
  \param theta inclination angle from z-axis
  \param phi azimuth angle from x-axis
  \param x x-coordinate
  \param y y-coordinate
  \param z z-coordinate
 */
void cartesian2spherical(real_t* rho, real_t* theta, real_t* phi,
    const real_t x, const real_t y, const real_t z)
{
  *rho = sqrt(x*x + y*y + z*z);
  *theta = acos(z / *rho);
  *phi = atan2(y,x);
}

