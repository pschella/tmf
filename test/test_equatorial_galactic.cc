#include <iostream>
#include <cmath>
#include "../src/tmf.h"

using namespace std;

int main()
{
  double alpha = tmf_hms2rad(17, 48, 59.74);
  double delta = tmf_dms2rad(-14, 43, 8.2);
  double l = 0.0;
  double b = 0.0;

  /************************************************************************
   * Test of B1950 coordinate conversion                                  *
   ************************************************************************/

  cout << "alpha = " << tmf_rad2deg(alpha) << " delta = " << tmf_rad2deg(delta) << " (degrees)" << endl;

  cout << "alpha = " << alpha << " delta = " << delta << " (radians)" << endl;

  tmf_equatorial2galactic(&l, &b, alpha, delta);

  cout << "l = " << tmf_rad2deg(l) << " b = " << tmf_rad2deg(b) << endl;

  tmf_galactic2equatorial(&alpha, &delta, l, b);

  cout << "alpha = " << alpha << " delta = " << delta << " (radians)" << endl;

  cout << "alpha = " << tmf_rad2deg(alpha) << " delta = " << tmf_rad2deg(delta) << " (degrees)" << endl;

  /************************************************************************
   * Test of J2000 coordinate conversion                                  *
   ************************************************************************/

  double alpha_J = 0.0;
  double delta_J = 0.0;

  cout << "(B1950) alpha = " << tmf_rad2deg(alpha) << " delta = " << tmf_rad2deg(delta) << " (degrees)" << endl;

  tmf_b19502j2000(&alpha_J, &delta_J, alpha, delta);

  cout << "(J2000) alpha = " << tmf_rad2deg(alpha_J) << " delta = " << tmf_rad2deg(delta_J) << " (degrees)" << endl;

  tmf_j20002b1950(&alpha, &delta, alpha_J, delta_J);

  cout << "(B1950) alpha = " << tmf_rad2deg(alpha) << " delta = " << tmf_rad2deg(delta) << " (degrees)" << endl;

//  cout << "alpha = " << tmf_rad2hmsrepr(alpha_J) << " delta = " << tmf_rad2dmsrepr(delta_J) << " (degrees)" << endl;
//  cout << "l = " << tmf_rad2dmsrepr(l) << " b = " << tmf_rad2dmsrepr(b) << endl;
}

