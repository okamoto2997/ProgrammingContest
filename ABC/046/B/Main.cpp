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
  auto [N, K] = read_elems<int, int>();
  u64 ret = K;
  for (int n = 1; n < N; ++n)
    ret *= K - 1;
  cout << ret << endl;
  return 0;
}