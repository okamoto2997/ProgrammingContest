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
  auto [N, W] = read_elems<int, int>();
  vector<i64> value(W + 1, -1);
  value[0] = 0;
  int max_weight = 0;
  for (int n = 0; n < N; ++n){
    auto [w, v] = read_elems<int, int>();
    for (int i = min(max_weight, W - w); i >= 0; --i)
      if (value[i] >= 0)
        value[i + w] = max<i64>(value[i + w], value[i] + v);
    max_weight = min(W, max_weight + w);
  }
  // for (int w = 0; w <= W; ++w){
  //   cerr << value[w] << " / " << w << "\n";
  // }
  cout << max<i64>(value) << endl;
  return 0;
}