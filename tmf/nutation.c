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

real_t tmf_nutation(const real_t jde)
{
  int i = 0;
  real_t Dphi = 0.0;
  real_t arg = 0.0;
  const real_t T = (jde - 2451545.) / 36525.;
  const real_t T2 = T * T;
  const real_t T3 = T * T2;

  // Mean elongation of the Moon from the Sun
  const real_t D = (297.85036 + 445267.111480 * T - 0.0019142 * T2 + T3 / 189474.) * M_PI / 180.;

  // Mean anomaly of the Sun (Earth)
  const real_t M = (357.52772 + 35999.050340 * T - 0.0001603 * T2 + T3 / 300000.) * M_PI / 180.;

  // Mean anomaly of the Moon
  const real_t Mm = (134.96298 + 477198.867398 * T - 0.0086972 * T2 + T3 / 56250.) * M_PI / 180.;

  // Moon's argument of latitude
  const real_t F = (93.27191 + 483202.017538 * T - 0.0036825 * T2 + T3 / 327270.) * M_PI / 180.;

  /* Longitude of the ascending node of the Moon's mean orbit on the
     ecliptic, measured from the mean equinox of the date */
  const real_t Omega = (125.04452 - 1934.136261 * T + 0.0020708 * T2 + T3 / 450000.) * M_PI / 180.;

  /* Argument for trigonometric functions in terms of 
     multiples of D, M, Md, F, Omega */
  const int mul[63][5] = {
    { 0, 0, 0, 0, 1},
    {-2, 0, 0, 2, 2},
    { 0, 0, 0, 2, 2},
    { 0, 0, 0, 0, 2},
    { 0, 1, 0, 0, 0},
    { 0, 0, 1, 0, 0},
    {-2, 1, 0, 2, 2},
    { 0, 0, 0, 2, 1},
    { 0, 0, 1, 2, 2},
    {-2,-1, 0, 2, 2},
    {-2, 0, 1, 0, 0},
    {-2, 0, 0, 2, 1},
    { 0, 0,-1, 2, 2},
    { 2, 0, 0, 0, 0},
    { 0, 0, 1, 0, 1},
    { 2, 0,-1, 2, 2},
    { 0, 0,-1, 0, 1},
    { 0, 0, 1, 2, 1},
    {-2, 0, 2, 0, 0},
    { 0, 0,-2, 2, 1},
    { 2, 0, 0, 2, 2},
    { 0, 0, 2, 2, 2},
    { 0, 0, 2, 0, 0},
    {-2, 0, 1, 2, 2},
    { 0, 0, 0, 2, 0},
    {-2, 0, 0, 2, 0},
    { 0, 0,-1, 2, 1},
    { 0, 2, 0, 0, 0},
    { 2, 0,-1, 0, 1},
    {-2, 2, 0, 2, 2},
    { 0, 1, 0, 0, 1},
    {-2, 0, 1, 0, 1},
    { 0,-1, 0, 0, 1},
    { 0, 0, 2,-2, 0},
    { 2, 0,-1, 2, 1},
    { 2, 0, 1, 2, 2},
    { 0, 1, 0, 2, 2},
    {-2, 1, 1, 0, 0},
    { 0,-1, 0, 2, 2},
    { 2, 0, 0, 2, 1},
    { 2, 0, 1, 0, 0},
    {-2, 0, 2, 2, 2},
    {-2, 0, 1, 2, 1},
    { 2, 0,-2, 0, 1},
    { 2, 0, 0, 0, 1},
    { 0,-1, 1, 0, 0},
    {-2,-1, 0, 2, 1},
    {-2, 0, 0, 0, 1},
    { 0, 0, 2, 2, 1},
    {-2, 0, 2, 0, 1},
    {-2, 1, 0, 2, 1},
    { 0, 0, 1,-2, 0},
    {-1, 0, 1, 0, 0},
    {-2, 1, 0, 0, 0},
    { 1, 0, 0, 0, 0},
    { 0, 0, 1, 2, 0},
    { 0, 0,-2, 2, 2},
    {-1,-1, 1, 0, 0},
    { 0, 1, 1, 0, 0},
    { 0,-1, 1, 2, 2},
    { 2,-1,-1, 2, 2},
    { 0, 0, 3, 2, 2},
    { 2,-1, 0, 2, 2}
  };

  /* Coefficients of sine and cosine for Dphi in units of 0''.00001 */
  const real_t c[63] = {
    -171996 - 174.2 * T,
       -13187 - 1.6 * T,
        -2274 - 0.2 * T,
         2062 + 0.2 * T,
         1426 - 3.4 * T,
          712 + 0.1 * T,
         -517 + 1.2 * T,
         -386 - 0.4 * T,
                   -301,
          217 - 0.5 * T,
                   -158,
          129 + 0.1 * T,
                    123,
                     63,
           63 + 0.1 * T,
                    -59,
          -58 - 0.1 * T,
                    -51,
                     48,
                     46,
                    -38,
                    -31,
                     29,
                     29,
                     26,
                    -22,
                     21,
           17 - 0.1 * T,
                     16,
          -16 + 0.1 * T,
                    -15,
                    -13,
                    -12,
                     11,
                    -10,
                     -8,
                      7,
                     -7,
                     -7,
                     -7,
                      6,
                      6,
                      6,
                     -6,
                     -6,
                      5,
                     -5,
                     -5,
                     -5,
                      4,
                      4,
                      4,
                     -4,
                     -4,
                     -4,
                      3,
                     -3,
                     -3,
                     -3,
                     -3,
                     -3,
                     -3,
                     -3
  };

  // Calculate sum over sine and cosine for Dph and Depsilon respectively
  for (i=0; i<63; i++)
  {
    arg = mul[i][0] * D  + \
          mul[i][1] * M  + \
          mul[i][2] * Mm + \
          mul[i][3] * F  + \
          mul[i][4] * Omega;

    Dphi += c[i] * sin(arg);
  }

  return tmf_deg2rad(Dphi / 3.6e7);
}

