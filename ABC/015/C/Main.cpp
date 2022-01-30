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
  auto [N, K] = read_elems<int, int>();
  vector<vector<int>> T(N);
  for (auto &t : T)
    t = read_vector(K);
  int bound = pow(K, N);
  int i = 0;
  while (i < bound) {
    int choice = i;
    int result = 0;
    for (int n = 0; n < N; ++n) {
      result ^= T[n][choice % K];
      choice /= K;
    }
    if (result == 0) {
      cout << "Found" << endl;
      return 0;
    }
    ++i;
  }
  cout << "Nothing" << endl;
  return 0;
}