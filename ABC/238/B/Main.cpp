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
  int N = read();
  vector<bool> cut(360, false);
  cut[0] = true;
  int prev = 0;
  for (int i = 0; i < N; ++i) {
    prev = (prev + read()) % 360;
    cut[prev] = true;
  }

  int angle = 1, max_angle = 1;
  for (int i = 0; i < 360; ++i)
    if (cut[i]) angle = 1;
    else
      ++angle, max_angle = max(max_angle, angle);

  cout << max_angle << endl;

  return 0;
}