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
  string s = read<string>();

  for (size_t i = 1; i < s.size(); ++i)
    if (s[i] == s[i - 1]) {
      cout << i << " " << i + 1 << endl;
      return 0;
    }
  for (size_t i = 2; i < s.size(); ++i)
    if (s[i] == s[i - 2]) {
      cout << i - 1 << " " << i + 1 << endl;
      return 0;
    }
  cout << "-1 -1" << endl;
  return 0;
}