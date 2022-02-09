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
  string s = read<string>();
  vector<int> p_count(s.size());
  p_count[0] = 0;
  for (size_t i = 1; i < s.size(); ++i)
    p_count[i] = p_count[i - 1] + (s[i - 1] == 'g' ? 1 : -1);
  int balance = 0;
  for (auto c : s)
    if (c == 'g') balance += 1;
    else
      balance -= 1;

  const int max_score = balance / 2;

  if (max_score == 0) {
    cout << 0 << endl;
    return 0;
  }

  // how can i achive max_score ?

  int score = 0;
  int count = 0;
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    const char c = s[i];
    if (c == 'g' and count < p_count[i]) score++, count++;
    if (c == 'p' and ++count == p_count[i]) break;
  }

  cout << score << endl;

  return 0;
}