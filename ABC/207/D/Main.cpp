#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <sys/time.h>
#include <vector>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

struct point {
  double x, y;
};

void move_to_origin(vector<point> &U) {
  point c = {0, 0};
  for (const auto &u : U)
    c.x += u.x, c.y += u.y;
  c.x /= U.size();
  c.y /= U.size();
  for (auto &u : U)
    u.x -= c.x, u.y -= c.y;
}

bool enough_near(const point &u1, const point &u2, double eps) {
  return hypot(u1.x - u2.x, u1.y - u2.y) < eps;
}

int main() {
  int N = read();
  vector<point> S(N), T(N);
  for (int n = 0; n < N; ++n)
    tie(S[n].x, S[n].y) = read_elems<int, int>();
  for (int n = 0; n < N; ++n)
    tie(T[n].x, T[n].y) = read_elems<int, int>();
  move_to_origin(S);
  move_to_origin(T);

  if (N == 1) {
    cout << "Yes" << endl;
    return 0;
  }

  INFO("S:");
  for (auto s : S)
    INFO("(%g, %g)", s.x, s.y);
  INFO("T:");
  for (auto t : T)
    INFO("(%g, %g)", t.x, t.y);

  int pivot = (S[0].x * S[0].y ? 1 : 0);

  const double eps = 1e-6;
  const double dist = hypot(S[pivot].x, S[pivot].y);
  const double theta = atan2(S[pivot].y, S[pivot].x);

  INFO("reference");
  INFO("  dist = %f, theta = %f", dist, theta);

  for (int n = 0; n < N; ++n) {
    INFO("check point %d", n);
    if (fabs(hypot(T[n].x, T[n].y) - dist) < eps) {
      INFO("dist matched:  %f vs. %f", dist, hypot(T[n].x, T[n].y));
      const double dtheta = theta - atan2(T[n].y, T[n].x);
      const double c = cos(dtheta);
      const double s = sin(dtheta);
      INFO("dtheta = %f", dtheta);
      INFO("(c, s) = (%f, %f)", c, s);
      list<point> tmp;
      for (int i = 0; i < N; ++i)
        tmp.emplace_back(
            point{T[i].x * c - T[i].y * s, T[i].x * s + T[i].y * c});

      for (int i = 0; i < N; ++i) {
        auto iter = tmp.end();
        for (iter = tmp.begin(); iter != tmp.end(); ++iter)
          if (enough_near(*iter, S[i], eps)) break;

        if (iter != tmp.end()) tmp.erase(iter);
        else {
          INFO("(%f, %f) missed", S[i].x, S[i].y);
          break;
        }
      }

      for (auto p : tmp)
        INFO("remained (%f, %f)", p.x, p.y);

      if (tmp.empty()) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  INFO("All candidates unmatched");
  cout << "No" << endl;
  return 0;
}