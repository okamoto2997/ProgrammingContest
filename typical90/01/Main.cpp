#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int score(const vector<int> cut, int L, const vector<int>& A){
  int ret = A[cut[0]];
  for (int i = 1; i < cut.size() - 1; ++i)
    ret = min(ret, A[cut[i]] - A[cut[i - 1]]);
  ret = min(ret, L - A[cut.back()]);
}

bool is_cut_possibile(int score, int K, int L, const vector<int>& A){
  int current_pos = 0;
  int current_index = 0;
  for (int k = 0; k < K; ++k){
    for (; current_index < A.size(); ++current_index)
      if (A[current_index] - current_pos >= score){
        current_pos = A[current_index];
        break;
      }
    if (current_index == A.size())
      return false;
  }
  return L - current_pos >= score;
}

int main(){
  auto [N, L] = read_elems<int, int>();
  int K = read();
  auto A = read_vector(N);
  vector<int> cut(K); iota(cut.begin(), cut.end(), 0);
  int min_score = 0;
  int sup_score = L;

  while (sup_score - min_score > 1){
    int candidate = (sup_score + min_score) / 2;
    cerr << "candidate: " << candidate << "\n";
    if (is_cut_possibile(candidate, K, L, A))
      min_score = candidate;
    else
      sup_score = candidate;
  }

  cout << min_score << endl;

  return 0;
}