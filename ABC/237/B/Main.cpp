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
  int H, W;
  tie(H, W) = read_elems<int, int>();
  vector<vector<int>> A(H);
  for (auto &a : A)
    a = read_vector(W);
  for (int w = 0; w < W; ++w) {
    for (int h = 0; h < H; ++h)
      cout << (h ? " " : "") << A[h][w];
    cout << "\n";
  }
  return 0;
}