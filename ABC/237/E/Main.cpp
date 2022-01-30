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
  int N, M;
  tie(N, M) = read_elems<int, int>();
  vector<int> H = read_vector(N);
  int bottom = *min_element(H.begin(), H.end());
  vector<int> memory(N, -2e8);
  vector<vector<int>> edges(N);
  for (int i = 0; i < M; ++i) {
    int U, V;
    tie(U, V) = read_elems<int, int>();
    --U, --V;
    edges[U].emplace_back(V);
    edges[V].emplace_back(U);
  }

  int highest_fun = 0;
  vector<int> candidate;
  candidate.emplace_back(0);
  memory[0] = 0;

  while (candidate.size()) {
    auto pos = candidate.back();
    candidate.pop_back();

    highest_fun = max(highest_fun, memory[pos]);

    if (H[pos] - bottom + memory[pos] < highest_fun) continue;

    for (auto e : edges[pos]) {
      int f = memory[pos];
      f += (H[pos] < H[e] ? 2 : 1) * (H[pos] - H[e]);
      if (memory[e] < f) {
        memory[e] = f;
        candidate.push_back(e);
      }
    }
  }

  cout << highest_fun << endl;

  return 0;
}