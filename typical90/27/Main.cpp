#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main()
{
  int N = read();
  set<string> user_list;
  for (int n = 1; n <= N; ++n)
  {
    string S = read<string>();
    if (user_list.find(S) == user_list.end())
    {
      cout << n << "\n";
      user_list.emplace(move(S));
    }
  }
  return 0;
}