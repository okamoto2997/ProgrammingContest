#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int T = read();
  auto [L, X, Y] = read_elems<i64, i64, i64>();
  int Q = read();
  cout.precision(15);
  for(int q = 0; q < Q; ++q){
    int E = read();
    const double theta = 2*M_PI*E/T;
    const double x = 0;
    const double y = -0.5*L*sin(theta);
    const double z = 0.5*L*(1 - cos(theta));
    const double d_xy = hypot(X - x, Y - y);
    const double d_xyz = hypot(d_xy, 0 - z);
    cout << 360*acos(d_xy / d_xyz)/(2*M_PI) << "\n";
  }
  return 0;
}