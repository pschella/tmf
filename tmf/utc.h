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

#ifndef __TMF_UTC_H__
#define __TMF_UTC_H__

#include <tmf.h>

/*!
  \brief Calculate TAI - UTC in seconds

  For dates before July 1 1972 a fixed value of 10s will be returned.

  \todo Update this routine whenever a leap second is inserted.

  \param utc Universal Time Coordinated as Julian day

  \return TAI - UTC in seconds
 */
int tmf_delta_tai_utc(const real_t utc);

/*!
  \brief Calculate TT - UTC in seconds

  For dates before July 1 1972 a fixed value of 10s + TT - TAI is returned.

  \param utc Universal Time Coordinated as Julian day

  \return TT - UTC in seconds
 */
real_t tmf_delta_tt_utc(const real_t utc);

#endif // __TMF_UTC_H__

