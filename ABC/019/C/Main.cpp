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
  set<int> list;
  auto a = read_vector(N);
  for (int n = 0; n < N; ++n) {
    while ((a[n] & 1) == 0)
      a[n] >>= 1;
    list.emplace(a[n]);
  }
  cout << list.size() << "\n";
  return 0;
}