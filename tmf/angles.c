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

real_t tmf_hav(const real_t theta) { return (1 - cos(theta)) / 2; };

real_t tmf_ahav(const real_t a) { return acos(1 - 2 * a); };

real_t tmf_deg2rad(const real_t a) { return a * M_PI / 180.; };

real_t tmf_rad2deg(const real_t a) { return a * 180. / M_PI; };

real_t tmf_hms2deg(const int h, const int m, const real_t s)
{
  return (h + m / 60. + s / 3600.) * (180. / 12.);
}

real_t tmf_dms2deg(const int d, const int am, const real_t as)
{
  return (d + (am / 60.) + (as / 3600.));
}

void tmf_deg2hms(int* h, int* m, real_t* s, const real_t d)
{
  // Make sure D = [0, 360)
  const real_t D = (d >= 0 ? fmod(d, 360.) : 360. + fmod(d, 360.));
  const real_t H = D * 12. / 180.;

  *h = (int)H;
  *m = (int)((H - *h) * 60.);
  *s = (H - *h - (*m / 60.)) * 3600.;
}

void tmf_deg2dms(int* d, int* m, real_t* s, real_t deg)
{
  *d = (int)deg;
  deg -= *d;
  *m = (int)(deg * 60.);
  deg -= *m / 60.;
  *s = deg * 3600.;
}

real_t tmf_hms2rad(const int h, const int m, const real_t s)
{
  return (h + m / 60. + s / 3600.) * (M_PI / 12.);
}

real_t tmf_dms2rad(const int d, const int am, const real_t as)
{
  return tmf_deg2rad((d + (am / 60.) + (as / 3600.)));
}

void tmf_rad2hms(int* h, int* m, real_t* s, const real_t r)
{
  const real_t H = r * 12. / M_PI;

  *h = (int)H;
  *m = (int)((H - *h) * 60.);
  *s = (H - *h - (*m / 60.)) * 3600.;
}

void tmf_rad2dms(int* d, int* m, real_t* s, const real_t r)
{
  real_t deg = tmf_rad2deg(r);

  *d = (int)deg;
  deg -= *d;
  *m = (int)(deg * 60.);
  deg -= *m / 60.;
  *s = deg * 3600.;
}

real_t tmf_rad2circle(const real_t phi)
{
  real_t p = fmod(phi, 2*M_PI);
  
  return p < 0 ? 2*M_PI + p : p;
}

real_t tmf_deg2circle(const real_t phi)
{
  real_t p = fmod(phi, 360.);
  
  return p < 0 ? 360. + p : p;
}

