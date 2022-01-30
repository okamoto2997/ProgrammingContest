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

int main() {
  int N = read();
  set<int> NG;
  for (int i = 0; i < 3; ++i) {
    int ng = read();
    NG.emplace(ng);
  }

  if (NG.count(N)) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> p(N + 1, 101);
  p[N] = 0;
  for (int n = N; 0 < n; --n) {
    for (int i = 1; i <= 3 and n - i >= 0; ++i)
      if (NG.count(n - i) == 0) p[n - i] = min(p[n - i], p[n] + 1);
  }

  if (p[0] <= 100) cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}