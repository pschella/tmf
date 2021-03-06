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

real_t tmf_jd2mjd(const real_t jd) { return jd - 2400000.5; };

real_t tmf_mjd2jd(const real_t mjd) { return mjd + 2400000.5; };

real_t tmf_gregorian2jd(const int y, const int m, const real_t d)
{
  int Y;
  int M;

  if (m==1 || m==2)
  {
    Y = y - 1;
    M = m + 12;
  }
  else
  {
    Y = y;
    M = m;
  }

  int a = (int)(Y / 100);
  int b = 2-a+(int)(a/4);

  return (int)(365.25 * (Y + 4716)) + (int)(30.6001 * (M + 1)) + d + b - 1524.5;
}

real_t tmf_julian2jd(const int y, const int m, const real_t d)
{
  int Y;
  int M;

  if (m==1 || m==2)
  {
    Y = y - 1;
    M = m + 12;
  }
  else
  {
    Y = y;
    M = m;
  }

  return (int)(365.25 * (Y + 4716)) + (int)(30.6001 * (M + 1)) + d - 1524.5;
}

real_t tmf_date2jd(const int y, const int m, const real_t d)
{
  real_t jd = 0;

  // Gregorian calendar
  if (y > 1582)
  {
    jd = tmf_gregorian2jd(y, m, d);
  }
  // Julian calendar
  else if (y < 1582)
  {
    jd = tmf_julian2jd(y, m, d);
  }
  // Gregorian calendar
  else if (m > 10)
  {
    jd = tmf_gregorian2jd(y, m, d);
  }
  // Julian calendar
  else if (m < 10)
  {
    jd = tmf_julian2jd(y, m, d);
  }
  // Gregorian calendar
  else if (d >= 15)
  {
    jd = tmf_gregorian2jd(y, m, d);
  }
  // Julian calendar
  else if (d <= 4)
  {
    jd = tmf_julian2jd(y, m, d);
  }

  return jd;
}

void tmf_jd2date(int* y, int* m, real_t* d, const real_t jd)
{
  int Z, A, alpha, B, C, D, E;
  real_t JD, F;

  JD = jd+0.5;

  Z = (int)JD; // integer part
  F = JD - Z;  // fractional part

  if (Z < 2299161)
  {
    A = Z;
  }
  else
  {
    alpha = (int)((Z - 1867216.25) / 36524.25);

    A = Z + 1 + alpha - (int)(alpha / 4);
  }

  B = A + 1524;
  C = (int)((B - 122.1) / 365.25);
  D = (int)(365.25 * C);
  E = (int)((B - D) / 30.6001);

  *d = B - D - (int)(30.6001 * E) + F;
  *m = (E < 14) ? E - 1 : E - 13;
  *y = (*m > 2) ? C - 4716 : C - 4715;
}

