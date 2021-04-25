#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

constexpr int digit_sum(int n){
  int ret = 0;
  while (n)
    ret += n % 10, n /= 10;
  return ret;
}

int main(){
  auto [N, A, B] = read_elems<int, int, int>();
  int ret = 0;
  for (int n = 1; n <= N; ++n){
    int sum = digit_sum(n);
    ret += (A <= sum && sum <= B ? n : 0);
  }
  cout << ret << endl;
  return 0;
}