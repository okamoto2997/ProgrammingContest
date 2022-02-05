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
  auto [N, M] = read_elems<int, int>();
  graph g(N);
  for (int i = 0; i < M; ++i) {
    auto [A, B] = read_elems<int, int>();
    --A, --B;
    g.add_edge(A, B);
  }
  vector<vector<int>> ff_table(N, vector<int>(N, 0));

  for (int i = 0; i < N; ++i) {
    int total_ff = 0;
    for (auto f : g.edge[i])
      for (auto ff : g.edge[f])
        ff_table[i][ff] = 1;
    for (auto f : g.edge[i])
      ff_table[i][f] = 0;
    ff_table[i][i] = 0;
    for (int j = 0; j < N; ++j)
      total_ff += ff_table[i][j];
    cout << total_ff << endl;
  }

  return 0;
}