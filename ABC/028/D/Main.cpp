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
  auto [N, K] = read_elems<u64, u64>();
  u64 D = N * N * N;
  cout.precision(16);
  cout << fixed << 1.0 * (1 + 3 * (N - 1) + 6 * (K - 1) * (N - K)) / D << endl;
  return 0;
}