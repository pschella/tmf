
// File: index.xml

// File: angles_8h.xml
%feature("docstring")  tmf_hav "real_t tmf_hav(const real_t theta)

Haversine ";

%feature("docstring")  tmf_ahav "real_t tmf_ahav(const real_t a)

Inverse haversine ";

%feature("docstring")  tmf_deg2rad "real_t tmf_deg2rad(const real_t
a)

Convert degrees to radians ";

%feature("docstring")  tmf_rad2deg "real_t tmf_rad2deg(const real_t
a)

Convert radians to degrees ";

%feature("docstring")  tmf_hms2deg "real_t tmf_hms2deg(const int h,
const int m, const real_t s)

Convert hours, min, sec to degrees.

deg degrees

Parameters:
-----------

h:  degrees

m:  minutes

s:  seconds ";

%feature("docstring")  tmf_dms2deg "real_t tmf_dms2deg(const int d,
const int am, const real_t as)

Convert degrees, arcmin, arcsec to degrees.

deg degrees

Parameters:
-----------

d:  degrees

am:  arcminutes

as:  arcseconds ";

%feature("docstring")  tmf_deg2hms "void tmf_deg2hms(int *h, int *m,
real_t *s, const real_t d)

Convert degrees to hours, min, sec.

Note, angles outside of the range [0, 360) are projected onto this
range.

Parameters:
-----------

h:  hour

m:  minutes

s:  seconds

d:  degrees ";

%feature("docstring")  tmf_deg2dms "void tmf_deg2dms(int *d, int *m,
real_t *s, real_t deg)

Convert degrees to degrees, min, sec.

Parameters:
-----------

d:  degrees

m:  minutes

s:  seconds

deg:  degrees ";

%feature("docstring")  tmf_hms2rad "real_t tmf_hms2rad(const int h,
const int m, const real_t s)

Convert hours, min, sec to radians.

rad radians

Parameters:
-----------

h:  radians

m:  minutes

s:  seconds ";

%feature("docstring")  tmf_dms2rad "real_t tmf_dms2rad(const int d,
const int am, const real_t as)

Convert degrees, arcmin, arcsec to radians.

rad radians

Parameters:
-----------

d:  degrees

am:  arcminutes

as:  arcseconds ";

%feature("docstring")  tmf_rad2hms "void tmf_rad2hms(int *h, int *m,
real_t *s, const real_t r)

Convert radians to hours, min, sec.

Parameters:
-----------

h:  hour

m:  minutes

s:  seconds

r:  radians ";

%feature("docstring")  tmf_rad2dms "void tmf_rad2dms(int *d, int *m,
real_t *s, const real_t r)

Convert radians to degrees, min, sec.

Note, angles outside of the range [0, 2*pi) are projected onto this
range.

Parameters:
-----------

d:  radians

m:  minutes

s:  seconds

r:  radians ";

%feature("docstring")  tmf_rad2circle "real_t tmf_rad2circle(const
real_t phi)

Project an angle onto the range [0,2*pi)

Parameters:
-----------

phi:  angle in radians

angle in range [0,2*pi) ";

%feature("docstring")  tmf_deg2circle "real_t tmf_deg2circle(const
real_t phi)

Project an angle onto the range [0,360)

Parameters:
-----------

phi:  angle in radians

angle in range [0,360) ";


// File: angular__separation_8h.xml
%feature("docstring")  tmf_angular_separation "real_t
tmf_angular_separation(const real_t lon_1, const real_t lat_1, const
real_t lon_2, const real_t lat_2)

Calculate angular separation.

angular separation in radians

Parameters:
-----------

lon_1:  longitude of point 1 in radians

lat_1:  latitude of point 1 in radians

lon_2:  longitude of point 2 in radians

lat_2:  latitude of point 2 in radians ";


// File: cartesian__logpolar_8h.xml
%feature("docstring")  tmf_logpolar2cartesian "void
tmf_logpolar2cartesian(real_t *x, real_t *y, const real_t rho, const
real_t theta)

Converts logpolar coordinates to Cartesian coordinates.

Parameters:
-----------

x:  x-coordinate

y:  y-coordinate

rho:  radius

theta:  angle with x-axis ";

%feature("docstring")  tmf_cartesian2logpolar "void
tmf_cartesian2logpolar(real_t *rho, real_t *theta, const real_t x,
const real_t y)

Converts Cartesian coordinates to logpolar coordinates.

Parameters:
-----------

