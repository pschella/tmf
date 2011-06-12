/**************************************************************************
 *  This file is part of the Transmogrify library.                        *
 *  Copyright tmf_(C) 2010 Pim Schellart <P.Schellart@astro.ru.nl>            *
 *                                                                        *
 *  This library is free software: you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation, either version 3 of the License, or     *
 *  tmf_(at your option) any later version.                                   *
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

#include <tmf_config.h>
#include <constants.h>

#ifdef __cplusplus
extern "C" {
#endif 

/* angles.c */
real_t tmf_deg2rad(real_t a);

real_t tmf_rad2deg(real_t a);

real_t tmf_hms2deg(int h, int m, real_t s);

real_t tmf_dms2deg(int d, int am, real_t as);

void tmf_deg2hms(int* h, int* m, real_t* s, real_t d);

void tmf_deg2dms(int* d, int* m, real_t* s, real_t deg);

real_t tmf_hms2rad(int h, int m, real_t s);

real_t tmf_dms2rad(int d, int am, real_t as);

void tmf_rad2hms(int* h, int* m, real_t* s, real_t r);

void tmf_rad2dms(int* d, int* m, real_t* s, real_t r);

real_t tmf_rad2circle(real_t phi);

real_t tmf_deg2circle(real_t phi);

/* epoch.c */
void tmf_j2000_to_b1950(real_t* alpha_B, real_t* delta_B, real_t alpha_J, real_t delta_J);

void tmf_b1950_to_j2000(real_t* alpha_J, real_t* delta_J, real_t alpha_B, real_t delta_B);

/* cartesian_logpolar.c */
void tmf_logpolar_to_cartesian(real_t* x, real_t* y, real_t rho, real_t theta);

void tmf_cartesian_to_logpolar(real_t* rho, real_t* theta, real_t x, real_t y);

/* cartesian_polar.c */
void tmf_polar_to_cartesian(real_t* x, real_t* y, real_t r, real_t theta);

void tmf_cartesian_to_polar(real_t* r, real_t* theta, real_t x, real_t y);

/* cartesian_spherical.c */
void tmf_spherical_to_cartesian(real_t* x, real_t* y, real_t* z, real_t rho, real_t theta, real_t phi);

void tmf_cartesian_to_spherical(real_t* rho, real_t* theta, real_t* phi, real_t x, real_t y, real_t z);

/* cylindrical_spherical.c */
void tmf_spherical_to_cylindrical(real_t* r, real_t* h, real_t rho, real_t phi);

void tmf_cylindrical_to_spherical(real_t* rho, real_t* phi, real_t r, real_t h);

/* equatorial_horizontal.c */
void tmf_equatorial_to_horizontal(real_t* A, real_t* h, real_t H, real_t delta, real_t phi);

void tmf_horizontal_to_equatorial(real_t* H, real_t* delta, real_t A, real_t h, real_t phi);

void tmf_radec_to_azel(real_t* A, real_t* h, real_t alpha, real_t delta, real_t utc, real_t ut1_utc, real_t L, real_t phi);

void tmf_azel_to_radec(real_t* alpha, real_t* delta, real_t A, real_t h, real_t utc, real_t ut1_utc, real_t L, real_t phi);

/* jd_date.c */
real_t tmf_jd_to_mjd(real_t jd);

real_t tmf_mjd_to_jd(real_t mjd);

real_t tmf_gregorian_to_jd(int y, int m, real_t d);

real_t tmf_julian_to_jd(int y, int m, real_t d);

real_t tmf_date_to_jd(int y, int m, real_t d);

void tmf_jd_to_date(int* y, int* m, real_t* d, real_t jd);

/* nutation.c */
real_t tmf_nutation(real_t jde);

real_t tmf_obliquity(real_t jde);

real_t tmf_mean_obliquity(real_t jde);

real_t tmf_true_obliquity(real_t jde);

/* sidereal_time.c */
real_t tmf_gmst(real_t jd);

real_t tmf_gast(real_t jd, real_t jde);

real_t tmf_last(real_t jd, real_t jde, real_t L);

/* equatorial_galactic.c */
void tmf_equatorial_to_galactic(real_t* l, real_t* b, real_t alpha, real_t delta);

void tmf_galactic_to_equatorial(real_t* alpha, real_t* delta, real_t l, real_t b);

/* utc.c */
int tmf_delta_tai_utc(real_t utc);

real_t tmf_delta_tt_utc(real_t utc);

/* equatorial_ecliptic.c */
void tmf_equatorial_to_ecliptic(real_t* lambda, real_t* beta, real_t alpha, real_t delta, real_t jde);

void tmf_ecliptic_to_equatorial(real_t* alpha, real_t* delta, real_t lambda, real_t beta, real_t jde);

/* itrf_local.c */
void tmf_itrf_to_local(real_t* E, real_t* N, real_t* U, real_t x, real_t y, real_t z, real_t ref_x, real_t ref_y, real_t ref_z, real_t ref_lon, real_t ref_lat);

/* distance.c */
real_t tmf_angular_separation(real_t a1, real_t d1, real_t a2, real_t d2);

/* hjd.c */
real_t tmf_jd_to_hjd(real_t jd, real_t alpha, real_t delta, real_t utc, real_t ut1_utc, real_t L, real_t phi);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __TMF_H__

