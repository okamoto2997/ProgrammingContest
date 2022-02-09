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
  int max_diam = 0, max_idx = 0;
  for (int n = 2; n <= N; ++n) {
    cout << "? " << 1 << " " << n << endl;
    int diam = read();
    INFO("%d", diam);
    if (max_diam < diam) max_diam = diam, max_idx = n;
  }
  for (int n = 1; n <= N; ++n)
    if (n != max_idx) {
      cout << "? " << max_idx << " " << n << endl;
      int diam = read();
      INFO("%d", diam);
      if (max_diam < diam) max_diam = diam;
    }
  cout << "! " << max_diam << endl;
  return 0;
}