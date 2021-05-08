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

u64 count_2(u64 N, u64 k){
  if (k > 2 * N) return 0;
  return min<i64>(max<i64>(k - 2 * N + 1, 0), k + 1);
}

u64 count_3(u64 N, u64 k){
  if (k > 3 * N) return 0;
  u64 ret = 0;
  for (int i = max<i64>(0, k - 2 * N); i <= k; ++i)
    ret += count_2(N, k - i);
  cerr << "k  : " << k << "\n";
  cerr << "ret: " << ret << "\n";
  return ret;
}

int main(){
  auto [N, K] = read_elems<u64, u64>();

  u64 k = 0;
  while (true){
    u64 c = count_3(N - 1, k);
    if (K >= c)
      K -= c;
    else
      break;
    ++k;
  }

  cerr << "opt score: " << k << "\n";
  cerr << "remain   : " << K << "\n";

  u64 i = 0;
  while (true){
    u64 c = count_2(N - 1, k - i);
    cerr << "i : " << i << "\n";
    cerr << "c : " << c << "\n";
    if (K >= c)
      K -= c;
    else
      break;
    ++i;
  }

  cout << 1 + i << " " << 1 + K << " " << 1 + (k - K - i) << "\n";

  return 0;
}