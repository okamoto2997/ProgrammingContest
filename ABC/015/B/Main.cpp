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
  auto A = read_vector(N);

  int buggy_soft = 0, total_bug = 0;
  for (auto a : A)
    if (a) buggy_soft++, total_bug += a;

  cout << (int)ceil(1.0 * total_bug / buggy_soft) << endl;

  return 0;
}