#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <ctime>
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

char complement(char c) {
  switch (c) {
  case 'A':
    return 'T';
  case 'T':
    return 'A';
  case 'C':
    return 'G';
  case 'G':
    return 'C';
  default:
    exit(1);
  }
}

int main() {
  const int m = read<int>();

  for (int i = 0; i < m; ++i) {
    string s = read<string>();
    for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
      cout << complement(*iter);
    cout << "\n";
  }

  return 0;
}