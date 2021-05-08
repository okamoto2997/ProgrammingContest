#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int N = read();
  auto A = read_vector<int>(N);
  auto B = read_vector<int>(N);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  u64 ret = 0;
  for(int i = 0; i < N; ++i)
    ret += abs(A[i] - B[i]);
  cout << ret << endl;
  return 0;
}