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

#ifndef __TMF_JD_DATE_H__
#define __TMF_JD_DATE_H__

#include <tmf.h>

/*! Convert Julian day to modified Julian day. */
real_t tmf_jd2mjd(const real_t jd);

/*! Convert modified Julian day to Julian day. */
real_t tmf_mjd2jd(const real_t mjd);

/*!
  \brief Convert date in Gregorian calendar to Julian day.

  \return jd Julian day

  \param y year
  \param m month
  \param d day (with fraction)
 */
real_t tmf_gregorian2jd(const int y, const int m, const real_t d);

/*!
  \brief Convert date in Julian calendar to Julian day.

  \return jd Julian day

  \param y year
  \param m month
  \param d day (with fraction)
 */
real_t tmf_julian2jd(const int y, const int m, const real_t d);

/*!
  \brief Convert date in Gregorian or Julian calendar to Julian day.

  \return jd Julian day

  \param y year
  \param m month
  \param d day (with fraction)
 */
real_t tmf_date2jd(const int y, const int m, const real_t d);

/*!
  \brief Convert Julian day to calendar date.

  \param y year
  \param m month
  \param d day (with fraction)
  \param jd Julian day
 */
void tmf_jd2date(int* y, int* m, real_t* d, const real_t jd);

#endif // __TMF_JD_DATE_H__

