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
  string scr;
  for (auto c : s)
    if (c == '0') scr.push_back('0');
    else if (c == '1')
      scr.push_back('1');
    else if (scr.size())
      scr.pop_back();
  cout << scr << endl;
  return 0;
}