#include <iostream>
#include <ctime>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

#include "../lib/log.hpp"

using namespace std;

int main(){
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  for (auto& s : S) cin >> s;
  sort(S.begin(), S.end());
  for (auto& s : S) cout << s;
  cout << endl;
  return 0;
}