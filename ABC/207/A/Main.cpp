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
  auto [A, B, C] = read_elems<int, int, int>();
  cout << A + B + C - min(A, min(B, C)) << "\n";
  return 0;
}