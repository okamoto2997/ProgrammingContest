#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

void dijkstra(int start, vector<int> &len, map<int, map<int, int>> &G){
  len[start] = 0;
  std::priority_queue<pair<int, int>> que;
  que.push({0, start});
  while(que.size()){
    auto [time, current] = que.top();
    que.pop();
    for(auto &[v, t] : G[current])
      if(len[v] > -time + t){
        len[v] = -time + t;
        que.push({time - t, v});
      }
  }
}

int main(){
  auto [N, M] = read_elems<int, int>();
  map<int, map<int, int>> G;
  for(int m = 0; m < M; ++m){
    auto [A, B, C] = read_elems<int, int, int>();
    --A, --B;
    G[A][B] = C;
    G[B][A] = C;
  }

  vector<int> length_1(N, 2e9);
  vector<int> length_N(N, 2e9);

  dijkstra(0, length_1, G);
  dijkstra(N - 1, length_N, G);

  for(int k = 0; k < N; ++k)
    cout << length_1[k] + length_N[k] << "\n";

  return 0;
}