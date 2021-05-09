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
  map<u64, u64> value;
  value[0] = 0;

  for (int n = 0; n < N; ++n){
    auto [w, v] = read_elems<int, int>();
    for (auto iter = value.rbegin(); iter != value.rend(); ++iter){
      auto& [val, weight] = *iter;
      if (weight + w <= W)
        if (value.count(v + val))
          value[v + val] = min(w + weight, value[v + val]);
        else
          value[v + val] = w + weight;
    }
  }

  for (auto& [val, weight] : value)
    cerr << val << " -> " << weight << "\n";

  cout << value.rbegin()->first << endl;

  return 0;
}