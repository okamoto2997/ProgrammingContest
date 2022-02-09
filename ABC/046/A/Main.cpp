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
  auto abc = read_vector(3);
  if (abc[0] == abc[1] and abc[1] == abc[2]) cout << 1 << endl;
  else if (abc[0] == abc[1] or abc[1] == abc[2] or abc[2] == abc[0])
    cout << 2 << endl;
  else
    cout << 3 << endl;
  return 0;
}