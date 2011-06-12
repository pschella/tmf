#include <iostream>
#include <cmath>
#include "../src/tmf.h"

using namespace std;

int main()
{
  int h = 12;
  int m = 10;
  double s = 11.3;

  cout << h << " " << m << " " << s << endl;

  double d = tmf_hms2deg(h, m, s);

  cout << "deg = " << d << endl;

  tmf_deg2hms(&h, &m, &s, d);

  cout << h << " " << m << " " << s << endl;

  // Test angles > 360
  d = 360 + 180;

  tmf_deg2hms(&h, &m, &s, d);

  cout << h << " " << m << " " << s << endl;

  // Test angles < 0
  d = -180;

  tmf_deg2hms(&h, &m, &s, d);

  cout << h << " " << m << " " << s << endl;

  // Test angles to deg, m, s
  int D = -110;
  m = 10.;
  s = 12.;

  cout << D << " " << m << " " << s << endl;

  double deg = tmf_dms2deg(D, m, s);

  cout << deg << endl;

  tmf_deg2dms(&D, &m, &s, deg);

  cout << D << " " << m << " " << s << endl;

}

