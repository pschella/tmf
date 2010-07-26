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
#include <cmath>

// PROJECT INCLUDES
//

// LOCAL INCLUDES
//

// FORWARD REFERENCES
//

namespace tmf
{
  void gregoriandate2jd(double &jd, const int &y, const int &m, const double &d);

  void juliandate2jd(double &jd, const int &y, const int &m, const double &d);

  void date2jd(double &jd, const int &y, const int &m, const double &d);

  void jd2date(int &y, int &m, double &d, const double &jd);


  /* Inline functions */

  inline void jd2mjd(double &mjd, const double &jd) { mjd = jd - 2440000.5; };

  inline void mjd2jd(double &jd, const double &mjd) { jd = mjd + 2440000.5; };
} // End tmf

#endif // TMF_H

