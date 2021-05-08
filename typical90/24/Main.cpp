#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main()
{
  auto [N, K] = read_elems<int, int>();
  vector<int> A = read_vector<int>(N);
  vector<int> B = read_vector<int>(N);
  int diff = 0;
  for (int i = 0; i < N; ++i)
    diff += abs(A[i] - B[i]);
  cout << (diff <= K && ((K - diff) & 1) == 0 ? "Yes" : "No") << endl;
  return 0;
}