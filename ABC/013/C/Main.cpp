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
  auto [N, H] = read_elems<i64, i64>();
  auto [A, B, C, D, E] = read_elems<i64, i64, i64, i64, i64>();

  // 断食
  int h = H - N * E;
  if (h > 0) {
    cout << 0 << endl;
    return 0;
  }

  const double low_dish_eff = 1.0 * C / (D + E);
  const double normal_dish_eff = 1.0 * A / (D + E);

  int N1 = 0, H1 = 0;
  int cost1 = 0;
  if (low_dish_eff >= normal_dish_eff) {
    N1 = -h * low_dish_eff;
    H1 = H - (N - N1) * E + N1 * D;
    cost1 = N1 * C;
  } else {
    N1 = -h * normal_dish_eff;
    H1 = H - (N - N1) * E + N1 * B;
    cost1 = N1 * A;
  }

  if (H > 0) return 0;
}