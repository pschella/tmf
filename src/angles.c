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
#include <math.h>

// PROJECT INCLUDES
#include <tmf.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

double deg2rad(const double a) { return a * M_PI / 180.; };

double rad2deg(const double a) { return a * 180. / M_PI; };

double jd2mjd(const double jd) { return jd - 2400000.5; };

double mjd2jd(const double mjd) { return mjd + 2400000.5; };

/*!
  \brief Convert hours, min, sec to degrees

  \return deg degrees

  \param h degrees
  \param m minutes
  \param s seconds
 */
double hms2deg(const int h, const int m, const double s)
{
  return (h + m / 60. + s / 3600.) * (180. / 12.);
}

/*!
  \brief Convert degrees, arcmin, arcsec to degrees

  \return deg degrees

  \param d degrees
  \param am arcminutes
  \param as arcseconds
 */
double dms2deg(const int d, const int am, const double as)
{
  return (d + (am / 60.) + (as / 3600.));
}

/*!
  \brief Convert degrees to hours, min, sec

  Note, angles outside of the range [0, 360) are projected onto this range.

  \param h hour
  \param m minutes
  \param s seconds
  \param d degrees
 */
void deg2hms(int* h, int* m, double* s, const double d)
{
  // Make sure D = [0, 360)
  const double D = (d >= 0 ? fmod(d, 360.) : 360. + fmod(d, 360.));
  const double H = D * 12. / 180.;

  *h = (int)H;
  *m = (int)((H - *h) * 60.);
  *s = (H - *h - (*m / 60.)) * 3600.;
}

/*!
  \brief Convert degrees to degrees, min, sec

  \param d degrees
  \param m minutes
  \param s seconds
  \param deg degrees
 */
void deg2dms(int* d, int* m, double* s, double deg)
{
  *d = (int)deg;
  deg -= *d;
  *m = (int)(deg * 60.);
  deg -= *m / 60.;
  *s = deg * 3600.;
}

/*!
  \brief Convert hours, min, sec to radians

  \return rad radians

  \param h radians
  \param m minutes
  \param s seconds
 */
double hms2rad(const int h, const int m, const double s)
{
  return (h + m / 60. + s / 3600.) * (M_PI / 12.);
}

/*!
  \brief Convert degrees, arcmin, arcsec to radians

  \return rad radians

  \param d degrees
  \param am arcminutes
  \param as arcseconds
 */
double dms2rad(const int d, const int am, const double as)
{
  return deg2rad((d + (am / 60.) + (as / 3600.)));
}

/*!
  \brief Convert radians to hours, min, sec

  \param h hour
  \param m minutes
  \param s seconds
  \param r radians
 */
void rad2hms(int* h, int* m, double* s, const double r)
{
  const double H = r * 12. / M_PI;

  *h = (int)H;
  *m = (int)((H - *h) * 60.);
  *s = (H - *h - (*m / 60.)) * 3600.;
}

/*!
  \brief Convert radians to degrees, min, sec

  Note, angles outside of the range [0, 2*pi) are projected onto this range.

  \param d radians
  \param m minutes
  \param s seconds
  \param r radians
 */
void rad2dms(int* d, int* m, double* s, const double r)
{
  double deg = rad2deg(r);

  *d = (int)deg;
  deg -= *d;
  *m = (int)(deg * 60.);
  deg -= *m / 60.;
  *s = deg * 3600.;
}

/*!
  \brief Project an angle onto the range [0,2*pi)

  \param phi angle in radians

  \returns angle in range [0,2*pi)
 */
double rad2circle(const double phi)
{
  double p = fmod(phi, 2*M_PI);
  
  return p < 0 ? 2*M_PI + p : p;
}

/*!
  \brief Project an angle onto the range [0,360)

  \param phi angle in radians

  \returns angle in range [0,360)
 */
double deg2circle(const double phi)
{
  double p = fmod(phi, 360.);
  
  return p < 0 ? 360. + p : p;
}

