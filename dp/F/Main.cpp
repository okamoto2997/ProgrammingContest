#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  string s = read<string>();
  string t = read<string>();
  vector<vector<int>> matrix(s.size(), vector<int>(t.size(), 0));
  matrix[0][0] = (s[0] == t[0]);
  for (size_t i = 1; i < s.size(); ++i)
    matrix[i][0] = (s[i] == t[0]);
  for (size_t j = 1; j < t.size(); ++j)
    matrix[0][j] = (s[0] == t[j]);

  for (size_t i = 1; i < s.size(); ++i)
    for (size_t j = 1; j < t.size(); ++j)
      matrix[i][j] = max({ matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1] + (s[i] == t[j]) });

  cout << matrix.back().back() << endl;

  return 0;
}