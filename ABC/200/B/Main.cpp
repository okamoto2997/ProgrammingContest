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
  u64 n = N;
  for (int k = 0; k < K; ++k){
    if (n % 200 == 0)
      n /= 200;
    else
      n = n * 1000 + 200;
  }
  cout << n << endl;
  return 0;
}