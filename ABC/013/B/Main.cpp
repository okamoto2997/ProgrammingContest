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
  const int a = read();
  const int b = read();
  cout << min(abs(b - a), min(abs(b - a - 10), abs(b - a + 10))) << endl;
  ;
  return 0;
}