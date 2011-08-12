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

#ifndef __TMF_ITRF_LOCAL_H__
#define __TMF_ITRF_LOCAL_H__

#include <tmf.h>

/*!
  \brief Convert coordinates from ITRF to local Cartesian.

  \param E easterly
  \param N northerly
  \param U upper
  \param x ITRF x
  \param y ITRF y
  \param z ITRF z
  \param ref_x reference x position in ITRF
  \param ref_y reference y position in ITRF
  \param ref_z reference z position in ITRF
  \param ref_lon reference longitude in radians
  \param ref_lat reference latitude in radians
 */
void tmf_itrf2local(real_t* E, real_t* N, real_t* U,
    const real_t x, const real_t y, const real_t z,
    const real_t ref_x, const real_t ref_y, const real_t ref_z,
    const real_t ref_lon, const real_t ref_lat);

#endif // __TMF_ITRF_LOCAL_H__

