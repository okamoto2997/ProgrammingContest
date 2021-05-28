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
  auto [t, N] = read_elems<int, int>();
  DEBUG("N = %d", N);
  const int res = N % t;
  DEBUG("res = %d", res);
  const int quotient = (N / t);
  DEBUG("quot = %d", quotient);
  u64 price = (u64)quotient * 100;
  DEBUG("price = %lu", price);
  u64 prev_price = (u64)quotient * (100 + t);
  DEBUG("taxed price = %lu", prev_price);
  int count = 0;
  while (count < res){
    if (price * (100 + t) / 100 - prev_price > 1){
      DEBUG("taxed price: %lu", price * (100 + t) / 100);
      DEBUG("prev. taxed price: %lu", prev_price);
      ++count;
    }
    prev_price = price * (100 + t) / 100;
    price++;
  }
  cout << prev_price - 1 << endl;
  return 0;
}