real_t tmf_obliquity(const real_t jde)
{
  int i = 0;
  real_t Depsilon = 0.0;
  real_t arg = 0.0;
  const real_t T = (jde - 2451545.) / 36525.;
  const real_t T2 = T * T;
  const real_t T3 = T * T2;

  // Mean elongation of the Moon from the Sun
  const real_t D = (297.85036 + 445267.111480 * T - 0.0019142 * T2 + T3 / 189474.) * M_PI / 180.;

  // Mean anomaly of the Sun (Earth)
  const real_t M = (357.52772 + 35999.050340 * T - 0.0001603 * T2 + T3 / 300000.) * M_PI / 180.;

  // Mean anomaly of the Moon
  const real_t Mm = (134.96298 + 477198.867398 * T - 0.0086972 * T2 + T3 / 56250.) * M_PI / 180.;

  // Moon's argument of latitude
  const real_t F = (93.27191 + 483202.017538 * T - 0.0036825 * T2 + T3 / 327270.) * M_PI / 180.;

  /* Longitude of the ascending node of the Moon's mean orbit on the
     ecliptic, measured from the mean equinox of the date */
  const real_t Omega = (125.04452 - 1934.136261 * T + 0.0020708 * T2 + T3 / 450000.) * M_PI / 180.;

  /* Argument for trigonometric functions in terms of 
     multiples of D, M, Md, F, Omega */
  const int mul[38][5] = {
    { 0, 0, 0, 0, 1},
    {-2, 0, 0, 2, 2},
    { 0, 0, 0, 2, 2},
    { 0, 0, 0, 0, 2},
    { 0, 1, 0, 0, 0},
    { 0, 0, 1, 0, 0},
    {-2, 1, 0, 2, 2},
    { 0, 0, 0, 2, 1},
    { 0, 0, 1, 2, 2},
    {-2,-1, 0, 2, 2},
    {-2, 0, 0, 2, 1},
    { 0, 0,-1, 2, 2},
    { 0, 0, 1, 0, 1},
    { 2, 0,-1, 2, 2},
    { 0, 0,-1, 0, 1},
    { 0, 0, 1, 2, 1},
    { 0, 0,-2, 2, 1},
    { 2, 0, 0, 2, 2},
    { 0, 0, 2, 2, 2},
    {-2, 0, 1, 2, 2},
    { 0, 0,-1, 2, 1},
    { 2, 0,-1, 0, 1},
    {-2, 2, 0, 2, 2},
    { 0, 1, 0, 0, 1},
    {-2, 0, 1, 0, 1},
    { 0,-1, 0, 0, 1},
    { 2, 0,-1, 2, 1},
    { 2, 0, 1, 2, 2},
    { 0, 1, 0, 2, 2},
    { 0,-1, 0, 2, 2},
    { 2, 0, 0, 2, 1},
    {-2, 0, 2, 2, 2},
    {-2, 0, 1, 2, 1},
    { 2, 0,-2, 0, 1},
    { 2, 0, 0, 0, 1},
    {-2,-1, 0, 2, 1},
    {-2, 0, 0, 0, 1},
    { 0, 0, 2, 2, 1} 
  };

  /* Coefficients of sine and cosine for Depsilon in units of 0''.00001 */
  const real_t c[38] = {
     92025 + 8.9 * T,
      5736 - 3.1 * T,
       977 - 0.5 * T,
      -895 + 0.5 * T,
        54 - 0.1 * T,
                  -7,
       224 - 0.6 * T,
                 200,
       129 - 0.1 * T,
       -95 + 0.3 * T,
                 -70,
                 -53,
                 -33,
                  26,
                  32,
                  27,
                 -24,
                  16,
                  13,
                 -12,
                 -10,
                  -8,
                   7,
                   9,
                   7,
                   6,
                   5,
                   3,
                  -3,
                   3,
                   3,
                  -3,
                  -3,
                   3,
                   3,
                   3,
                   3,
                   3
  };

  // Calculate sum over sine and cosine for Dph and Depsilon respectively
  for (i=0; i<38; i++)
  {
    arg = mul[i][0] * D  + \
          mul[i][1] * M  + \
          mul[i][2] * Mm + \
          mul[i][3] * F  + \
          mul[i][4] * Omega;

    Depsilon += c[i] * cos(arg);
  }

  return tmf_deg2rad(Depsilon / 3.6e7);
}

real_t tmf_mean_obliquity(const real_t jde)
{
  real_t epsilon_0 = (23. * 3600.) + (26. * 60.) + 21.448;

  int i = 0;
  const real_t T = (jde - 2451545.) / 36525.;
  const real_t U = T / 100;
  const real_t a[10] = {
    -4680.93,
    -1.55,
     1999.25,
    -51.38,
    -249.67,
    -39.05,
     7.12,
     27.87,
     5.79,
     2.45
  };

  // Ufac = { U, U^2, U^3, ... , U^10 }
  real_t Ufac = 1.0;

  for (i=0; i<10; i++)
  {
    Ufac *= U;
    epsilon_0 += a[i]*Ufac;
  }

  return tmf_deg2rad(epsilon_0 / 3600);
}

real_t tmf_true_obliquity(const real_t jde)
{
  const real_t epsilon_0 = tmf_mean_obliquity(jde);
  const real_t Depsilon = tmf_obliquity(jde);

  return epsilon_0 + Depsilon;
}

