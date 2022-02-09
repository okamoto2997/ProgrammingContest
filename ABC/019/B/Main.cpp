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
  char prev = s[0];
  int count = 1;
  for (size_t i = 1; i < s.size(); ++i)
    if (s[i] == prev) count++;
    else {
      cout << prev << count;
      prev = s[i];
      count = 1;
    }
  cout << prev << count << endl;
  return 0;
}