rho:  radius

theta:  angle with x-axis

x:  x-coordinate

y:  y-coordinate ";


// File: cartesian__polar_8h.xml
%feature("docstring")  tmf_polar2cartesian "void
tmf_polar2cartesian(real_t *x, real_t *y, const real_t r, const real_t
theta)

Converts polar coordinates to Cartesian coordinates.

Parameters:
-----------

x:  x-coordinate

y:  y-coordinate

r:  radius

theta:  angle with x-axis ";

%feature("docstring")  tmf_cartesian2polar "void
tmf_cartesian2polar(real_t *r, real_t *theta, const real_t x, const
real_t y)

Converts Cartesian coordinates to polar coordinates.

Parameters:
-----------

r:  radius

theta:  angle with x-axis

x:  x-coordinate

y:  y-coordinate ";


// File: cartesian__spherical_8h.xml
%feature("docstring")  tmf_spherical2cartesian "void
tmf_spherical2cartesian(real_t *x, real_t *y, real_t *z, const real_t
rho, const real_t theta, const real_t phi)

Converts spherical coordinates to Cartesian coordinates.

Parameters:
-----------

x:  x-coordinate

y:  y-coordinate

z:  z-coordinate

rho:  radius

theta:  inclination angle from z-axis

phi:  azimuth angle from x-axis ";

%feature("docstring")  tmf_cartesian2spherical "void
tmf_cartesian2spherical(real_t *rho, real_t *theta, real_t *phi, const
real_t x, const real_t y, const real_t z)

Converts Cartesian coordinates to spherical coordinates.

Parameters:
-----------

rho:  radius

theta:  inclination angle from z-axis

phi:  azimuth angle from x-axis

x:  x-coordinate

y:  y-coordinate

z:  z-coordinate ";


// File: constants_8h.xml


// File: cylindrical__spherical_8h.xml
%feature("docstring")  tmf_spherical2cylindrical "void
tmf_spherical2cylindrical(real_t *r, real_t *h, const real_t rho,
const real_t phi)

Converts spherical coordinates to cylindrical coordinates.

Note that theta (the inclination angle from z-axis) is the same in
both systems.

Parameters:
-----------

r:  cylindrical radius

h:  cylindrical height

rho:  radius

phi:  azimuth angle from x-axis ";

%feature("docstring")  tmf_cylindrical2spherical "void
tmf_cylindrical2spherical(real_t *rho, real_t *phi, const real_t r,
const real_t h)

Converts cylindrical coordinates to spherical coordinates.

Note that theta (the inclination angle from z-axis) is the same in
both systems.

Parameters:
-----------

rho:  radius

phi:  azimuth angle from x-axis

r:  cylindrical radius

h:  cylindrical height ";


// File: epoch_8h.xml
%feature("docstring")  tmf_j20002b1950 "void tmf_j20002b1950(real_t
*alpha_B, real_t *delta_B, const real_t alpha_J, const real_t delta_J)

Convert equatorial coordinates from epoch J2000 to B1950.

Rotation matrix derived from equation 14.55 and the problem 14.6 in
Spherical Astronomy by Robin M. Green Cambridge University Press 1985
ISBN 0-521-31779-7

Parameters:
-----------

alpha_B:  right ascension reffered to the B1950 standard epoch

delta_B:  declination reffered to the B1950 standard epoch

alpha_J:  right ascension reffered to the J2000 standard epoch

delta_J:  declination reffered to the J2000 standard epoch ";

%feature("docstring")  tmf_b19502j2000 "void tmf_b19502j2000(real_t
*alpha_J, real_t *delta_J, const real_t alpha_B, const real_t delta_B)

Convert equatorial coordinates from epoch B1950 to J2000.

Rotation matrix derived from equation 14.55 and the problem 14.6 in
Spherical Astronomy by Robin M. Green Cambridge University Press 1985
ISBN 0-521-31779-7

Parameters:
-----------

alpha_J:  right ascension reffered to the J2000 standard epoch

delta_J:  declination reffered to the J2000 standard epoch

alpha_B:  right ascension reffered to the B1950 standard epoch

delta_B:  declination reffered to the B1950 standard epoch ";


// File: equatorial__ecliptical_8h.xml
%feature("docstring")  tmf_equatorial2ecliptic "void
tmf_equatorial2ecliptic(real_t *lambda, real_t *beta, const real_t
alpha, const real_t delta, const real_t jde)

