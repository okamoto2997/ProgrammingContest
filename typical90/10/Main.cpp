#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../lib/log.hpp"

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> C(N), P(N);
  for (size_t i = 0; i < N; ++i)
    cin >> C[i] >> P[i];
  int Q;
  cin >> Q;

  vector<int> summary_1(N), summary_2(N);
  if (C[0] == 1)
    summary_1[0] = P[0];
  else
    summary_2[0] = P[0];

  for (size_t i = 1; i < N; ++i) {
    summary_1[i] = summary_1[i - 1] + (C[i] == 1 ? P[i] : 0);
    summary_2[i] = summary_2[i - 1] + (C[i] == 2 ? P[i] : 0);
  }

  for (size_t i = 0; i < Q; ++i) {
    int L, R;
    cin >> L >> R;
    --L, --R;
    if (L == 0)
      cout << summary_1[R] << " " << summary_2[R] << "\n";
    else
      cout << summary_1[R] - summary_1[L - 1] << " " << summary_2[R] - summary_2[L - 1] << "\n";

  }

  return 0;
}