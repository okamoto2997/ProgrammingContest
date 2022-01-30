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
  int N, D;
  tie(N, D) = read_elems<int, int>();
  int X, Y;
  tie(X, Y) = read_elems<int, int>();

  cout.precision(15);

  cout << fixed;

  if (X % D or Y % D or (N < abs(X) / D + abs(Y) / D) or
      (N - (abs(X) / D + abs(Y) / D)) % 2) {
    cout << 0.0 << "\n";
    return 0;
  }

  // const u64 jump_X = X / D;
  // const u64 jump_Y = Y / D;
  vector<vector<double>> jump1(N + 2, vector<double>(N + 2, 0));
  vector<vector<double>> jump2(N + 2, vector<double>(N + 2, 0));

  jump1[0][0] = 1.0;

  INFO("check");

  for (int n = 1; n <= N; ++n) {
    jump2[0][0] += 0.5 * (jump1[1][0] + jump1[0][1]);
    for (int i = 1; i <= n; ++i) {
      jump2[0][i] +=
          0.25 * (jump1[0][i - 1] + jump1[0][i + 1] + 2 * jump1[1][i]);
      jump2[i][0] +=
          0.25 * (jump1[i - 1][0] + jump1[i + 1][0] + 2 * jump1[i][1]);
    }

    for (int i = 1; i <= n; ++i)
      for (int j = 1; i + j <= n; ++j)
        jump2[i][j] += 0.25 * (jump1[i - 1][j] + jump1[i + 1][j] +
                               jump1[i][j - 1] + jump1[i][j + 1]);

    // INFO("copy");
    for (int i = 0; i <= n; ++i)
      for (int j = 0; i + j <= n; ++j)
        jump1[i][j] = jump2[i][j], jump2[i][j] = 0;
  }

  // for (int i = 0; i < 2 * N + 1; ++i)
  //   for (int j = 0; j < 2 * N + 1; ++j)
  //     INFO("(%d, %d) = %f", i, j, jump1[i][j]);

  // INFO("X = %d, Y = %d", X, Y, D);
  // INFO("D = %d", D);
  // INFO("X/D = %d, Y/D = %d", X / D, Y / D);

  cout.precision(15);
  cout << jump1[abs(Y) / D][abs(X) / D] << endl;

  // int minimal_jump = X / D + Y / D;
  // int residual_jump = N - minimal_jump;

  // INFO("shortest jump pattern: %zu", comb(minimal_jump)[minimal_jump][X /
  // D]);

  return 0;
}