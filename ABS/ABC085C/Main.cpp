#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

// size_t index(int x, int y, int z){
//   size_t ret = x;
//   ret = ret * 10000 + y;
//   ret = ret * 10000 + z;
//   return ret;
// }

// bool find(int Y, int N, int& x, int& y, int& z, int current, set<size_t>& log){
//   if (log.find(index(x, y, z)) == log.end())
//     log.emplace(index(x, y, z));
//   else
//     return false;

//   if (Y == current && x + y + z == N) return true;
//   else if (Y < current) return false;
//   if (x + y + z >= N) return false;

//   if (find(Y, N, ++x, y, z, current + 10000, log)) return true;
//   if (find(Y, N, --x, ++y, z, current + 5000, log)) return true;
//   if (find(Y, N, x, --y, ++z, current + 1000, log)) return true;
//   --z;
//   return false;
// }

int main(){
  auto [N, Y] = read_elems<int, int>();

  for (int x = 0; x * 10000 <= Y; ++x){
    for (int y = 0; x * 10000 + y * 5000 <= Y; ++y){
      int z = (Y - x * 10000 - y * 5000) / 1000;
      if (x + y + z == N){
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}