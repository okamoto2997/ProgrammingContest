#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <queue>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

constexpr int W = 30, H = 30;

auto idx = [](int w, int h){return h * W + w;};
auto eidx = [](int w1, int h1, int w2, int h2){return max(idx(w1, h1), idx(w2, h2)) * W * H + min(idx(w1, h1), idx(w2, h2));};

std::string dijkstra(const map<int, int>& graph){

}

int main(){
  map<int, int> graph;
  map<int, int> count;
  for (int h = 0; h < H - 1; ++h)
    for (int w = 0; w < W; ++w){
      graph[eidx(w, h, w, h + 1)] = 5000;
      count[eidx(w, h, w, h + 1)] = 1;
    }
  for (int h = 0; h < H; ++h)
    for (int w = 0; w < W - 1; ++w){
      graph[eidx(w, h, w + 1, h)] = 5000;
      count[eidx(w, h, w + 1, h)] = 1;
    }

  for (size_t q = 0; q < 1000; ++q){
    INFO("query: %zu", q);
    auto [si, sj, ti, tj] = read_elems<int, int, int, int>();
    INFO("(%d, %d) -> (%d, %d)", si, sj, ti, tj);
    if (si < ti)
      for (int i = si; i < ti; ++i)
        cout << "D";
    else if (ti < si)
      for (int i = ti; i < si; ++i)
        cout << "U";

    if (sj < tj)
      for (int j = sj; j < tj; ++j)
        cout << "R";
    else if (tj < sj)
      for (int j = sj; tj < j; --j)
        cout << "L";
    cout << endl;
    int score = read();
    INFO("score %d", score);
  }
  return 0;
}