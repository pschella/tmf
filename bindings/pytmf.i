%module(docstring="Transmogrify is a fast, accurate and easy to use C/C++ library for astronomical coordinate and time transformations.") pytmf
%include "typemaps.i"
%{
/* Includes the header in the wrapper code */
#include "tmf.h"
%}

/* Parse constants header file to generate wrappers */
%include "constants.h"

/* Generate wrappers for the following functions */

/* angles.c */
double deg2rad(double a);

double rad2deg(double a);

double jd2mjd(double jd);

double mjd2jd(double mjd);

double hms2deg(int h, int m, double s);

double dms2deg(int d, int am, double as);

void deg2hms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double d);

void deg2dms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double deg);

double hms2rad(int h, int m, double s);

double dms2rad(int d, int am, double as);

void rad2hms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double r);

void rad2dms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double r);

double rad2circle(double phi);

double deg2circle(double phi);

/* epoch.c */
void j20002b1950(double* OUTPUT, double* OUTPUT, double alpha_J, double delta_J);

void b19502j2000(double* OUTPUT, double* OUTPUT, double alpha_B, double delta_B);

/* cartesian_logpolar.c */
void logpolar2cartesian(double* OUTPUT, double* OUTPUT, double rho, double theta);

void cartesian2logpolar(double* OUTPUT, double* OUTPUT, double x, double y);

/* cartesian_polar.c */
void polar2cartesian(double* OUTPUT, double* OUTPUT, double r, double theta);

void cartesian2polar(double* OUTPUT, double* OUTPUT, double x, double y);

/* cartesian_spherical.c */
void spherical2cartesian(double* OUTPUT, double* OUTPUT, double* OUTPUT, double rho, double theta, double phi);

void cartesian2spherical(double* OUTPUT, double* OUTPUT, double* OUTPUT, double x, double y, double z);

/* cylindrical_spherical.c */
void spherical2cylindrical(double* OUTPUT, double* OUTPUT, double rho, double phi);

void cylindrical2spherical(double* OUTPUT, double* OUTPUT, double r, double h);

/* equatorial_horizontal.c */
void equatorial2horizontal(double* OUTPUT, double* OUTPUT, double H, double delta, double phi);

void horizontal2equatorial(double* OUTPUT, double* OUTPUT, double A, double h, double phi);

void radec2azel(double* OUTPUT, double* OUTPUT, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

void azel2radec(double* OUTPUT, double* OUTPUT, double A, double h, double utc, double ut1_utc, double L, double phi);

/* jd_date.c */
double gregoriandate2jd(int y, int m, double d);

double juliandate2jd(int y, int m, double d);

double date2jd(int y, int m, double d);

void jd2date(int* OUTPUT, int* OUTPUT, double* OUTPUT, double jd);

/* nutation.c */
double nutation(double jde);

double obliquity(double jde);

double meanobliquity(double jde);

double trueobliquity(double jde);

/* sidedoubleime.c */
double gmst(double jd);

double gast(double jd, double jde);

double last(double jd, double jde, double L);

/* equatorial_galactic.c */
void equatorial2galactic(double* OUTPUT, double* OUTPUT, double alpha, double delta);

void galactic2equatorial(double* OUTPUT, double* OUTPUT, double l, double b);

/* utc.c */
int tai_utc(double utc);

double tt_utc(double utc);

/* equatorial_ecliptic.c */
void equatorial2ecliptic(double* OUTPUT, double* OUTPUT, double alpha, double delta, double jde);

void ecliptic2equatorial(double* OUTPUT, double* OUTPUT, double lambda, double beta, double jde);

/* itrf_local.c */
void itrf2local(double* OUTPUT, double* OUTPUT, double* OUTPUT, double x, double y, double z, double ref_x, double ref_y, double ref_z, double ref_lon, double ref_lat);

/* distance.c */
double angularseparation(double a1, double d1, double a2, double d2);

/* hjd.c */
double jd2hjd(double jd, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

