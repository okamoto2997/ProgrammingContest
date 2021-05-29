#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdarg>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

void set_parent(int pivot, const vector<vector<int>>& neighbor, vector<int>& parent, vector<int>& count) {
  count[pivot] = 1;
  for (auto n : neighbor[pivot])
    if (parent[n] < 0) {
      parent[n] = pivot;
      set_parent(n, neighbor, parent, count);
      count[pivot] += count[n];
    }
}

u64 count_func(int pivot, u64 others, const vector<vector<int>>& neighbor, const vector<int>& parent, const vector<int>& count) {
  u64 ret = others * count[pivot];
  for (auto n : neighbor[pivot])
    if (n != parent[pivot])
      ret += count_func(n, others + count[pivot] - count[n], neighbor, parent, count);
  return ret;
}

int main() {
  int N = read();
  vector<vector<int>> neighbor(N);
  for (int n = 0; n < N - 1; ++n) {
    auto [a, b] = read_elems<int, int>();
    --a, --b;
    neighbor[a].emplace_back(b);
    neighbor[b].emplace_back(a);
  }
  vector<int> parent(N, -1);
  vector<int> count(N, -1);
  parent[0] = 0;
  set_parent(0, neighbor, parent, count);
  cout << count_func(0, 0, neighbor, parent, count) << endl;

  return 0;
}