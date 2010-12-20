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
double deg2rad(const double a);

double rad2deg(const double a);

double jd2mjd(const double jd);

double mjd2jd(const double mjd);

double hms2deg(const int h, const int m, const double s);

double dms2deg(const int d, const int am, const double as);

void deg2hms(int* h, int* m, double* s, const double d);

void deg2dms(int* d, int* m, double* s, const double deg);

double hms2rad(const int h, const int m, const double s);

double dms2rad(const int d, const int am, const double as);

void rad2hms(int* h, int* m, double* s, const double r);

void rad2dms(int* d, int* m, double* s, const double r);

double rad2circle(const double phi);

double deg2circle(const double phi);

/* epoch.c */
void j20002b1950(double* alpha_B, double* delta_B, const double alpha_J, const double delta_J);

void b19502j2000(double* alpha_J, double* delta_J, const double alpha_B, const double delta_B);

/* cartesian_logpolar.c */
void logpolar2cartesian(double* x, double* y, const double rho, const double theta);

void cartesian2logpolar(double* rho, double* theta, const double x, const double y);

/* cartesian_polar.c */
void polar2cartesian(double* x, double* y, const double r, const double theta);

void cartesian2polar(double* r, double* theta, const double x, const double y);

/* cartesian_spherical.c */
void spherical2cartesian(double* x, double* y, double* z, const double rho, const double theta, const double phi);

void cartesian2spherical(double* rho, double* theta, double* phi, const double x, const double y, const double z);

/* cylindrical_spherical.c */
void spherical2cylindrical(double* r, double* h, const double rho, const double phi);

void cylindrical2spherical(double* rho, double* phi, const double r, const double h);

/* equatorial_horizontal.c */
void equatorial2horizontal(double* A, double* h, const double H, const double delta, const double phi);

void horizontal2equatorial(double* H, double* delta, const double A, const double h, const double phi);

void radec2azel(double* A, double* h, const double alpha, const double delta, const double utc, const double ut1_utc, const double L, const double phi);

void azel2radec(double* alpha, double* delta, const double A, const double h, const double utc, const double ut1_utc, const double L, const double phi);

/* jd_date.c */
double gregoriandate2jd(const int y, const int m, const double d);

double juliandate2jd(const int y, const int m, const double d);

double date2jd(const int y, const int m, const double d);

void jd2date(int* y, int* m, double* d, const double jd);

/* nutation.c */
void nutation(double* Dphi, double* Depsilon, const double jde);

double meanobliquity(const double jde);

/* sidereal_time.c */
double gmst(const double jd);

double gast(const double jd, const double jde);

double last(const double jd, const double jde, const double L);

/* equatorial_galactic.c */
void equatorial2galactic(double* l, double* b, const double alpha, const double delta);

void galactic2equatorial(double* alpha, double* delta, const double l, const double b);

/* utc.c */
int tai_utc(const double utc);

double tt_utc(const double utc);

/* equatorial_ecliptic.c */
void equatorial2ecliptic(double* lambda, double* beta, const double alpha, const double delta, const double jde);

void ecliptic2equatorial(double* alpha, double* delta, const double lambda, const double beta, const double jde);

/* itrf_local.c */
void itrf2local(double* E, double* N, double* U, const double x, const double y, const double z, const double ref_x, const double ref_y, const double ref_z, const double ref_lon, const double ref_lat);

/* hjd.c */
double jd2hjd(const double jd, const double alpha, const double delta, const double utc, const double ut1_utc, const double L, const double phi);

#endif // TMF_H

