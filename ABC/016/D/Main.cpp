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

struct segment {
  i64 Ax, Ay, Bx, By;

  i64 operator()(i64 x, i64 y) const {
    // a x + b y + c
    return (Ax - Bx) * y - (Ay - By) * x - Ax * By + Bx * Ay;
  }
};

bool is_cross(const segment &s1, const segment &s2) {
  return (s1(s2.Ax, s2.Ay) * s1(s2.Bx, s2.By) < 0) and
         (s2(s1.Ax, s1.Ay) * s2(s1.Bx, s1.By) < 0);
}

int main() {
  segment slash;
  tie(slash.Ax, slash.Ay, slash.Bx, slash.By) =
      read_elems<i64, i64, i64, i64>();
  int N = read();
  vector<pair<i64, i64>> polygon(N);
  for (int n = 0; n < N; ++n)
    tie(polygon[n].first, polygon[n].second) = read_elems<i64, i64>();

  segment edge;
  edge.Ax = polygon.back().first;
  edge.Ay = polygon.back().second;
  int cross_count = 0;
  for (int n = 0; n < N; ++n) {
    edge.Bx = edge.Ax;
    edge.By = edge.Ay;
    edge.Ax = polygon[n].first;
    edge.Ay = polygon[n].second;
    if (is_cross(edge, slash)) cross_count++;
  }

  DEBUG("cross: %d", cross_count);

  cout << 1 + cross_count / 2 << endl;

  return 0;
}