Conversion of equatorial coordinates to ecliptical coordinates.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Parameters:
-----------

lambda:  ecliptical (or celestial) longitude, measured from the vernal
equinox along the ecliptic in radians

beta:  ecliptical (or celestial) latitude, positive if north of the
ecliptic, negative if south in radians

alpha:  right ascension in radians (B1950.0 equinox)

delta:  declination in radians (B1950.0 equinox)

jde:  Julian Date of TD (or equivalently TT) ";

%feature("docstring")  tmf_ecliptic2equatorial "void
tmf_ecliptic2equatorial(real_t *alpha, real_t *delta, const real_t
lambda, const real_t beta, const real_t jde)

Conversion of ecliptical coordinates to equatorial coordinates.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Parameters:
-----------

alpha:  right ascension in radians (B1950.0 equinox)

delta:  declination in radians (B1950.0 equinox)

lambda:  ecliptical (or celestial) longitude, measured from the vernal
equinox along the ecliptic in radians

beta:  ecliptical (or celestial) latitude, positive if north of the
ecliptic, negative if south in radians

jde:  Julian Date of TD (or equivalently TT) ";


// File: equatorial__galactic_8h.xml
%feature("docstring")  tmf_equatorial2galactic "void
tmf_equatorial2galactic(real_t *l, real_t *b, const real_t alpha,
const real_t delta)

Conversion of equatorial coordinates to galactic coordinates.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Parameters:
-----------

l:  galactic longitude in radians

b:  galactic latitutde in radians

alpha:  right ascension in radians (B1950.0 equinox)

delta:  declination in radians (B1950.0 equinox) ";

%feature("docstring")  tmf_galactic2equatorial "void
tmf_galactic2equatorial(real_t *alpha, real_t *delta, const real_t l,
const real_t b)

Conversion of galactic coordinates to equatorial coordinates.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Parameters:
-----------

alpha:  right ascension in radians (B1950.0 equinox)

delta:  declination in radians (B1950.0 equinox)

l:  galactic longitude in radians

b:  galactic latitutde in radians ";


// File: equatorial__horizontal_8h.xml
%feature("docstring")  tmf_equatorial2horizontal "void
tmf_equatorial2horizontal(real_t *A, real_t *h, const real_t H, const
real_t delta, const real_t phi)

Conversion of equatorial coordinates to horizontal coordinates.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Modified slightly to calculate azimuth westward from north instead of
south.

Parameters:
-----------

A:  azimuth, measured westward from the north

h:  altitude, positive above the horizon, negative below

H:  hour angle (e.g. last - alpha where alpha is the right ascension
and last the local apparent siderial time)

delta:  declination, positive if north of the celestial equator,
negative if south

phi:  observer's latitude, positive if in the northern hemisphere,
negative in the southern one ";

%feature("docstring")  tmf_horizontal2equatorial "void
tmf_horizontal2equatorial(real_t *H, real_t *delta, const real_t A,
const real_t h, const real_t phi)

Conversion of equatorial coordinates to horizontal coordinates.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Modified slightly to calculate azimuth westward from north instead of
south.

Parameters:
-----------

H:  hour angle (e.g. last - alpha where alpha is the right ascension
and last the local apparent siderial time)

delta:  declination, positive if north of the celestial equator,
negative if south

A:  azimuth, measured westward from the north

h:  altitude, positive above the horizon, negative below

phi:  observer's latitude, positive if in the northern hemisphere,
negative in the southern one ";

%feature("docstring")  tmf_radec2azel "void tmf_radec2azel(real_t *A,
real_t *h, const real_t alpha, const real_t delta, const real_t utc,
const real_t ut1_utc, const real_t L, const real_t phi)

Convenience function for conversion of equatorial coordinates to
horizontal coordinates.

Use this function for quick and easy conversion of a few coordinates.
For many conversions sharing the same time and location please use the
sub functions to avoid unnessesary calculations.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Modified slightly to calculate azimuth westward from north instead of
south.

Parameters:
-----------

A:  azimuth, measured westward from the north

h:  altitude, positive above the horizon, negative below

alpha:  right ascension

delta:  declination, positive if north of the celestial equator,
negative if south

utc:  (universal time coordinated) as Julian day

ut1_utc:  difference UT1-UTC (as obtained from IERS bullitin A) if 0 a
maximum error of 0.9 seconds is made.

L:  observer's longitude (positive east, negative west from Greenwich)

phi:  observer's latitude, positive if in the northern hemisphere,
negative in the southern one ";

