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
  vector<string> S(4, "");
  for (int i = 1; i <= 3; ++i)
    S[i] = read<string>();
  string T = read<string>();
  for (char t : T)
    cout << S[t - '0'];
  cout << endl;
  return 0;
}