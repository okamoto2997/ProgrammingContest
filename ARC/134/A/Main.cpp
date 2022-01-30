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
  u64 N, L, W;
  tie(N, L, W) = read_elems<uint64_t, uint64_t, uint64_t>();
  vector<u64> a = read_vector<u64>(N);
  a.push_back(L);
  u64 x = 0, count = 0;
  for (auto pos : a) {
    INFO("current sheet covers: [0, %zu]", x);
    INFO("next sheet: %zu", pos);
    if (x < pos) {
      u64 need = (pos - x) / W + ((pos - x) % W != 0 ? 1 : 0);
      count += need;
      INFO("count = %zu", need);
      x = max(x + need * W, pos + W);
    } else
      x = max(pos + W, x);
  }
  // if(L - W > x){
  //   u64 need = (L - W - x) / W + ((L - W - x) % W != 0 ? 1 : 0);
  // }
  cout << count << endl;
  return 0;
}