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
  auto [N, Q] = read_elems<int, int>();
  auto A = read_vector<int>(N);
  int shift = 0;
  for (int q = 0; q < Q; ++q) {
    auto [T, x, y] = read_elems<int, int, int>();
    switch (T) {
    case 1:
      swap(A[(x - 1 - shift + 2 * N) % N], A[(y - 1 - shift + 2 * N) % N]);
      break;
    case 2:
      shift++;
      break;
    case 3:
      cout << A[(x - 1 - shift + 2 * N) % N] << "\n";
      break;
    }
  }
  cout << flush;
  return 0;
}