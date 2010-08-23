#include <iostream>
#include <cmath>
#include "../src/tmf.h"

using namespace std;
using namespace tmf;

int main()
{
  double alpha = hms2deg(23, 9, 16.641);
  double delta = dms2deg(-6, 43, 11.61);
  double L = dms2deg(77, 3, 56);
  double phi = dms2deg(38, 55, 17);
  int d, h, m;
  double s, Dphi, Depsilon, epsilon;

  cout << "alpha " << alpha << " delta " << delta << endl;
  cout << "L " << L << " phi " << phi << endl;

  // Calculate JD(UT1)
  double ut = gregoriandate2jd(1987, 4, 10. + ((19. + 21. / 60.) / 24.));

  cout.precision(9);
  cout << "JD(UT1) " << ut << endl;

  // Calculate GMST
  double theta = gmst(ut);

  deg2hms(h, m, s, theta);

  cout << "GMST " << theta;
  cout.precision(2);
  cout << " = " << h << " " << m << " ";
  cout.precision(6);
  cout << s <<endl;

  // Calculate precession and nutation of the ecliptic
  double tt = gregoriandate2jd(1987, 4, 10. + ((19. + 21. / 60. + 55.9 / 3600.) / 24.));

  cout.precision(9);
  cout << "JD(TT) " << tt << endl;

  nutation(Dphi, Depsilon, tt);

  epsilon = meanobliquity(ut) + Depsilon / 10000;

  deg2dms(d, m, s, (epsilon / 3600));

  cout.precision(4);
  cout << "Dphi " << Dphi / 10000 << " epsilon ";
  cout.precision(2);
  cout << d << " " << m << " ";
  cout.precision(4);
  cout << s << endl;

  // Calculate Greenwich Apparent Siderial Time
  double theta_0 = gast(ut, tt);
  deg2hms(h, m, s, theta_0);

  cout.precision(2);
  cout << "GAST " << theta_0 << " = " << h << " " << m << " ";
  cout.precision(5);
  cout << s << endl;

  // Calculate Local Apparant Sidereal Time
  double theta_L = fmod(last(ut, tt, L), 360);
  theta_L = theta_L < 0 ? theta_L + 360 : theta_L;
  deg2hms(h, m, s, theta_L);

  cout << "LAST " << h << " " << m << " " << s << endl;

  deg2hms(h, m, s, alpha);

  cout << h << " " << m << " " << s << endl;

  double H = theta_L - alpha;
  H = H < 0 ? H + 360 : H;

  cout.precision(9);
  cout << "H " << H << endl;

  // Calculate Altitude and Azimuth
  double A = 0.;
  double h2 = 0.;
  equatorial2horizontal(A, h2, deg2rad(H), deg2rad(delta), deg2rad(phi));

  cout.precision(5);
  cout << "A " << rad2deg(A) << " h " << rad2deg(h2) << endl;

  // Test the inverse transformations
  horizontal2equatorial(H, delta, A, h2, deg2rad(phi));

  cout.precision(9);
  cout << "H " << rad2deg(H) << endl;

  alpha = theta_L - rad2deg(H);
  alpha = alpha < 0 ? alpha + 360 : alpha;

  delta = rad2deg(delta);

  cout << "alpha " << alpha << " delta " << delta << endl;
}

