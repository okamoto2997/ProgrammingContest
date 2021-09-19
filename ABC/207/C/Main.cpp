#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sys/time.h>
#include <vector>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

bool is_crossed(int i, int j, const vector<pair<double, double>> &intvs) {
  return !(intvs[i].second < intvs[j].first ||
           intvs[j].second < intvs[i].first);
}

int main() {
  int N = read();
  vector<pair<double, double>> intvs(N);
  int count = 0;
  for (int n = 0; n < N; ++n) {
    auto [t, l, r] = read_elems<int, int, int>();
    --t;
    INFO("type: %d", t);
    intvs[n].first = l + 0.01 * ((t & 2) >> 1);
    intvs[n].second = r - 0.01 * (t & 1);
    INFO("interval: [%f, %f]", intvs[n].first, intvs[n].second);
    for (int m = 0; m < n; ++m)
      count += is_crossed(m, n, intvs);
  }
  cout << count << endl;

  return 0;
}