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
  int X = read<int>();
  if (X < 40) cout << 40 - X;
  else if (X < 70)
    cout << 70 - X;
  else if (X < 90)
    cout << 90 - X;
  else
    cout << "expert";
  cout << endl;
  return 0;
}