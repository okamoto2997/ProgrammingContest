#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdarg>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

struct point {
  i64 x, y;
};

int main() {
  auto [N, Q] = read_elems<i64, i64>();

  vector<point> points(N);
  i64 M[4] = {};

  for (int n = 0; n < N; ++n) {
    auto [x, y] = read_elems<i64, i64>();
    points[n].x = x;
    points[n].y = y;
    M[0] = max(M[0], x + y);
    M[1] = max(M[1], y - x);
    M[2] = max(M[2], -y - x);
    M[3] = max(M[3], x - y);
  }

  for (int q = 0; q < Q; ++q) {
    int query = read();
    --query;
    auto [x, y] = points[query];
    cout << max({ M[0] - x - y, M[1] - y + x, M[2] + x + y, M[3] - x + y }) << "\n";
  }

  return 0;
}