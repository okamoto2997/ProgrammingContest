#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  string S = read<string>();
  size_t pos = 0;
  size_t count = 0;
  while ((pos = S.find("ZONe", pos)) != string::npos){ ++pos; ++count; }
  cout << count << endl;
  return 0;
}