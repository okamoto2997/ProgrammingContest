#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdarg>
#include <numeric>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main() {
  int N = read();
  u64 ret = 1;
  for (int n = 0; n < N; ++n) {
    auto A = read_vector<u64>(6);
    ret = (ret * accumulate(A.begin(), A.end(), 0)) % mod;
  }
  cout << ret << endl;
  return 0;
}