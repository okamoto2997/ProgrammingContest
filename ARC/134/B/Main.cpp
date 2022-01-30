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
  int N = read<int>();
  string s = read<string>();
  vector<vector<int>> cache('z');
  for (int i = 0; i < N; ++i)
    cache[s[i] - 'a'].push_back(i);

  int right = N;
  for (int i = 0; i < right; ++i) {
    INFO("index: %d", i);
    INFO("current: %s", s.c_str());
    for (char c = 'a'; c < s[i]; ++c) {
      INFO("search for: %c", c);
      if (cache[c - 'a'].size()) {
        INFO("hit");
        int j;
        do {
          j = cache[c - 'a'].back();
          INFO("index: %d", j);
          cache[c - 'a'].pop_back();
        } while (j > right and cache[c - 'a'].size());

        if (i < j and j < right) {
          INFO("exchange: %d vs %d", i, j);
          swap(s[i], s[j]);
          right = j;
          break;
        } else {
          INFO("empty");
        }
      }
    }
  }

  // int left = 0, right = N - 1;
  // while (left < right) {
  //   char c = s[left];
  //   int i = left;
  //   for (int r = right; left < r; --r)
  //     if (s[r] < c) c = s[r], i = r;
  //   if (left != i) {
  //     INFO("swap: %d vs %d", left, i);
  //     swap(s[i], s[left]);
  //     INFO("result: %s", s.c_str());
  //     right = i - 1;
  //   } else
  //     INFO("skip");
  //   left += 1;
  // }
  cout << s << endl;
  return 0;
}