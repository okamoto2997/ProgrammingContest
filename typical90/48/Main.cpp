#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdarg>
#include <queue>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main() {
  auto [N, K] = read_elems<int, int>();
  vector<u64> score(K, 0);
  vector<u64> A(N), B(N);
  priority_queue<pair<u64, int>> target;
  for (int n = 0; n < N; ++n) {
    tie(A[n], B[n]) = read_elems<int, int>();
    target.push({ B[n], n });
  }

  vector<int> progress(N, 0);

  u64 total_score = 0;

  for (int k = 0; k < K; ++k) {
    auto [score, index] = target.top(); target.pop();
    total_score += score;
    if (++progress[index] == 1)
      target.push({ A[index] - B[index], index });
  }

  cout << total_score << endl;

  return 0;
}