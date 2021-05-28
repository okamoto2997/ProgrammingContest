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
  int res = 2025 - N;
  vector<string> ans;
  for (int n = 1; n <= 9; ++n)
    if (res % n == 0 && res / n < 10)
      ans.emplace_back(strprintf("%d x %d", n, res / n));
  sort(ans);
  cout << print(ans, '\n') << endl;
  return 0;
}