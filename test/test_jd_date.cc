#include <iostream>
#include "../src/tmf.h"

using namespace std;

int main()
{
  double jd, d;
  int y, m;

  jd = 0;
  y = -4712;
  m = 1;
  d = 1.5;

  std::cout<<"Y "<<y<<" M "<<m<<" D "<<d<<std::endl;

  jd = tmf_date_to_jd(y, m, d);

  std::cout.precision(9);

  std::cout<<jd<<std::endl;

  int Y = 0;
  int M = 0;
  double D = 0;

  tmf_jd_to_date(&Y, &M, &D, jd);

  std::cout<<"Y "<<Y<<" M "<<M<<" D "<<D<<std::endl;
}

