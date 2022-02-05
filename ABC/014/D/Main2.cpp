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

#include "lib/graph.hpp"

using namespace std;
using namespace lib;

int main() {
  int N = read();
  graph g(N);
  for (int n = 0; n < N - 1; ++n) {
    auto [x, y] = read_elems<int, int>();
    g.add_edge(x - 1, y - 1);
  }
  vector<vector<u64>> parent(ceil(log2(N)), vector<u64>(N));
  parent[0] = g.simple_tree();
  vector<u64> depth = calc_depth(parent[0]);
  for (size_t n = 1; n < parent.size(); ++n)
    for (int i = 0; i < N; ++i)
      parent[n][i] = parent[n - 1][parent[n - 1][i]];

  int Q = read();

  for (int q = 0; q < Q; ++q) {
    auto [a, b] = read_elems<int, int>();
    --a, --b;
    int loop_count = 1;
    INFO("%ld %ld", depth[a], depth[b]);
    if (u64 d = depth[a] - depth[b]; depth[a] > depth[b])
      for (size_t level = 0; level < parent.size(); ++level)
        if ((d >> level) & 1) loop_count += (1 << level), a = parent[level][a];

    if (u64 d = depth[b] - depth[a]; depth[a] < depth[b])
      for (size_t level = 0; level < parent.size(); ++level)
        if ((d >> level) & 1) loop_count += (1 << level), b = parent[level][b];

    while (a != b) {
      loop_count += depth[a] - depth[parent[0][a]];
      a = parent[0][a];
      loop_count += depth[b] - depth[parent[0][b]];
      b = parent[0][b];
    }

    cout << loop_count << endl;
  }
  return 0;
}
