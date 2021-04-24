#include <iostream>
#include <ctime>
#include <filesystem>
#include <vector>

#include "../lib/log.hpp"

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));

  for (auto& row : A)
    for (auto& a : row)
      cin >> a;

  vector<int> R(H, 0), C(W, 0);

  for (size_t r = 0; r < H; ++r)
    for (size_t c = 0; c < W; ++c)
      R[r] += A[r][c], C[c] += A[r][c];

  for (size_t r = 0; r < H; ++r) {
    for (size_t c = 0; c < W; ++c)
      cout << R[r] + C[c] - A[r][c] << " ";
    cout << "\n";
  }
  cout << flush;


  return 0;
}