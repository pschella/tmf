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

#ifndef TMF_H
#define TMF_H

// SYSTEM INCLUDES
#include <math.h>

// PROJECT INCLUDES
#include <constants.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

/* angles.c */
double deg2rad(double a);

double rad2deg(double a);

double jd2mjd(double jd);

double mjd2jd(double mjd);

double hms2deg(int h, int m, double s);

double dms2deg(int d, int am, double as);

void deg2hms(int* h, int* m, double* s, double d);

void deg2dms(int* d, int* m, double* s, double deg);

double hms2rad(int h, int m, double s);

double dms2rad(int d, int am, double as);

void rad2hms(int* h, int* m, double* s, double r);

void rad2dms(int* d, int* m, double* s, double r);

double rad2circle(double phi);

double deg2circle(double phi);

/* epoch.c */
void j20002b1950(double* alpha_B, double* delta_B, double alpha_J, double delta_J);

void b19502j2000(double* alpha_J, double* delta_J, double alpha_B, double delta_B);

/* cartesian_logpolar.c */
void logpolar2cartesian(double* x, double* y, double rho, double theta);

void cartesian2logpolar(double* rho, double* theta, double x, double y);

/* cartesian_polar.c */
void polar2cartesian(double* x, double* y, double r, double theta);

void cartesian2polar(double* r, double* theta, double x, double y);

/* cartesian_spherical.c */
void spherical2cartesian(double* x, double* y, double* z, double rho, double theta, double phi);

void cartesian2spherical(double* rho, double* theta, double* phi, double x, double y, double z);

/* cylindrical_spherical.c */
void spherical2cylindrical(double* r, double* h, double rho, double phi);

void cylindrical2spherical(double* rho, double* phi, double r, double h);

/* equatorial_horizontal.c */
void equatorial2horizontal(double* A, double* h, double H, double delta, double phi);

void horizontal2equatorial(double* H, double* delta, double A, double h, double phi);

void radec2azel(double* A, double* h, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

void azel2radec(double* alpha, double* delta, double A, double h, double utc, double ut1_utc, double L, double phi);

/* jd_date.c */
double gregoriandate2jd(int y, int m, double d);

double juliandate2jd(int y, int m, double d);

double date2jd(int y, int m, double d);

void jd2date(int* y, int* m, double* d, double jd);

/* nutation.c */
double nutation(double jde);

double obliquity(double jde);

double meanobliquity(double jde);

double trueobliquity(double jde);

/* sidereal_time.c */
double gmst(double jd);

double gast(double jd, double jde);

double last(double jd, double jde, double L);

/* equatorial_galactic.c */
void equatorial2galactic(double* l, double* b, double alpha, double delta);

void galactic2equatorial(double* alpha, double* delta, double l, double b);

/* utc.c */
int tai_utc(double utc);

double tt_utc(double utc);

/* equatorial_ecliptic.c */
void equatorial2ecliptic(double* lambda, double* beta, double alpha, double delta, double jde);

void ecliptic2equatorial(double* alpha, double* delta, double lambda, double beta, double jde);

/* itrf_local.c */
void itrf2local(double* E, double* N, double* U, double x, double y, double z, double ref_x, double ref_y, double ref_z, double ref_lon, double ref_lat);

/* hjd.c */
double jd2hjd(double jd, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

#endif // TMF_H