%feature("docstring")  tmf_azel2radec "void tmf_azel2radec(real_t
*alpha, real_t *delta, const real_t A, const real_t h, const real_t
utc, const real_t ut1_utc, const real_t L, const real_t phi)

Convenience function for conversion of horizontal coordinates to
equatorial coordinates.

Use this function for quick and easy conversion of a few coordinates.
For many conversions sharing the same time and location please use the
sub functions to avoid unnessesary calculations.

Direct implementation of the method described in chapter 13 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Modified slightly to calculate azimuth westward from north instead of
south.

Parameters:
-----------

alpha:  right ascension

delta:  declination, positive if north of the celestial equator,
negative if south

A:  azimuth, measured westward from the north

h:  altitude, positive above the horizon, negative below

utc:  (universal time coordinated) as Julian day

ut1_utc:  difference UT1-UTC (as obtained from IERS bullitin A) if 0 a
maximum error of 0.9 seconds is made.

L:  observer's longitude (positive east, negative west from Greenwich)

phi:  observer's latitude, positive if in the northern hemisphere,
negative in the southern one ";


// File: hjd_8h.xml
%feature("docstring")  tmf_jd2hjd "real_t tmf_jd2hjd(const real_t jd,
const real_t alpha, const real_t delta, const real_t utc, const real_t
ut1_utc, const real_t L, const real_t phi)

Convert Julian day to the Heliocentric frame by correcting for the
projected light travel time between the Earth and the Sun.

hjd Julian day

Parameters:
-----------

jd:  year

alpha:  right ascension

delta:  declination, positive if north of the celestial equator,

utc:  (universal time coordinated) as Julian day

ut1_utc:  difference UT1-UTC (as obtained from IERS bullitin A) if 0 a
maximum error of 0.9 seconds is made.

L:  observer's longitude (positive east, negative west from Greenwich)

phi:  observer's latitude, positive if in the northern hemisphere,
negative in the southern one ";


// File: itrf__local_8h.xml
%feature("docstring")  tmf_itrf2local "void tmf_itrf2local(real_t *E,
real_t *N, real_t *U, const real_t x, const real_t y, const real_t z,
const real_t ref_x, const real_t ref_y, const real_t ref_z, const
real_t ref_lon, const real_t ref_lat)

Convert coordinates from ITRF to local Cartesian.

Parameters:
-----------

E:  easterly

N:  northerly

U:  upper

x:  ITRF x

y:  ITRF y

z:  ITRF z

ref_x:  reference x position in ITRF

ref_y:  reference y position in ITRF

ref_z:  reference z position in ITRF

ref_lon:  reference longitude in radians

ref_lat:  reference latitude in radians ";


// File: jd__date_8h.xml
%feature("docstring")  tmf_jd2mjd "real_t tmf_jd2mjd(const real_t jd)

Convert Julian day to modified Julian day. ";

%feature("docstring")  tmf_mjd2jd "real_t tmf_mjd2jd(const real_t
mjd)

Convert modified Julian day to Julian day. ";

%feature("docstring")  tmf_gregorian2jd "real_t
tmf_gregorian2jd(const int y, const int m, const real_t d)

Convert date in Gregorian calendar to Julian day.

jd Julian day

Parameters:
-----------

y:  year

m:  month

d:  day (with fraction) ";

%feature("docstring")  tmf_julian2jd "real_t tmf_julian2jd(const int
y, const int m, const real_t d)

Convert date in Julian calendar to Julian day.

jd Julian day

Parameters:
-----------

y:  year

m:  month

d:  day (with fraction) ";

%feature("docstring")  tmf_date2jd "real_t tmf_date2jd(const int y,
const int m, const real_t d)

Convert date in Gregorian or Julian calendar to Julian day.

jd Julian day

Parameters:
-----------

y:  year

m:  month

d:  day (with fraction) ";

%feature("docstring")  tmf_jd2date "void tmf_jd2date(int *y, int *m,
real_t *d, const real_t jd)

Convert Julian day to calendar date.

Parameters:
-----------

y:  year

m:  month

d:  day (with fraction)

jd:  Julian day ";


// File: nutation_8h.xml
%feature("docstring")  tmf_nutation "real_t tmf_nutation(const real_t
jde)

Get Nutation and Obliquity of the Ecliptic at given instant.

