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
  int N, Q, X;
  tie(N, Q, X) = read_elems<int, int, int>();
  vector<int> P = read_vector(N);
  for (int q = 0; q < Q; ++q) {
    int C, L, R;
    tie(C, L, R) = read_elems<int, int, int>();
    if (C == 1) sort(P.begin() + (L - 1), P.begin() + R);
    else
      sort(P.begin() + (L - 1), P.begin() + R, greater<int>());
  }
  for (int i = 0; i < N; ++i)
    if (P[i] == X) cout << i + 1 << "\n";
  return 0;
}