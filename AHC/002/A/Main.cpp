#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cassert>

#include "../lib/log.hpp"
#include "../lib/utility.hpp"

using namespace std;
using namespace lib;

constexpr size_t W = 50, H = 50;

enum flag{
  U = 1,
  D = 2,
  L = 4,
  R = 8
};

constexpr flag flag_list[] = { U, D, L, R };
pair<int, int> index2delta(int i){
  assert(0 <= i && i < 4);
  switch (i){
  case 0:
    return make_pair(1, 0);
  case 1:
    return make_pair(-1, 0);
  case 2:
    return make_pair(0, -1);
  case 3:
    return make_pair(0, 1);
  default:
    assert(0);
  }
}

pair<int, int> char2delta(char c){
  switch (c){
  case 'U':
    return make_pair(1, 0);
  case 'D':
    return make_pair(-1, 0);
  case 'L':
    return make_pair(0, -1);
  case 'R':
    return make_pair(0, 1);
  default:
    assert(0);
  }
}

void set(int i, int j, vector<vector<bool>>& movable, const vector<vector<int>>& tile, bool flag = false){
  movable[i][j] = flag;
  if (0 < j && tile[i][j] == tile[i][j - 1])
    movable[i][j - 1] = flag;
  if (j < W - 1 && tile[i][j] == tile[i][j + 1])
    movable[i][j + 1] = flag;
  if (0 < i && tile[i][j] == tile[i - 1][j])
    movable[i - 1][j] = flag;
  if (i < H - 1 && tile[i][j] == tile[i + 1][j])
    movable[i + 1][j] = flag;
}
// UDLR
// 1248
string listup(int i, int j, const vector<vector<bool>>& movable){
  size_t ret = 0;
  ret |= L * (0 < j && movable[i][j - 1]);
  ret |= R * (j < W - 1 && movable[i][j + 1]);
  ret |= U * (0 < i && movable[i - 1][j]);
  ret |= D * (i < H - 1 && movable[i + 1][j]);
  return ret;
}

void search(size_t score, size_t d, size_t max_d, int i, int j, string& command, map<size_t, string>& log, vector<vector<bool>>& movable, const vector<vector<int>>& tile){
  if (d == max_d){ log[score] = command; return; }
  size_t candidate = listup(i, j, movable);
  if (candidate == 0){ log[score] = command; return; }

  for(auto f : flag_list)
    if(candidate & f)

  pair<int, int> delta = char2delta(command.back());

}

int main(){
  auto [s_i, s_j] = read_elems<int, int>();
  vector<vector<int>> tile(H, vector<int>(W, -1));
  vector<vector<int>> score(H, vector<int>(W, -1));
  vector<vector<bool>> movable(H, vector<bool>(W, true));

  for (size_t h = 0; h < H; ++h)
    for (size_t w = 0; w < W; ++w)
      cin >> tile[h][w];
  for (size_t h = 0; h < H; ++h)
    for (size_t w = 0; w < W; ++w)
      cin >> score[h][w];
  set(s_i, s_j, movable, tile);
  for (size_t h = 0; h < H; ++h){
    for (size_t w = 0; w < W; ++w)
      cout << (movable[h][w] ? "o" : "x");
    cout << "\n";
  }
  cout << flush;
  return 0;
}