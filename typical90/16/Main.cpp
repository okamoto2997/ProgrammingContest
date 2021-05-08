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
  auto V = read_vector<int>(3);
  cerr << "N = " << N << "\n";
  cerr << "A = " << V[0] << "\n";
  cerr << "B = " << V[1] << "\n";
  cerr << "C = " << V[2] << "\n";

  cerr << "sort\n";
  sort(V.begin(), V.end());

  cerr << "A = " << V[0] << "\n";
  cerr << "B = " << V[1] << "\n";
  cerr << "C = " << V[2] << "\n";

  int min_coins = 9999;
  for(int c = 0; c*V[2] <= N; ++c)
    for(int b = 0; c*V[2] + b*V[1] <= N; ++b){
      auto [r, q] = div(N - c*V[2] - b*V[1], V[0]);
      if(q == 0)
        min_coins = min(min_coins, r + b + c);
    }
  cout << min_coins << "\n";
  return 0;
}