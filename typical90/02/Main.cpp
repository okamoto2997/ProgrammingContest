#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  const int N = read();
  if(N & 1) return 0;
  vector<vector<string>> catalogue(N/2);
  catalogue[0].reserve(1);
  catalogue[0].push_back("()");

  for(int n = 1; 2*n < N; ++n){
    catalogue[n].reserve(catalogue[n].size() + catalogue[n - 1].size());
    for(auto &s : catalogue[n - 1])
      catalogue[n].emplace_back("(" + s + ")");
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if(2*(i + 1) + 2*(j + 1) == 2*(n + 1)){
          catalogue[n].reserve(catalogue[n].size() + catalogue[i].size()*catalogue[j].size());
          for(auto &s : catalogue[i])
            for(auto &t : catalogue[j])
              catalogue[n].emplace_back(s + t);
        }
    sort(catalogue[n].begin(), catalogue[n].end());
    auto end = unique(catalogue[n].begin(), catalogue[n].end());
    catalogue[n].erase(end, catalogue[n].end());
  }

  for(auto & s: catalogue.back())
    cout << s << "\n";
  cout << flush;
  return 0;
}