#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  auto S = read<string>();

  vector<string> candidates = { "dream", "dreamer", "erase", "eraser" };
  set<pair<int, int>> states;
  states.emplace(-1, 0);

  for (auto c : S){
    set<pair<int, int>> next_states;
    cerr << "char: " << c << "\n";
    for (auto iter = states.begin(); iter != states.end(); ++iter){
      auto [candidate, index] = *iter;
      if (candidate < 0){
        cerr << "emplty state detected\n";
        for (size_t i = 0; i < candidates.size(); ++i)
          if (c == candidates[i][0])
            next_states.emplace(i, 0);
      }
      else{
        cerr << "state: " << candidates[candidate] << "\n";
        if (candidates[candidate][index + 1] == c){
          if (candidates[candidate].size() == index + 2)
            next_states.emplace(-1, 0);
          else
            next_states.emplace(candidate, index + 1);
        }
      }
    }
    states = next_states;
    if (states.size() == 0)
      break;
  }

  for (auto [i, index] : states){
    cerr << "candidate: " << (i < 0 ? string("*") : candidates[i]) << " with index: " << index << "\n";
  }

  cout << (states.find(make_pair(-1, 0)) != states.end() ? "YES" : "NO") << endl;

  return 0;
}