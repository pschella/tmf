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
  \brief Converts polar coordinates to Cartesian coordinates

  \param x x-coordinate
  \param y y-coordinate
  \param r radius
  \param theta angle with x-axis
 */
void tmf_polar_to_cartesian(real_t* x, real_t* y,
    const real_t r, const real_t theta)
{
  *x = r * cos(theta);
  *y = r * sin(theta);
}

/*!
  \brief Converts Cartesian coordinates to polar coordinates

  \param r radius
  \param theta angle with x-axis
  \param x x-coordinate
  \param y y-coordinate
 */
void tmf_cartesian_to_polar(real_t* r, real_t* theta,
    const real_t x, const real_t y)
{
  *r = sqrt(x*x + y*y);
  *theta = atan2(y, x);
}

