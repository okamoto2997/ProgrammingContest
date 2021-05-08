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
  vector<vector<int>> happiness(3, vector<int>(N, 0));
  auto [a, b, c] = read_elems<int, int, int>();
  happiness[0][0] = a;
  happiness[1][0] = b;
  happiness[2][0] = c;
  for (int n = 1; n < N; ++n){
    auto score = read_vector<int>(3);
    for (int type = 0; type < 3; ++type)
      happiness[type][n] = score[type] + max(happiness[(type + 1) % 3][n - 1], happiness[(type + 2) % 3][n - 1]);
  }

  // for (size_t n = 0; n < N; ++n){
  //   for (size_t t = 0; t < 3; ++t)
  //     cerr << happiness[t][n] << " ";
  //   cerr << "\n";
  // }

  cout << max({ happiness[0].back(), happiness[1].back(), happiness[2].back() }) << endl;

  return 0;
}