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
#include <cmath>
#include <iostream>

// PROJECT INCLUDES
#include <tmf.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

using namespace std;

/*!
  \brief Convert hours, min, sec to degrees

  \return deg degrees

  \param h degrees
  \param m minutes
  \param s seconds
 */
double tmf::hms2deg(const int& h, const int& m, const double& s)
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
double tmf::dms2deg(const int& d, const int& am, const double& as)
{
  if (d >= 0)
  {
    return (d + (am / 60.) + (as / 3600.));
  }
  else
  {
    return (d - (am / 60.) - (as / 3600.));
  }
}

/*!
  \brief Convert degrees to hours, min, sec

  Note, angles outside of the range [0, 360) are projected onto this range.

  \param h hour
  \param m minutes
  \param s seconds
  \param d degrees
 */
void tmf::deg2hms(int& h, int& m, double& s, const double& d)
{
  // Make sure D = [0, 360)
  const double D = (d >= 0 ? fmod(d, 360.) : 360. + fmod(d, 360.));
  const double H = D * 12. / 180.;

  h = int(H);
  m = int((H - h) * 60.);
  s = (H - h - (m / 60.)) * 3600.;
}

/*!
  \brief Convert degrees to degrees, min, sec

  Note, angles outside of the range [0, 360) are projected onto this range.

  \param h hour
  \param m minutes
  \param s seconds
  \param d degrees
 */
void tmf::deg2dms(int& d, int& m, double& s, const double& deg)
{
  const double D = abs(fmod(deg, 360.));
  const int sgn = (deg >= 0) ? 1 : -1;

  d = int(D);
  m = int((D - d) * 60.);
  s = (D - d - (m / 60.)) * 3600.;

  d *= sgn;
}

