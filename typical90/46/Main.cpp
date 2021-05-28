#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdarg>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main() {
  int N = read();
  auto A = read_vector<int>(N);
  auto B = read_vector<int>(N);
  auto C = read_vector<int>(N);
  vector<u64> a(46, 0), b(46, 0), c(46, 0);
  for (int n = 0; n < N; ++n) {
    ++a[A[n] % 46];
    ++b[B[n] % 46];
    ++c[C[n] % 46];
  }
  u64 ret = 0;
  for (int i = 0; i < 46; ++i)
    for (int j = 0; j < 46; ++j)
      ret += a[i] * b[j] * c[(92 - i - j) % 46];

  cout << ret << endl;

  return 0;
}