#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  auto [N, K] = read_elems<int, int>();
  auto h = read_vector<int>(N);
  vector<int> score(N, 1e9);
  score[0] = 0;

  for (int n = 1; n < N; ++n)
    for (int k = 1; k <= min(n, K); ++k)
      score[n] = min(score[n], score[n - k] + abs(h[n] - h[n - k]));
  cout << score.back() << endl;
  return 0;
}