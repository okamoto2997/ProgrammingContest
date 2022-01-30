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
  string S = read<string>();
  S[0] = toupper(S[0]);
  for (int i = 1; i < S.size(); ++i)
    S[i] = tolower(S[i]);
  cout << S << endl;
  return 0;
}