The nutation is due to the action of the Moon and can be described as
a sum of periodic terms. Nutation is partioned into a component
parallel to and one perpendicular to the ecliptic. The component
allong the ecliptic is called the ``nutation in longitude'' and
affects the celestial longitude of all heavenly bodies. The component
perpendicular to the ecliptic is called the ``nutation of obliquity''
and affects the obliquity of the equator to the ecliptic, it does not
affect the longitude of heavenly bodies.

Direct implementation of the method described in chapter 22 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Parameters:
-----------

jde:  Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
equivalently Terrestrial Time (TT)) ";

%feature("docstring")  tmf_obliquity "real_t tmf_obliquity(const
real_t jde)

Get Obliquity of the Ecliptic at given instant.

The nutation is due to the action of the Moon and can be described as
a sum of periodic terms. Nutation is partioned into a component
parallel to and one perpendicular to the ecliptic. The component
allong the ecliptic is called the ``nutation in longitude'' and
affects the celestial longitude of all heavenly bodies. The component
perpendicular to the ecliptic is called the ``nutation of obliquity''
and affects the obliquity of the equator to the ecliptic, it does not
affect the longitude of heavenly bodies.

Direct implementation of the method described in chapter 22 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Parameters:
-----------

jde:  Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
equivalently Terrestrial Time (TT)) ";

%feature("docstring")  tmf_mean_obliquity "real_t
tmf_mean_obliquity(const real_t jde)

Get mean obliquity of the ecliptic.

Direct implementation of the method described in chapter 22 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

epsilon_0 mean obliquity of the ecliptic in radians

Parameters:
-----------

jde:  Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
equivalently Terrestrial Time (TT)) ";

%feature("docstring")  tmf_true_obliquity "real_t
tmf_true_obliquity(const real_t jde)

Get true obliquity of the ecliptic.

Direct implementation of the method described in chapter 22 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

epsilon true obliquity of the ecliptic in radians

Parameters:
-----------

jde:  Julian Ephemeris Day (e.g. Julian Day of Dynamical Time (TD) or
equivalently Terrestrial Time (TT)) ";


// File: sidereal__time_8h.xml
%feature("docstring")  tmf_gmst "real_t tmf_gmst(const real_t jd)

Get Greanwich Mean Sidereal Time (GMST) in degrees from UT1.

Direct implementation of the method described in chapter 12 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Coefficients converted to radians with identical numerical precission

theta Greanwich Mean Sidereal Time in radians

Parameters:
-----------

jd:  Julian Date of UT1 ";

%feature("docstring")  tmf_gast "real_t tmf_gast(const real_t jd,
const real_t jde)

Get Greenwich Apparent Sidereal Time (GAST) in degrees from UT1.

Direct implementation of the method described in chapter 12 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

theta Greenwich Apparent Sidereal Time in radians

Parameters:
-----------

jd:  Julian Date of UT1

jde:  Julian Date of TD (or equivalently TT) ";

%feature("docstring")  tmf_last "real_t tmf_last(const real_t jd,
const real_t jde, const real_t L)

Get Local Apparent Sidereal Time (LAST) in degrees from UT1.

Direct implementation of the method described in chapter 12 of
Astronomical Algorithms by Jean Meeus, second edition, 2005 Published
by: Willman-Bell Inc. ISBN 0-943396-61-1

Modified slightly to measure longitude positive east in accordance
with IAU convention instead of positive west.

theta Local Aparrent Sidereal Time in radians

Parameters:
-----------

jd:  Julian Date of UT1

jde:  Julian Date of TD (or equivalently TT)

L:  observer's longitude (positive east, negative west from Greenwich)
";


// File: tmf_8h.xml


// File: utc_8h.xml
%feature("docstring")  tmf_delta_tai_utc "int tmf_delta_tai_utc(const
real_t utc)

Calculate TAI - UTC in seconds.

For dates before July 1 1972 a fixed value of 10s will be returned.

Todo Update this routine whenever a leap second is inserted.

Parameters:
-----------

utc:  Universal Time Coordinated as Julian day

TAI - UTC in seconds ";

%feature("docstring")  tmf_delta_tt_utc "real_t
tmf_delta_tt_utc(const real_t utc)

Calculate TT - UTC in seconds.

For dates before July 1 1972 a fixed value of 10s + TT - TAI is
returned.

Parameters:
-----------

utc:  Universal Time Coordinated as Julian day

TT - UTC in seconds ";


// File: todo.xml


// File: dir_e572c31fe1af3a399b34e180bdf058ca.xml

