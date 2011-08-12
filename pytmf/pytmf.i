%module(docstring="Transmogrify is a fast, accurate and easy to use C/C++ library for astronomical coordinate and time transformations.") pytmf
%include "typemaps.i"
%{
/* Includes the header in the wrapper code */
#include <tmf/tmf.h>
%}

/* Set module version to library version */
%constant char* __version__ = TMF_VERSION;

/* Parse constants header file to generate wrappers */
%include <tmf/constants.h>

/* Strip prefix */
%rename("%(strip:[tmf_])s") "";

/* Enable docstrings */
%feature("autodoc", "1");

/* Generate wrappers for the following functions */

/* angles.c */
double tmf_hav(double theta);

double tmf_ahav(double a);

double tmf_deg2rad(double a);

double tmf_rad2deg(double a);

double tmf_hms2deg(int h, int m, double s);

double tmf_dms2deg(int d, int am, double as);

void tmf_deg2hms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double d);

void tmf_deg2dms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double deg);

double tmf_hms2rad(int h, int m, double s);

double tmf_dms2rad(int d, int am, double as);

void tmf_rad2hms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double r);

void tmf_rad2dms(int* OUTPUT, int* OUTPUT, double* OUTPUT, double r);

double tmf_rad2circle(double phi);

double tmf_deg2circle(double phi);

/* angular_separation.c */
double tmf_angular_separation(double lon_1, double lat_1, double lon_2, double lat_2);

/* epoch.c */
void tmf_j20002b1950(double* OUTPUT, double* OUTPUT, double alpha_J, double delta_J);

void tmf_b19502j2000(double* OUTPUT, double* OUTPUT, double alpha_B, double delta_B);

/* cartesian_logpolar.c */
void tmf_logpolar2cartesian(double* OUTPUT, double* OUTPUT, double rho, double theta);

void tmf_cartesian2logpolar(double* OUTPUT, double* OUTPUT, double x, double y);

/* cartesian_polar.c */
void tmf_polar2cartesian(double* OUTPUT, double* OUTPUT, double r, double theta);

void tmf_cartesian2polar(double* OUTPUT, double* OUTPUT, double x, double y);

/* cartesian_spherical.c */
void tmf_spherical2cartesian(double* OUTPUT, double* OUTPUT, double* OUTPUT, double rho, double theta, double phi);

void tmf_cartesian2spherical(double* OUTPUT, double* OUTPUT, double* OUTPUT, double x, double y, double z);

/* cylindrical_spherical.c */
void tmf_spherical2cylindrical(double* OUTPUT, double* OUTPUT, double rho, double phi);

void tmf_cylindrical2spherical(double* OUTPUT, double* OUTPUT, double r, double h);

/* equatorial_horizontal.c */
void tmf_equatorial2horizontal(double* OUTPUT, double* OUTPUT, double H, double delta, double phi);

void tmf_horizontal2equatorial(double* OUTPUT, double* OUTPUT, double A, double h, double phi);

void tmf_radec2azel(double* OUTPUT, double* OUTPUT, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

void tmf_azel2radec(double* OUTPUT, double* OUTPUT, double A, double h, double utc, double ut1_utc, double L, double phi);

/* jd_date.c */
double tmf_jd2mjd(double jd);

double tmf_mjd2jd(double mjd);

double tmf_gregorian2jd(int y, int m, double d);

double tmf_julian2jd(int y, int m, double d);

double tmf_date2jd(int y, int m, double d);

void tmf_jd2date(int* OUTPUT, int* OUTPUT, double* OUTPUT, double jd);

/* nutation.c */
double tmf_nutation(double jde);

double tmf_obliquity(double jde);

double tmf_mean_obliquity(double jde);

double tmf_true_obliquity(double jde);

/* sidedoubleime.c */
double tmf_gmst(double jd);

double tmf_gast(double jd, double jde);

double tmf_last(double jd, double jde, double L);

/* equatorial_galactic.c */
void tmf_equatorial2galactic(double* OUTPUT, double* OUTPUT, double alpha, double delta);

void tmf_galactic2equatorial(double* OUTPUT, double* OUTPUT, double l, double b);

/* utc.c */
int tmf_delta_tai_utc(double utc);

double tmf_delta_tt_utc(double utc);

/* equatorial_ecliptic.c */
void tmf_equatorial2ecliptic(double* OUTPUT, double* OUTPUT, double alpha, double delta, double jde);

void tmf_ecliptic2equatorial(double* OUTPUT, double* OUTPUT, double lambda, double beta, double jde);

/* itrf_local.c */
void tmf_itrf2local(double* OUTPUT, double* OUTPUT, double* OUTPUT, double x, double y, double z, double ref_x, double ref_y, double ref_z, double ref_lon, double ref_lat);

/* distance.c */
double tmf_angular_separation(double a1, double d1, double a2, double d2);

/* hjd.c */
double tmf_jd2hjd(double jd, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

