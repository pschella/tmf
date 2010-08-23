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
using namespace tmf;

/*!
  \brief Get Greanwich Mean Sidereal Time (GMST) in degrees from UT1.

  \return theta Greanwich Mean Sidereal Time in degrees

  \param jd Julian Date of UT1
 */
double tmf::gmst(const double& jd)
{
  const double T = (jd - 2451545.) / 36525.;

  return 280.46061837 + 360.98564736629 * (jd - 2451545.0) + 0.000387933 * T * T - (T * T * T / 38710000.);
}

/*!
  \brief Get Greenwich Apparent Sidereal Time (GAST) in degrees from UT1.

  \return theta Greenwich Apparent Sidereal Time in degrees

  \param jd Julian Date of UT1
  \param jde Julian Date of TD (or equivalently TT)
 */
double tmf::gast(const double& jd, const double& jde)
{
  double Dphi = 0.0;
  double Depsilon = 0.0;

  // Get mean obliquity of the ecliptic
  double epsilon = meanobliquity(jde);

  // Get nutation and deviaton for obliquity of the ecliptic
  nutation(Dphi, Depsilon, jde);

  // Correct Dphi to arc seconds
  Dphi /= 10000;

  // Correct for effect of nutation and correct to radians
  epsilon += (Depsilon / 10000);
  epsilon *= M_PI / (180 * 3600);

  // Get Greenwhich Mean Siderial Time and add equation of the equinoxes
  return gmst(jd) + Dphi * cos(epsilon) / 3600;
}

/*!
  \brief Get Local Apparent Sidereal Time (LAST) in degrees from UT1.

  \return theta Local Aparrent Sidereal Time in degrees

  \param jd Julian Date of UT1
  \param jde Julian Date of TD (or equivalently TT)
  \param L observer's longitude (positive west, negative east
         from Greenwich)
 */
double tmf::last(const double& jd, const double& jde, const double& L)
{
  /* Get Greenwich Apparent Siderial Time
     and correct for observer's longitude */
  return gast(jd, jde) - L;
}

