#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <numeric>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int N = read();
  vector<u64> a(2 * N);
  vector<char> c(2 * N);
  int R = 0, G = 0, B = 0;
  for (int n = 0; n < 2 * N; ++n){
    tie(a[n], c[n]) = read_elems<u64, char>();
    switch (c[n]){
    case 'R':
      ++R;
      break;
    case 'G':
      ++G;
      break;
    case 'B':
      ++B;
      break;
    }
  }

  R %= 2;
  G %= 2;
  B %= 2;

  if (R + G + B == 0){
    cout << 0 << endl;
    return 0;
  }

  char balanced = '\0';

  if (R == 0) balanced = 'R';
  if (G == 0) balanced = 'G';
  if (B == 0) balanced = 'B';
  // cout << "R: " << R << "\n";
  // cout << "G: " << G << "\n";
  // cout << "B: " << B << "\n";

  // cout << "balanced: " << balanced << "\n";

  vector<int> index; index.reserve(2 * N);
  for (int n = 0; n < 2 * N; ++n)
    if (c[n] != balanced)
      index.push_back(n);

  sort(index.begin(), index.end(), [&a](int i, int j){return a[i] < a[j];});
  u64 min = 1e16;
  u64 prev_a = a[index[0]];
  char prev_c = c[index[0]];
  for (auto i : index){
    cout << "index: " << i << ", pretty: " << a[i] << ", color: " << c[i] << "\n";
    if (c[i] != prev_c){
      min = std::min(min, a[i] - prev_a);
      prev_c = c[i];
      if (min == 0) break;
    }
    prev_a = a[i];
  }

  cout << min << "\n";

  return 0;
}