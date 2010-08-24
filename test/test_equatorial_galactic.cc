#include <iostream>
#include <cmath>
#include "../src/tmf.h"

using namespace std;
using namespace tmf;

int main()
{
  double alpha = hms2rad(17, 48, 59.74);
  double delta = dms2rad(-14, 43, 8.2);
  double l = 0.0;
  double b = 0.0;

  cout << "alpha = " << rad2deg(alpha) << " delta = " << rad2deg(delta) << " (degrees)" << endl;

  cout << "alpha = " << alpha << " delta = " << delta << " (radians)" << endl;

  equatorial2galactic(l, b, alpha, delta);

  cout << "l = " << rad2deg(l) << " b = " << rad2deg(b) << endl;

  galactic2equatorial(alpha, delta, l, b);

  cout << "alpha = " << alpha << " delta = " << delta << " (radians)" << endl;

  cout << "alpha = " << rad2deg(alpha) << " delta = " << rad2deg(delta) << " (degrees)" << endl;
}

