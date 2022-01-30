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
  auto [N, M] = read_elems<int, int>();
  vector<vector<int>> d(N, vector<int>(N, 3000000));
  for (int i = 0; i < N; ++i)
    d[i][i] = 0;
  for (int i = 0; i < M; ++i) {
    auto [a, b, t] = read_elems<int, int, int>();
    --a, --b;
    d[a][b] = d[b][a] = t;
  }

  /// @comment Warshall-Floyd method
  for (int k = 0; k < N; ++k)
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int minmax = 3000000;
  for (int i = 0; i < N; ++i) {
    int max = 0;
    for (int j = 0; j < N; ++j)
      max = std::max(max, d[i][j]);
    minmax = min(minmax, max);
  }

  cout << minmax << endl;

  return 0;
}