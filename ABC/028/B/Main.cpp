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
  string S = read<string>();
  vector<int> count(6, 0);
  for (auto s : S)
    count[s - 'A']++;
  for (int i = 0; i < 6; ++i)
    cout << (i ? " " : "") << count[i];
  cout << endl;
  return 0;
}