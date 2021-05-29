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
  auto [N, L] = read_elems<int, int>();
  vector<u64> count(N + 1, 0);
  for (int i = 0; i < min(N, L); ++i)
    count[i] = 1;
  for (int n = L; n <= N; ++n)
    count[n] = (count[n - L] + count[n - 1]) % 1000000007;
  cout << count.back() << endl;
  return 0;
}