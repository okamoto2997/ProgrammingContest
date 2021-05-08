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
  int N = read();
  auto h = read_vector<int>(N);

  vector<int> min_score(N, 0);
  min_score[1] = abs(h[0] - h[1]);
  for (int i = 2; i < N; ++i)
    min_score[i] = min(abs(h[i] - h[i - 1]) + min_score[i - 1], abs(h[i] - h[i - 2]) + min_score[i - 2]);
  cout << min_score.back() << endl;
  return 0;
}