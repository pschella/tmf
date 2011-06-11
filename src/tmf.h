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

#ifndef __TMF_H__
#define __TMF_H__

// SYSTEM INCLUDES
#include <math.h>

// PROJECT INCLUDES
#include <tmf_config.h>
#include <constants.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

/* angles.c */
real_t deg2rad(real_t a);

real_t rad2deg(real_t a);

real_t jd2mjd(real_t jd);

real_t mjd2jd(real_t mjd);

real_t hms2deg(int h, int m, real_t s);

real_t dms2deg(int d, int am, real_t as);

void deg2hms(int* h, int* m, real_t* s, real_t d);

void deg2dms(int* d, int* m, real_t* s, real_t deg);

real_t hms2rad(int h, int m, real_t s);

real_t dms2rad(int d, int am, real_t as);

void rad2hms(int* h, int* m, real_t* s, real_t r);

void rad2dms(int* d, int* m, real_t* s, real_t r);

real_t rad2circle(real_t phi);

real_t deg2circle(real_t phi);

/* epoch.c */
void j20002b1950(real_t* alpha_B, real_t* delta_B, real_t alpha_J, real_t delta_J);

void b19502j2000(real_t* alpha_J, real_t* delta_J, real_t alpha_B, real_t delta_B);

/* cartesian_logpolar.c */
void logpolar2cartesian(real_t* x, real_t* y, real_t rho, real_t theta);

void cartesian2logpolar(real_t* rho, real_t* theta, real_t x, real_t y);

/* cartesian_polar.c */
void polar2cartesian(real_t* x, real_t* y, real_t r, real_t theta);

void cartesian2polar(real_t* r, real_t* theta, real_t x, real_t y);

/* cartesian_spherical.c */
void spherical2cartesian(real_t* x, real_t* y, real_t* z, real_t rho, real_t theta, real_t phi);

void cartesian2spherical(real_t* rho, real_t* theta, real_t* phi, real_t x, real_t y, real_t z);

/* cylindrical_spherical.c */
void spherical2cylindrical(real_t* r, real_t* h, real_t rho, real_t phi);

void cylindrical2spherical(real_t* rho, real_t* phi, real_t r, real_t h);

/* equatorial_horizontal.c */
void equatorial2horizontal(real_t* A, real_t* h, real_t H, real_t delta, real_t phi);

void horizontal2equatorial(real_t* H, real_t* delta, real_t A, real_t h, real_t phi);

void radec2azel(real_t* A, real_t* h, real_t alpha, real_t delta, real_t utc, real_t ut1_utc, real_t L, real_t phi);

void azel2radec(real_t* alpha, real_t* delta, real_t A, real_t h, real_t utc, real_t ut1_utc, real_t L, real_t phi);

/* jd_date.c */
real_t gregoriandate2jd(int y, int m, real_t d);

real_t juliandate2jd(int y, int m, real_t d);

real_t date2jd(int y, int m, real_t d);

void jd2date(int* y, int* m, real_t* d, real_t jd);

/* nutation.c */
real_t nutation(real_t jde);

real_t obliquity(real_t jde);

real_t meanobliquity(real_t jde);

real_t trueobliquity(real_t jde);

/* sidereal_time.c */
real_t gmst(real_t jd);

real_t gast(real_t jd, real_t jde);

real_t last(real_t jd, real_t jde, real_t L);

/* equatorial_galactic.c */
void equatorial2galactic(real_t* l, real_t* b, real_t alpha, real_t delta);

void galactic2equatorial(real_t* alpha, real_t* delta, real_t l, real_t b);

/* utc.c */
int tai_utc(real_t utc);

real_t tt_utc(real_t utc);

/* equatorial_ecliptic.c */
void equatorial2ecliptic(real_t* lambda, real_t* beta, real_t alpha, real_t delta, real_t jde);

void ecliptic2equatorial(real_t* alpha, real_t* delta, real_t lambda, real_t beta, real_t jde);

/* itrf_local.c */
void itrf2local(real_t* E, real_t* N, real_t* U, real_t x, real_t y, real_t z, real_t ref_x, real_t ref_y, real_t ref_z, real_t ref_lon, real_t ref_lat);

/* distance.c */
real_t angularseparation(real_t a1, real_t d1, real_t a2, real_t d2);

/* hjd.c */
real_t jd2hjd(real_t jd, real_t alpha, real_t delta, real_t utc, real_t ut1_utc, real_t L, real_t phi);

#endif // __TMF_H__

