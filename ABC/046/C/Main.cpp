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
  auto [t, a] = read_elems<u64, u64>();
  DEBUG("t = %ld, a = %ld", t, a);
  for (int n = 1; n < N; ++n) {
    auto [T, A] = read_elems<u64, u64>();
    // t / a <=> T / A
    // if (t * A != T * a) {
    //   const u64 p = (a + A - a % A);
    //   const u64 q = (t + T - t % T);
    //   const u64 m = min(p, q);
    //   a = max((a / (A * m) + (a % (A * m) == 0)) * A * m, A * m);
    //   t = max((t / (T * m) + (t % (T * m) == 0)) * T * m, T * m);
    // }
    const u64 m = max(a / A + (a % A != 0), t / T + (t % T != 0));
    t = T * m;
    a = A * m;
    // if (t * A > T * a) {
    //   a += A - a % A;
    //   u64 m = max(a / A, t / T + (t % T == 0));
    //   // while (m * T < t)
    //   //   ++m, a += A;
    //   a = m * A;
    //   t = m * T;
    // } else if (t * A < T * a) {
    //   t += T - t % T;
    //   u64 m = max(t / T, a / A + (a % A == 0));
    //   // while (m * A < a)
    //   //   ++m, t += T;
    //   t = m * T;
    //   a = m * A;
    // }
    DEBUG("t = %ld, a = %ld", t, a);
  }
  cout << t + a << endl;
  return 0;
}