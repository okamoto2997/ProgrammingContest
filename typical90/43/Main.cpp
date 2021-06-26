
#include <algorithm>

#include <cstdarg>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "lib/log.hpp"

#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main() {
  auto [H, W] = read_elems<int, int>();
  auto [rs, cs] = read_elems<int, int>();
  auto [rt, ct] = read_elems<int, int>();
  vector<vector<int>> S(H + 2, vector<int>(W + 2, -2));
  for (int r = 1; r <= H; ++r) {
    for (int c = 1; c <= W; ++c)
      S[r][c] = (read<char>() == '.' ? -1 : -2);
  }

  constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // for (int r = 0; r < H + 2; ++r) {
  //   for (int c = 0; c < W + 2; ++c)
  //     cerr << (char)(S[r][c] == -2 ? '#' : S[r][c] == -1 ? '.' : S[r][c] +
  //     '0');
  //   cerr << "\n";
  // }

  S[rs][cs] = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      check_list;
  check_list.emplace(0, rs, cs);

  while (check_list.size()) {
    auto [level, r, c] = check_list.top();
    check_list.pop();
    for (auto [dr, dc] : dirs) {
      int step = 1;
      // INFO("dr, dc = %d, %d", dr, dc);
      while (S[r + step * dr][c + step * dc] != -2) {
        const int R = r + step * dr;
        const int C = c + step * dc;
        if (S[R][C] == -1) S[R][C] = level;
        for (auto [dR, dC] : dirs)
          if (dr != dR && dc != dC && S[R + dR][C + dC] == -1)
            check_list.emplace(level + 1, R, C);
        ++step;
      }
    }
    if (S[rt][ct] != -1) break;
    // for (int r = 0; r < H + 2; ++r) {
    //   for (int c = 0; c < W + 2; ++c)
    //     cerr << (char)(S[r][c] == -2   ? '#'
    //                    : S[r][c] == -1 ? '.'
    //                                    : S[r][c] + '0');
    //   cerr << "\n";
    // }
  }

  cout << S[rt][ct] << "\n";

  return 0;
}