#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <deque>
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
  string S = read<string>();

  deque<int> former, later;
  for (int i = 0; i < N; ++i)
    if (S[i] == 'L') later.push_front(i);
    else
      former.push_back(i);

  for (auto i : former)
    cout << i << " ";
  cout << N;
  for (auto i : later)
    cout << " " << i;
  cout << endl;

  return 0;
}