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
  int W = read();
  auto [N, K] = read_elems<int, int>();
  vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i)
    tie(A[i], B[i]) = read_elems<int, int>();
  vector<vector<int>> importantness(K + 1, vector<int>(W + 1, 0));
  for (int i = 0; i < N; ++i)
    for (int k = K - 1; 0 <= k; --k)
      for (int w = W - A[i]; 0 <= w; --w)
        if (k == 0 or w == 0 or importantness[k][w])
          importantness[k + 1][w + A[i]] =
              max(importantness[k + 1][w + A[i]], importantness[k][w] + B[i]);
  int max_importantness = 0;
  for (int k = 0; k <= K; ++k)
    for (int w = 0; w <= W; ++w)
      max_importantness = max(max_importantness, importantness[k][w]);
  cout << max_importantness << endl;
  return 0;
}