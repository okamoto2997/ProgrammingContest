#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int index(const vector<int>& coin){
  return coin[0] * 10000 + coin[1] * 100 + coin[2];
}

size_t count(int X, int current, vector<int>& coin, set<int>& log, const vector<int>& limit, const vector<int>& price){
  log.emplace(index(coin));
  if (current == X) return 1;

  int ret = 0;

  for (int i = 0; i < 3; ++i){
    if (coin[i] + 1 > limit[i]) continue;
    if (current + price[i] > X) continue;
    ++coin[i];
    if (log.find(index(coin)) == log.end())
      ret += count(X, current + price[i], coin, log, limit, price);
    --coin[i];
  }

  return ret;
}

int main(){
  auto [A, B, C] = read_elems<int, int, int>();
  auto X = read<int>();

  vector<int> limit = { A, B, C };
  vector<int> price = { 500, 100, 50 };
  vector<int> coin = { 0, 0, 0 };
  set<int> log;

  cout << count(X, 0, coin, log, limit, price) << endl;

  return 0;
}