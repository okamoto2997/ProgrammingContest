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
  string X = read<string>();
  string rev = "abcdefghijklmnopqrstuvwxyz";
  for (char &c : rev)
    c = X[c - 'a'];
  cout << X << "\n";
  cout << rev << "\n";
  return 0;
}