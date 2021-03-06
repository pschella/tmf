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

#ifndef __TMF_CARTESIAN_LOGPOLAR_H__
#define __TMF_CARTESIAN_LOGPOLAR_H__

#include <tmf.h>

/*!
  \brief Converts logpolar coordinates to Cartesian coordinates

  \param x x-coordinate
  \param y y-coordinate
  \param rho radius
  \param theta angle with x-axis
 */
void tmf_logpolar2cartesian(real_t* x, real_t* y,
    const real_t rho, const real_t theta);

/*!
  \brief Converts Cartesian coordinates to logpolar coordinates

  \param rho radius
  \param theta angle with x-axis
  \param x x-coordinate
  \param y y-coordinate
 */
void tmf_cartesian2logpolar(real_t* rho, real_t* theta,
    const real_t x, const real_t y);

#endif // __TMF_CARTESIAN_LOGPOLAR_H__

