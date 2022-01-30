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
  auto X = read_vector(5);
  vector<int> sum;
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < i; ++j)
      for (int k = 0; k < j; ++k)
        sum.emplace_back(X[i] + X[j] + X[k]);
  sort(sum);

  cout << sum[sum.size() - 3] << endl;

  return 0;
}