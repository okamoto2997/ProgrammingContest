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
  int n = read();
  auto a = read_vector(n);

  int res[] = {3, 0, 1, 0, 1, 2};

  int sum = 0;
  for (int i : a)
    sum += res[i % 6];
  cout << sum << endl;
  return 0;
}