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

bool check(u64 s, u64 x, u64 y, int b) {
  static set<tuple<u64, u64, u64, int>> check_list;

  auto key = make_tuple(s, x, y, b);
  if (check_list.count(key)) return false;

  INFO("s = %lu, x = %lu, y = %lu, b = %d", s, x, y, b);
  check_list.emplace(key);

  u64 checker = 1ull << b;
  if (x + y == s) return true;
  if (x + y > s) return false;
  if (s - (x + y) > checker) return false;

  if (b == 0) return false;

  // u64 s_bit = (s & checker) >> b;
  // u64 x_bit = (x & checker) >> b;
  // u64 y_bit = (y & checker) >> b;

  u64 diff = ((s & checker) ^ ((x + y) & checker)) >> b;
  if (diff) {
    if (b > 0)
      return check(s, x | checker, y, b) ||
             check(s, x | (checker >> 1), y, b - 1) ||
             check(s, x | (checker >> 1), y | (checker >> 1), b - 1);
    else
      return check(s, x | checker, y, b);
  } else {
    return check(s, x, y, b - 1);
  }
}

int main() {
  u64 T = read<u64>();
  for (u64 i = 0; i < T; ++i) {
    auto [a, s] = read_elems<u64, u64>();

    if (a + a > s) {
      cout << "No" << endl;
      continue;
    }

    u64 rem = s - 2 * a;
    int b = 60;
    bool is_match = true;
    while (rem) {
      u64 checker = 1ull << b;
      if (checker > rem) {
        --b;
        continue;
      }
      u64 diff = (rem & checker) >> b;
      if (diff) {
        if ((a & checker) && (a & (checker >> 1))) {
          cout << "No" << endl;
          is_match = false;
          break;
        } else {
          a |= checker >> 1;
        }
      }
    }
    if (is_match) cout << "Yes" << endl;

    // if (check(s, a, a, 60)) cout << "Yes" << endl;
    // else
    //   cout << "No" << endl;
  }
  return 0;
}