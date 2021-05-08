#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int N = read();
  vector<vector<int>> status(N, vector<int>(5));
  for (int n = 0; n < N; ++n)
    status[n] = read_vector<int>(5);

  vector<vector<int>> status_index(5, vector<int>(N));
  for (size_t type = 0; type < 5; ++type){
    iota(status_index[type].begin(), status_index[type].end(), 0);
    sort(status_index[type].begin(), status_index[type].end(),
      [&status, type](int i, int j){return status[i][type] > status[j][type];}
    );
  }




  for (auto i : status_index[1]){
    cout << status[i][1] << endl;
  }



  return 0;
}