#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  auto [N, D, H] = read_elems<int, int, int>();
  double height = 0;
  for (size_t n = 0; n < N; ++n){
    auto [d, h] = read_elems<int, int>();
    height = max(height, h - 1.0 * (H - h) / (D - d) * d);
  }
  cout.precision(15);
  cout << height << endl;
  return 0;
}