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
  int left = 0, right = S.size() - 1;
  while (S[left] == 'a' and left < S.size())
    ++left;
  while (S[right] == 'a' and 0 <= right)
    --right;

  if (left > (S.size() - 1 - right)) {
    cout << "No" << endl;
    return 0;
  }

  while (left < right)
    if (S[left] == S[right]) ++left, --right;
    else {
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;

  return 0;
}