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
  u64 N = read<u64>();

  u64 digit = 10;
  u64 total = 0;

  while (N >= digit) {
    total = (total + ((digit - digit / 10) % mod2) *
                         ((digit + 1 - digit / 10) % mod2) / 2) %
            mod2;
    digit *= 10;
  }
  digit /= 10;
  total =
      (total + ((N + 1 - digit) % mod2) * ((N + 2 - digit) % mod2) / 2) % mod2;

  cout << total << endl;

  return 0;
}