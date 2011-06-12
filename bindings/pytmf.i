%module(docstring="Transmogrify is a fast, accurate and easy to use C/C++ library for astronomical coordinate and time transformations.") pytmf
%include "typemaps.i"
%{
/* Includes the header in the wrapper code */
#include "tmf.h"
%}

/* Parse constants header file to generate wrappers */
%include "constants.h"

/* Strip prefix */
%rename("%(strip:[tmf_])s") "";

/* Generate wrappers for the following functions */

/* angles.c */
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

/* epoch.c */
void tmf_j2000_to_b1950(double* OUTPUT, double* OUTPUT, double alpha_J, double delta_J);

void tmf_b1950_to_j2000(double* OUTPUT, double* OUTPUT, double alpha_B, double delta_B);

/* cartesian_logpolar.c */
void tmf_logpolar_to_cartesian(double* OUTPUT, double* OUTPUT, double rho, double theta);

void tmf_cartesian_to_logpolar(double* OUTPUT, double* OUTPUT, double x, double y);

/* cartesian_polar.c */
void tmf_polar_to_cartesian(double* OUTPUT, double* OUTPUT, double r, double theta);

void tmf_cartesian_to_polar(double* OUTPUT, double* OUTPUT, double x, double y);

/* cartesian_spherical.c */
void tmf_spherical_to_cartesian(double* OUTPUT, double* OUTPUT, double* OUTPUT, double rho, double theta, double phi);

void tmf_cartesian_to_spherical(double* OUTPUT, double* OUTPUT, double* OUTPUT, double x, double y, double z);

/* cylindrical_spherical.c */
void tmf_spherical_to_cylindrical(double* OUTPUT, double* OUTPUT, double rho, double phi);

void tmf_cylindrical_to_spherical(double* OUTPUT, double* OUTPUT, double r, double h);

/* equatorial_horizontal.c */
void tmf_equatorial_to_horizontal(double* OUTPUT, double* OUTPUT, double H, double delta, double phi);

void tmf_horizontal_to_equatorial(double* OUTPUT, double* OUTPUT, double A, double h, double phi);

void tmf_radec_to_azel(double* OUTPUT, double* OUTPUT, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

void tmf_azel_to_radec(double* OUTPUT, double* OUTPUT, double A, double h, double utc, double ut1_utc, double L, double phi);

/* jd_date.c */
double tmf_jd_to_mjd(double jd);

double tmf_mjd_to_jd(double mjd);

double tmf_gregorian_to_jd(int y, int m, double d);

double tmf_julian_to_jd(int y, int m, double d);

double tmf_date_to_jd(int y, int m, double d);

void tmf_jd_to_date(int* OUTPUT, int* OUTPUT, double* OUTPUT, double jd);

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
void tmf_equatorial_to_galactic(double* OUTPUT, double* OUTPUT, double alpha, double delta);

void tmf_galactic_to_equatorial(double* OUTPUT, double* OUTPUT, double l, double b);

/* utc.c */
int tmf_delta_tai_utc(double utc);

double tmf_delta_tt_utc(double utc);

/* equatorial_ecliptic.c */
void tmf_equatorial_to_ecliptic(double* OUTPUT, double* OUTPUT, double alpha, double delta, double jde);

void tmf_ecliptic_to_equatorial(double* OUTPUT, double* OUTPUT, double lambda, double beta, double jde);

/* itrf_local.c */
void tmf_itrf_to_local(double* OUTPUT, double* OUTPUT, double* OUTPUT, double x, double y, double z, double ref_x, double ref_y, double ref_z, double ref_lon, double ref_lat);

/* distance.c */
double tmf_angular_separation(double a1, double d1, double a_to_, double d_to_);

/* hjd.c */
double tmf_jd_to_hjd(double jd, double alpha, double delta, double utc, double ut1_utc, double L, double phi);

