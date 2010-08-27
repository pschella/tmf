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
#include <boost/python.hpp>

// PROJECT INCLUDES
#include <tmf.h>

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

using namespace tmf;

BOOST_PYTHON_MODULE(pytmf)
{
    using namespace boost::python;
    def("deg2rad", deg2rad);
    def("rad2deg", rad2deg);
    def("jd2mjd", jd2mjd);
    def("mjd2jd", mjd2jd);
    def("hms2deg", hms2deg);
    def("deg2hms", deg2hms);
    def("deg2dms", deg2dms);
    def("hms2rad", hms2rad);
    def("dms2rad", dms2rad);
    def("rad2hms", rad2hms);
    def("rad2dms", rad2dms);
    def("rad2circle", rad2circle);
    def("deg2circle", deg2circle);
    def("rad2hmsrepr", rad2hmsrepr);
    def("rad2dmsrepr", rad2hmsrepr);
    def("j20002b1950", j20002b1950);
    def("b19502j2000", b19502j2000);
    def("logpolar2cartesian", logpolar2cartesian);
    def("cartesian2logpolar", cartesian2logpolar);
    def("spherical2cartesian", spherical2cartesian);
    def("cartesian2spherical", cartesian2spherical);
    def("equatorial2horizontal", equatorial2horizontal);
    def("horizontal2equatorial", horizontal2equatorial);
    def("gregoriandate2jd", gregoriandate2jd);
    def("juliandate2jd", juliandate2jd);
    def("date2jd", date2jd);
    def("jd2date", jd2date);
    def("nutation", nutation);
    def("meanobliquity", meanobliquity);
    def("gmst", gmst);
    def("gast", gast);
    def("last", last);
    def("equatorial2galactic", equatorial2galactic);
    def("galactic2equatorial", galactic2equatorial);
    def("tai_utc", tai_utc);
    def("tt_utc", tt_utc);
}

