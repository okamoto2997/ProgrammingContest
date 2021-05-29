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
  int N = read();
  vector<int> color(N, -1);
  vector<vector<int>> neighbor(N);
  for (int n = 0; n < N; ++n) {
    auto [A, B] = read_elems<int, int>();
    --A, --B;
    neighbor[A].emplace_back(B);
    neighbor[B].emplace_back(A);
  }
  color[0] = 0;
  vector<int> stack; stack.reserve(N);
  stack.push_back(0);
  while (stack.size()) {
    auto pivot = stack.back(); stack.pop_back();
    for (auto& n : neighbor[pivot])
      if (color[n] < 0) {
        color[n] = 1 - color[pivot];
        stack.push_back(n);
      }
  }
  int count = count_if(color.begin(), color.end(), [](int c) {return c == 0;});
  int select_color = count >= N / 2 ? 0 : 1;
  int output_count = 0;
  for (int n = 0; n < N; ++n)
    if (color[n] == select_color) {
      cout << n + 1 << " ";
      if (++output_count == N / 2)
        break;
    }
  cout << endl;
  return 0;
}