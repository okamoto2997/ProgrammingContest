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
  i64 N = read<i64>();
  i64 m = 1;
  m <<= 31;
  cout << (-m <= N and N < m ? "Yes" : "No") << endl;
  return 0;
}