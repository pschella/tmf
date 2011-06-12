#include <iostream>
#include <cmath>

#include "../src/tmf.h"

using namespace std;

int main()
{
  double alpha = tmf_hms2rad(23, 9, 16.641);
  double delta = tmf_dms2rad(-6, -43, -11.61);
  double L = tmf_dms2rad(77, 3, 56);
  double phi = tmf_dms2rad(38, 55, 17);
  int d, h, m;
  double s, Dphi, Depsilon, epsilon;

  cout << "alpha " << tmf_rad2deg(alpha) << " delta " << tmf_rad2deg(delta) << endl;
  cout << "L " << tmf_rad2deg(L) << " phi " << tmf_rad2deg(phi) << endl;

  // Calculate JD(UT1)
  double ut = tmf_gregorian2jd(1987, 4, 10. + ((19. + 21. / 60.) / 24.));

  cout.precision(9);
  cout << "JD(UT1) " << ut << endl;

  // Calculate GMST
  double theta = tmf_rad2circle(tmf_gmst(ut));

  tmf_rad2hms(&h, &m, &s, theta);

  cout << "GMST " << theta;
  cout.precision(2);
  cout << " = " << h << " " << m << " ";
  cout.precision(6);
  cout << s <<endl;

  // Calculate precession and nutation of the ecliptic
  double dtt = tmf_delta_tt_utc(tmf_date2jd(1987, 4, 10. + ((19. + 21. / 60.) / 24.)));
  double tt = tmf_gregorian2jd(1987, 4, 10. + ((19. + 21. / 60. + dtt / 3600.) / 24.));

  cout.precision(9);
  cout << "JD(TT) " << tt << endl;

  Dphi = tmf_nutation(tt);
  Depsilon = tmf_obliquity(tt);

  epsilon = tmf_mean_obliquity(ut) + Depsilon;

  tmf_rad2dms(&d, &m, &s, epsilon);

  cout.precision(4);
  cout << "Dphi " << tmf_rad2deg(Dphi) * 3600 << " epsilon ";
  cout.precision(2);
  cout << d << " " << m << " ";
  cout.precision(4);
  cout << s << endl;

  // Calculate Greenwich Apparent Siderial Time
  double theta_0 = tmf_rad2circle(tmf_gast(ut, tt));
  tmf_rad2hms(&h, &m, &s, theta_0);

  cout.precision(2);
  cout << "GAST " << theta_0 << " = " << h << " " << m << " ";
  cout.precision(5);
  cout << s << endl;

  // Calculate Local Apparant Sidereal Time
  double theta_L = tmf_rad2circle(tmf_last(ut, tt, L));

  tmf_rad2hms(&h, &m, &s, theta_L);
  cout << "LAST " << h << " " << m << " " << s << endl;

  tmf_rad2hms(&h, &m, &s, alpha);
  cout << h << " " << m << " " << s << endl;

  // Calculate hour angle
  double H = tmf_rad2circle(theta_L - alpha);

  cout.precision(9);
  cout << "H " << tmf_rad2deg(H) << endl;

  // Calculate Altitude and Azimuth
  double A = 0.;
  double h2 = 0.;
  tmf_equatorial2horizontal(&A, &h2, H, delta, phi);

  cout.precision(5);
  cout << "A " << tmf_rad2deg(A) << " h " << tmf_rad2deg(h2) << endl;

  // Test the inverse transformations
  tmf_horizontal2equatorial(&H, &delta, A, h2, phi);

  cout.precision(9);
  cout << "H " << tmf_rad2deg(H) << endl;

  alpha = tmf_deg2circle(tmf_rad2deg(theta_L - H));

  delta = tmf_rad2deg(delta);

  cout << "alpha " << alpha << " delta " << delta << endl;
}

