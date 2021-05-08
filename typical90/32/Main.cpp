#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int score(vector<int> &players, const vector<vector<int>> &A){
  int ret = 0;
  for(size_t i = 0; i < players.size(); ++i)
    ret += A[players[i]][i];
  return ret;
}

void search_minscore(int current_level, vector<int> &players, set<int> &bench, int N, int &min_score, const vector<vector<int>> &A, map<int, set<int>> &bad){
  if(score(players, A) > min_score) return;
  if(current_level == N){
    // cerr << "candidate:\n";
    // for(auto player : players)
    //   cerr << "\t" << player << "\n";
    min_score = min(min_score, score(players, A));
  }else{
    for(auto iter = bench.begin(); iter != bench.end(); ++iter){
      int player = *iter;
      if(players.size() > 0 && bad[players.back()].count(player))
        continue;
      else{
        players.push_back(player);
        bench.erase(iter);
        search_minscore(current_level + 1, players, bench, N, min_score, A, bad);
        iter = bench.insert(player).first;
        players.pop_back();
      }
    }
  }
}

int main(){
  int N = read();
  vector<vector<int>> A(N);
  for(auto &a : A)
    a = read_vector<int>(N);
  int M = read();
  map<int, set<int>> bad;
  for(int m = 0; m < M; ++m){
    auto [X, Y] = read_elems<int, int>();
    --X, --Y;
    bad[X].emplace(Y);
    bad[Y].emplace(X);
  }
      // cerr << "bad pair list:\n";
      // for(auto [player, enemies] : bad)
      //   for(auto bad_player : enemies)
      //     cerr << "\t" << player << " : " << bad_player << "\n";
  vector<int> players; players.reserve(N);
  set<int> bench; for(int i = 0; i < N; ++i) bench.emplace(i);
  int min_score = 1000000;
  search_minscore(0, players, bench, N, min_score, A, bad);

  cout << (min_score == 1000000 ? -1 : min_score) << endl;
  
  return 0;
}