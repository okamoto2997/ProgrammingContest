#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdarg>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

struct point{
  int x, y;
};

int main(){
  int N = read();
  vector<point> points(N);
  i64 max[2][2] = {};
  i64 min[2][2] = {};

  for (int n = 0; n < N; ++n){
    auto [x, y] = read_elems<int, int>();
    points[n].x = x;
    points[n].y = y;
    for (size_t t = 0; t < 2; ++t){
      int r = x * (1 - 2 * (t & 1)) + y;
      cout << "r: " << r << "\n";
      if (r >= max[t][0])
        max[t][1] = max[t][0], max[t][0] = r;
      else if (r >= max[t][1])
        max[t][1] = r;

      if (r <= min[t][0])
        min[t][1] = min[t][0], min[t][0] = r;
      else if (r <= min[t][1])
        min[t][1] = r;
    }
  }

  for (size_t t = 0; t < 2; ++t){
    cout << "max 0: " << max[t][0] << "\n";
    cout << "max 1: " << max[t][1] << "\n";
    cout << "min 0: " << min[t][0] << "\n";
    cout << "min 1: " << min[t][1] << "\n";
  }

  int en[2] = {};

  for (int n = 0; n < N; ++n){
    auto [x, y] = points[n];
    for (int t = 0; t < 2; ++t){
      for (int i = 0; i < 2; ++i){
        int r = std::max(max[t][i] - (x * (1 - 2 * (t & 1)) + y), 0l);
        cout << "r: " << r << "\n";
        if (r >= en[0])
          en[1] = en[0], en[0] = r;
        else if (r >= en[1])
          en[1] = r;

        r = std::max((x * (1 - 2 * (t & 1)) + y) - min[t][i], 0l);
        cout << "r: " << r << "\n";
        if (r >= en[0])
          en[1] = en[0], en[0] = r;
        else if (r >= en[1])
          en[1] = r;
      }
    }
    cout << endl;
  }

  cout << en[0] << "\n";
  cout << en[1] << "\n";

  return 0;
}