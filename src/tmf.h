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
#include <exception>
#include <cmath>

// PROJECT INCLUDES
//

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

namespace tmf
{
  /* exception handling */
  class Error : public std::exception {};

  class InputError : public Error {};
  
  /* inlines (for increased speed) */
  inline double deg2rad(const double& a) { return a * M_PI / 180; };

  inline double rad2deg(const double& a) { return a * 180 / M_PI; };

  /* angles.cc */
  double hms2deg(const int& h, const int& m, const double& s);

  double dms2deg(const int& d, const int& am, const double& as);

  void deg2hms(int& h, int& m, double& s, const double& d);

  void deg2dms(int& d, int& m, double& s, const double& d);

  double hms2rad(const int& h, const int& m, const double& s);
  
  double dms2rad(const int& d, const int& am, const double& as);

  void rad2hms(int& h, int& m, double& s, const double& r);

  void rad2dms(int& d, int& m, double& s, const double& r);

  /* cartesian_logpolar.cc */
  void logpolar2cartesian(double& x, double& y, const double& rho, const double& theta);

  void cartesian2logpolar(double& rho, double& theta, const double& x, const double& y);

  /* cartesian_polar.cc */
  void polar2cartesian(double& x, double& y, const double& r, const double& theta);

  void cartesian2polar(double& r, double& theta, const double& x, const double& y);

  /* cartesian_spherical.cc */
  void spherical2cartesian(double& x, double& y, double& z, const double& rho, const double& theta, const double& phi);

  void cartesian2spherical(double& rho, double& theta, double& phi, const double& x, const double& y, const double& z);

  /* cylindrical_spherical.cc */
  void spherical2cylindrical(double r, double h, const double& rho, const double& phi);

  void spherical2cylindrical(double& rho, double& phi, const double& r, const double& h);

  /* equatorial_horizontal.cc */
  void equatorial2horizontal(double& A, double& h, const double& H, const double& delta, const double& phi);

  void horizontal2equatorial(double& H, double& delta, const double& A, const double& h, const double& phi);

  /* jd_date.cc */
  double gregoriandate2jd(const int& y, const int& m, const double& d);

  double juliandate2jd(const int& y, const int& m, const double& d);

  double date2jd(const int& y, const int& m, const double& d);

  void jd2date(int& y, int& m, double& d, const double& jd);

  /* jd_mjd.cc */
  void jd2mjd(double& mjd, const double& jd);

  void mjd2jd(double& jd, const double& mjd);

  /* nutation.cc */
  void nutation(double& Dphi, double& Depsilon, const double& jde);

  double meanobliquity(const double& jde);

  /* sidereal_time.cc */
  double gmst(const double& jd);

  double gast(const double& jd, const double& jde);

  double last(const double& jd, const double& jde, const double& L);
} // End tmf

#endif // TMF_H

