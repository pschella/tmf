#include <iostream>
#include <cmath>

#include "../src/tmf.h"

using namespace std;

int main()
{
  double Dphi = 0;
  double Depsilon = 0;
  double epsilon = 0;
  double epsilon_0 = 0;
  int d, m;
  double s;

  double jde = 2446895.5;

  Dphi = tmf_nutation(jde);
    
  Depsilon = tmf_obliquity(jde);

  tmf_rad2dms(&d, &m, &s, Dphi);

  cout<<"Dphi "<<d<<" "<<m<<" "<<s<<endl;
  cout<<"Expected:"<<endl;
  cout<<"Dphi 0 0 -3.788\n"<<endl;

  tmf_rad2dms(&d, &m, &s, Depsilon);

  cout<<"Depsilon "<<d<<" "<<m<<" "<<s<<endl;
  cout<<"Expected:"<<endl;
  cout<<"Depsilon 0 0 9.443\n"<<endl;

  epsilon_0 = tmf_mean_obliquity(jde);

  tmf_rad2dms(&d, &m, &s, epsilon_0);

  cout<<"epsilon_0 "<<d<<" "<<m<<" "<<s<<endl;
  cout<<"Expected:"<<endl;
  cout<<"epsilon_0 23 26 27.407\n"<<endl;

  epsilon = epsilon_0 + Depsilon;

  tmf_rad2dms(&d, &m, &s, epsilon);

  cout<<"epsilon "<<d<<" "<<m<<" "<<s<<endl;
  cout<<"Expected:"<<endl;
  cout<<"epsilon 23 26 36.850"<<endl;
}
