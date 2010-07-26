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

// PROJECT INCLUDES
#include <tmf.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

using namespace std;

/*!
  \brief Convert degrees, arcmin, arcsec to radians

  \param r radians
  \param d degrees
  \param am arcminutes
  \param as arcseconds
 */
void dms2r(double &r, const int &d, const int &am, const double &as)
{
  r = (d + (am / 60.) + (as / 3600.)) * (M_PI / 180.);
}

/*!
  \brief Convert radians to degrees, arcmin, arcsec

  \param d degrees
  \param am arcminutes
  \param as arcseconds
  \param r radians
 */
void dms2r(int &d, int &am, double &as, double &r)
{
  const double D = r * (180. / M_PI);

  d = int(D);
  am = int((D - d) * 60);
  as = (D - d - (am / 60.)) * 3600.;
}

/*!
  \brief Convert hours, min, sec to radians

  \param r radians
  \param h degrees
  \param m minutes
  \param s seconds
 */
void hms2r(double &r, const int &h, const int &m, const double &s)
{
  r = (h + m * 60. + s * 3600.) * (M_PI / 12.);
}

/*!
  \brief Convert radians to hours, min, sec

  \param h degrees
  \param m minutes
  \param s seconds
  \param r radians
 */
void hms2r(int &h, int &m, double &s, double &r)
{
  const double H = r * (12. / M_PI);

  h = int(H);
  m = int((H - h) * 60);
  s = (H - h - (m / 60.)) * 3600.;
}

