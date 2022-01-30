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
  const int N = read();
  if (N < 60) cout << "Bad";
  else if (N < 90)
    cout << "Good";
  else if (N < 100)
    cout << "Great";
  else
    cout << "Perfect";
  cout << endl;
  return 0;
}