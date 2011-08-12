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
#include <stdlib.h>
#include <math.h>

// PROJECT INCLUDES
#include <tmf.h>

void tmf_equatorial2ecliptic(real_t* lambda, real_t* beta,
    const real_t alpha, const real_t delta,
    const real_t jde)
{
  // Get true obliquity of the ecliptic
  real_t epsilon = tmf_true_obliquity(jde);

  const real_t se = sin(epsilon);
  const real_t sa = sin(alpha);
  const real_t ca = cos(alpha);
  const real_t sd = sin(delta);
  const real_t cd = cos(delta);
  const real_t td = tan(delta);

  *lambda = atan2(sa * cd + td * se, ca);
  *beta = asin(sd * ca - cd * se * sa);
}

void tmf_ecliptic2equatorial(real_t* alpha, real_t* delta,
    const real_t lambda, const real_t beta,
    const real_t jde)
{
  // Get true obliquity of the ecliptic
  real_t epsilon = tmf_true_obliquity(jde);

  const real_t se = sin(epsilon);
  const real_t ce = cos(epsilon);
  const real_t sl = sin(lambda);
  const real_t cl = cos(lambda);
  const real_t sb = sin(beta);
  const real_t cb = cos(beta);
  const real_t tb = tan(beta);

  *alpha = atan2(sl * ce - tb * se, cl);
  *delta = asin(sb * ce + cb * se * sl);
}

