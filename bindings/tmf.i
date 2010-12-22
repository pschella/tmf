%module(docstring="Transmogrify is a fast, accurate and easy to use C/C++ library for astronomical coordinate and time transformations.") tmf
%include "typemaps.i"
%{
/* Includes the header in the wrapper code */
#include "tmf.h"
%}

/* Parse constants header file to generate wrappers */
%include "constants.h"

/* Generate wrappers for the following functions */

/* angles.c */
double deg2rad(const double a);

double rad2deg(const double a);

double jd2mjd(const double jd);

double mjd2jd(const double mjd);

double hms2deg(const int h, const int m, const double s);

double dms2deg(const int d, const int am, const double as);

void deg2hms(int* OUTPUT, int* OUTPUT, double* OUTPUT, const double d);

void deg2dms(int* OUTPUT, int* OUTPUT, double* OUTPUT, const double deg);

double hms2rad(const int h, const int m, const double s);

double dms2rad(const int d, const int am, const double as);

void rad2hms(int* OUTPUT, int* OUTPUT, double* OUTPUT, const double r);

void rad2dms(int* OUTPUT, int* OUTPUT, double* OUTPUT, const double r);

double rad2circle(const double phi);

double deg2circle(const double phi);

/* epoch.c */
void j20002b1950(double* OUTPUT, double* OUTPUT, const double alpha_J, const double delta_J);

void b19502j2000(double* OUTPUT, double* OUTPUT, const double alpha_B, const double delta_B);

/* cartesian_logpolar.c */
void logpolar2cartesian(double* OUTPUT, double* OUTPUT, const double rho, const double theta);

void cartesian2logpolar(double* OUTPUT, double* OUTPUT, const double x, const double y);

/* cartesian_polar.c */
void polar2cartesian(double* OUTPUT, double* OUTPUT, const double r, const double theta);

void cartesian2polar(double* OUTPUT, double* OUTPUT, const double x, const double y);

/* cartesian_spherical.c */
void spherical2cartesian(double* OUTPUT, double* OUTPUT, double* OUTPUT, const double rho, const double theta, const double phi);

void cartesian2spherical(double* OUTPUT, double* OUTPUT, double* OUTPUT, const double x, const double y, const double z);

/* cylindrical_spherical.c */
void spherical2cylindrical(double* OUTPUT, double* OUTPUT, const double rho, const double phi);

void cylindrical2spherical(double* OUTPUT, double* OUTPUT, const double r, const double h);

/* equatorial_horizontal.c */
void equatorial2horizontal(double* OUTPUT, double* OUTPUT, const double H, const double delta, const double phi);

void horizontal2equatorial(double* OUTPUT, double* OUTPUT, const double A, const double h, const double phi);

void radec2azel(double* OUTPUT, double* OUTPUT, const double alpha, const double delta, const double utc, const double ut1_utc, const double L, const double phi);

void azel2radec(double* OUTPUT, double* OUTPUT, const double A, const double h, const double utc, const double ut1_utc, const double L, const double phi);

/* jd_date.c */
double gregoriandate2jd(const int y, const int m, const double d);

double juliandate2jd(const int y, const int m, const double d);

double date2jd(const int y, const int m, const double d);

void jd2date(int* OUTPUT, int* OUTPUT, double* OUTPUT, const double jd);

/* nutation.c */
void nutation(double* OUTPUT, double* OUTPUT, const double jde);

double meanobliquity(const double jde);

/* sidereal_time.c */
double gmst(const double jd);

double gast(const double jd, const double jde);

double last(const double jd, const double jde, const double L);

/* equatorial_galactic.c */
void equatorial2galactic(double* OUTPUT, double* OUTPUT, const double alpha, const double delta);

void galactic2equatorial(double* OUTPUT, double* OUTPUT, const double l, const double b);

/* utc.c */
int tai_utc(const double utc);

double tt_utc(const double utc);

/* equatorial_ecliptic.c */
void equatorial2ecliptic(double* OUTPUT, double* OUTPUT, const double alpha, const double delta, const double jde);

void ecliptic2equatorial(double* OUTPUT, double* OUTPUT, const double lambda, const double beta, const double jde);

/* itrf_local.c */
void itrf2local(double* OUTPUT, double* OUTPUT, double* OUTPUT, const double x, const double y, const double z, const double ref_x, const double ref_y, const double ref_z, const double ref_lon, const double ref_lat);

/* hjd.c */
double jd2hjd(const double jd, const double alpha, const double delta, const double utc, const double ut1_utc, const double L, const double phi);

