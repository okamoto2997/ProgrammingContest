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
  auto [A, B, C, D] = read_elems<int, int, int, int>();
  // exists n s.t. A + B*n <= C*n*D
  if (C * D - B <= 0) cout << -1 << endl;
  else
    cout << (u64)ceil(1.0 * A / (C * D - B)) << endl;

  return 0;
}