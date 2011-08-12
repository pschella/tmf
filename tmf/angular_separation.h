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

#ifndef __TMF_ANGULAR_SEPARATION_H__
#define __TMF_ANGULAR_SEPARATION_H__

#include <tmf.h>

/*!
  \brief Calculate angular separation

  \return angular separation in radians

  \param lon_1 longitude of point 1 in radians
  \param lat_1 latitude of point 1 in radians
  \param lon_2 longitude of point 2 in radians
  \param lat_2 latitude of point 2 in radians
 */
real_t tmf_angular_separation(const real_t lon_1, const real_t lat_1, const real_t lon_2, const real_t lat_2);

#endif // __TMF_ANGULAR_SEPARATION_H__

