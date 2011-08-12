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

#ifndef __TMF_ANGLES_H__
#define __TMF_ANGLES_H__

#include <tmf.h>

/*! Haversine */
real_t tmf_hav(const real_t theta);

/*! Inverse haversine */
real_t tmf_ahav(const real_t a);

/*! Convert degrees to radians */
real_t tmf_deg2rad(const real_t a);

/*! Convert radians to degrees */
real_t tmf_rad2deg(const real_t a);

/*!
  \brief Convert hours, min, sec to degrees

  \return deg degrees

  \param h degrees
  \param m minutes
  \param s seconds
 */
real_t tmf_hms2deg(const int h, const int m, const real_t s);

/*!
  \brief Convert degrees, arcmin, arcsec to degrees

  \return deg degrees

  \param d degrees
  \param am arcminutes
  \param as arcseconds
 */
real_t tmf_dms2deg(const int d, const int am, const real_t as);

/*!
  \brief Convert degrees to hours, min, sec

  Note, angles outside of the range [0, 360) are projected onto this range.

  \param h hour
  \param m minutes
  \param s seconds
  \param d degrees
 */
void tmf_deg2hms(int* h, int* m, real_t* s, const real_t d);

/*!
  \brief Convert degrees to degrees, min, sec

  \param d degrees
  \param m minutes
  \param s seconds
  \param deg degrees
 */
void tmf_deg2dms(int* d, int* m, real_t* s, real_t deg);

/*!
  \brief Convert hours, min, sec to radians

  \return rad radians

  \param h radians
  \param m minutes
  \param s seconds
 */
real_t tmf_hms2rad(const int h, const int m, const real_t s);

/*!
  \brief Convert degrees, arcmin, arcsec to radians

  \return rad radians

  \param d degrees
  \param am arcminutes
  \param as arcseconds
 */
real_t tmf_dms2rad(const int d, const int am, const real_t as);

/*!
  \brief Convert radians to hours, min, sec

  \param h hour
  \param m minutes
  \param s seconds
  \param r radians
 */
void tmf_rad2hms(int* h, int* m, real_t* s, const real_t r);

/*!
  \brief Convert radians to degrees, min, sec

  Note, angles outside of the range [0, 2*pi) are projected onto this range.

  \param d radians
  \param m minutes
  \param s seconds
  \param r radians
 */
void tmf_rad2dms(int* d, int* m, real_t* s, const real_t r);

/*!
  \brief Project an angle onto the range [0,2*pi)

  \param phi angle in radians

  \returns angle in range [0,2*pi)
 */
real_t tmf_rad2circle(const real_t phi);

/*!
  \brief Project an angle onto the range [0,360)

  \param phi angle in radians

  \returns angle in range [0,360)
 */
real_t tmf_deg2circle(const real_t phi);

#endif // __TMF_ANGLES_H__

