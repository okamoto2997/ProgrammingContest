#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  auto N = read();
  auto d = read_vector(N);
  sort(d.begin(), d.end());
  auto iter = unique(d.begin(), d.end());
  d.erase(iter, d.end());
  cout << d.size() << endl;
  return 0;
}