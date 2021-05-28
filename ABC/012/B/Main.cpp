#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  int N = read();
  cout << strprintf("%02d:%02d:%02d", N / 3600, N / 60 % 60, N % 60) << endl;
  return 0;
}