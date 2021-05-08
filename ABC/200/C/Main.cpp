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
  vector<int> count(200, 0);
  for (int n = 0; n < N; ++n){
    int A = read();
    count[A % 200]++;
  }
  u64 ret = 0;
  for (auto a : count)
    ret += a * (a - 1) / 2;
  cout << ret << endl;
  return 0;
}