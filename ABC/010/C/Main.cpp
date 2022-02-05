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
  auto [txa, tya, txb, tyb, T, V] = read_elems<int, int, int, int, int, int>();
  int n = read();
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i)
    tie(x[i], y[i]) = read_elems<int, int>();

  for (int i = 0; i < n; ++i)
    if (hypot(txa - x[i], tya - y[i]) + hypot(txb - x[i], tyb - y[i]) <=
        T * V) {
      cout << "YES" << endl;
      return 0;
    }
  cout << "NO" << endl;
}