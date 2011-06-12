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
#include <stdlib.h>
#include <math.h>

// PROJECT INCLUDES
#include <tmf.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

/*!
  \brief Conversion of equatorial coordinates to horizontal coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  Modified slightly to calculate azimuth westward from north instead of
  south.

  \param A azimuth, measured westward from the north
  \param h altitude, positive above the horizon, negative below
  \param H hour angle (e.g. last - alpha where alpha is the right ascension
         and last the local apparent siderial time)
  \param delta declination, positive if north of the celestial equator,
         negative if south
  \param phi observer's latitude, positive if in the northern hemisphere,
         negative in the southern one
 */
void tmf_equatorial2horizontal(real_t* A, real_t* h,
    const real_t H, const real_t delta, const real_t phi)
{
  const real_t sH = sin(H);
  const real_t cH = cos(H);
  const real_t sd = sin(delta);
  const real_t cd = cos(delta);
  const real_t td = tan(delta);
  const real_t sp = sin(phi);
  const real_t cp = cos(phi);

  *A = atan2(sH, (cH * sp - td * cp)) - M_PI;

  *h = asin(sp * sd + cp * cd * cH);
}

/*!
  \brief Conversion of equatorial coordinates to horizontal coordinates.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  Modified slightly to calculate azimuth westward from north instead of
  south.

  \param H hour angle (e.g. last - alpha where alpha is the right ascension
         and last the local apparent siderial time)
  \param delta declination, positive if north of the celestial equator,
         negative if south
  \param A azimuth, measured westward from the north
  \param h altitude, positive above the horizon, negative below
  \param phi observer's latitude, positive if in the northern hemisphere,
         negative in the southern one
 */
void tmf_horizontal2equatorial(real_t* H, real_t* delta,
    const real_t A, const real_t h, const real_t phi)
{
  const real_t sA = sin(A-M_PI);
  const real_t cA = cos(A-M_PI);
  const real_t sp = sin(phi);
  const real_t cp = cos(phi);
  const real_t sh = sin(h);
  const real_t ch = cos(h);
  const real_t th = tan(h);

  *H = atan2(sA, (cA * sp + th * cp));

  *delta = asin(sp * sh - cp * ch * cA);
}

/*!
  \brief Convenience function for conversion of equatorial coordinates to horizontal coordinates.

  Use this function for quick and easy conversion of a few coordinates.
  For many conversions sharing the same time and location please use the
  sub functions to avoid unnessesary calculations.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  Modified slightly to calculate azimuth westward from north instead of
  south.

  \param A azimuth, measured westward from the north
  \param h altitude, positive above the horizon, negative below
  \param alpha right ascension
  \param delta declination, positive if north of the celestial equator,
         negative if south
  \param utc (universal time coordinated) as Julian day
  \param ut1_utc difference UT1-UTC (as obtained from IERS bullitin A)
         if 0 a maximum error of 0.9 seconds is made.
  \param L observer's longitude (positive east, negative west
         from Greenwich)
  \param phi observer's latitude, positive if in the northern hemisphere,
         negative in the southern one
 */
void tmf_radec2azel(real_t* A, real_t* h, const real_t alpha, const real_t delta, const real_t utc, const real_t ut1_utc, const real_t L, const real_t phi)
{
  // Calculate Terestrial Time (TT)
  const real_t tt = utc + tmf_delta_tt_utc(utc) / SECONDS_PER_DAY;

  // Calculate Universal Time (UT1)
  const real_t ut1 = utc + ut1_utc / SECONDS_PER_DAY;

  // Calculate Local Apparant Sidereal Time (LAST)
  const real_t theta_L = tmf_last(ut1, tt, L);

  // Calculate hour angle
  const real_t H = tmf_rad2circle(theta_L - alpha);

  // Convert from equatorial to horizontal coordinates
  tmf_equatorial2horizontal(A, h, H, delta, phi);
}

/*!
  \brief Convenience function for conversion of horizontal coordinates to equatorial coordinates.

  Use this function for quick and easy conversion of a few coordinates.
  For many conversions sharing the same time and location please use the
  sub functions to avoid unnessesary calculations.

  Direct implementation of the method described in chapter 13 of
  Astronomical Algorithms by Jean Meeus, second edition, 2005
  Published by: Willman-Bell Inc.
  ISBN 0-943396-61-1

  Modified slightly to calculate azimuth westward from north instead of
  south.

  \param alpha right ascension
  \param delta declination, positive if north of the celestial equator,
         negative if south
  \param A azimuth, measured westward from the north
  \param h altitude, positive above the horizon, negative below
  \param utc (universal time coordinated) as Julian day
  \param ut1_utc difference UT1-UTC (as obtained from IERS bullitin A)
         if 0 a maximum error of 0.9 seconds is made.
  \param L observer's longitude (positive east, negative west
         from Greenwich)
  \param phi observer's latitude, positive if in the northern hemisphere,
         negative in the southern one
 */
void tmf_azel2radec(real_t* alpha, real_t* delta, const real_t A, const real_t h, const real_t utc, const real_t ut1_utc, const real_t L, const real_t phi)
{
  // Variables
  real_t H = 0; 

  // Calculate Terestrial Time (TT)
  const real_t tt = utc + tmf_delta_tt_utc(utc) / SECONDS_PER_DAY;

  // Calculate Universal Time (UT1)
  const real_t ut1 = utc + ut1_utc / SECONDS_PER_DAY;

  // Calculate Local Apparant Sidereal Time (LAST)
  const real_t theta_L = tmf_last(ut1, tt, L);

  // Convert from equatorial to horizontal coordinates
  tmf_horizontal2equatorial(&H, delta, A, h, phi);

  // Calculate right ascention
  *alpha = tmf_rad2circle(theta_L - H);
}

