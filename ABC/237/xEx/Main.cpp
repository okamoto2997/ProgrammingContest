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
  set<string> palindoromes;
  for (size_t i = 0; i < S.size(); ++i)
    for (size_t j = i; j < S.size(); ++j) {
      int left = i, right = j;
      bool is_palindorome = true;
      while (left <= right)
        if (S[left] == S[right]) ++left, --right;
        else {
          is_palindorome = false;
          break;
        }
      if (is_palindorome) palindoromes.emplace(S.substr(i, j - i + 1));
    }

  multimap<int, string> data;
  for (const auto &s : palindoromes) {
    data.emplace(s.size(), s);
  }

  int palindorome_count = 0;

  for (auto iter = data.begin(); iter != data.end(); ++iter) {
    INFO("length: %d", iter->first);
    INFO("'%s'", iter->second.c_str());
    const string &s = iter->second;
    auto subiter = iter;
    subiter++;
    int sub_count = 0;
    while (subiter != data.end()) {
      if (subiter->second.find(s) != string::npos) sub_count++;
      if (sub_count > 1) break;
      ++subiter;
    }
    if (sub_count == 0) {
      palindorome_count += 1;
      auto subiter = iter;
      subiter++;
      for (; subiter != data.end(); ++subiter)
        if (subiter->second.find(s) != string::npos) {
          data.erase(subiter);
          break;
        }
    }
  }

  cout << palindorome_count << endl;

  return 0;
}