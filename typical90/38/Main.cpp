#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdarg>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main() {
  auto [A, B] = read_elems<u64, u64>();
  u64 N = A / gcd(A, B) * B;
  if ((N / B != A / gcd(A, B)) or (N / (A / gcd(A, B)) != B) or (N % B != 0) or (N % A != 0) or (N > 1000000000000000000ull))
    cout << "Large" << endl;
  else
    cout << N << endl;
  return 0;
}