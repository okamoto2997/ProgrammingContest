#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int N = read<int>();
  auto a = read_vector<int>(N);

  sort(a.begin(), a.end(), greater<int>());

  int diff = 0;
  for (int i = 0; i < a.size(); i += 2){
    if (a.size() - i > 1)
      diff += a[i] - a[i + 1];
    else
      diff += a[i];
  }

  cout << diff << endl;

  return 0;
}