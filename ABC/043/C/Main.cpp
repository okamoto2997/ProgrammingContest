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
  auto a = read_vector(N);
  int min_total_cost = 1e8;
  for (int ave = -100; ave <= 100; ++ave) {
    int cost = 0;
    for (int _a : a)
      cost += (_a - ave) * (_a - ave);
    min_total_cost = min(min_total_cost, cost);
  }
  cout << min_total_cost << endl;
  return 0;
}