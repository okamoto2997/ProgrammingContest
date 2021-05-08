#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int N = read();
  vector<int> A = read_vector<int>(N);
  vector<int> count(200, 0);
  for (auto& a : A) a %= 200, ++count[a];

  for (int i = 0; i < 200; ++i)
    if (count[i] >= 2){
      cerr << "rem  : " << i << "\n";
      cerr << "count: " << count[i] << "\n";
      cout << "Yes\n";
      int j = 0;
      for (; j < N; ++j)
        if (A[j] == i){
          cout << 1 << " " << ++j << "\n";
          break;
        }
      for (; j < N; ++j)
        if (A[j] == i){
          cout << 1 << " " << ++j << "\n";
          break;
        }
      return 0;
    }

  vector<bool> B(N, false);
  vector<bool> C(N, false);

  cout << "No\n";
  return 0;
}