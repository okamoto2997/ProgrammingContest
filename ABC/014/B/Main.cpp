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
  auto [n, X] = read_elems<int, int>();
  auto a = read_vector(n);
  int total = 0;
  for (int i = 0; i < n; ++i)
    total += a[i] * (X & 1), X >>= 1;
  cout << total << endl;
  return 0;
}