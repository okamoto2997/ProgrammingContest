#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int N = read();
  int cur_t = 0, cur_x = 0, cur_y = 0;
  bool impossibble = false;
  for (size_t n = 0; n < N; ++n){
    auto [t, x, y] = read_elems<int, int, int>();
    impossibble |= (t % 2 != (x + y) % 2);
    impossibble |= (t - cur_t) < abs(x - cur_x) + abs(y - cur_y);
    if (impossibble) break;
    cur_t = t;
    cur_x = x;
    cur_y = y;
  }
  cout << (impossibble ? "No" : "Yes") << endl;
  return 0;
}