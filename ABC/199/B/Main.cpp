#include <iostream>
#include <ctime>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

#include "../lib/log.hpp"

using namespace std;

int main(){
  int N;
  cin >> N;
  int lower = 1, upper = 1000;
  int A, B;
  for (size_t n = 0; n < N; ++n){
    cin >> A;
    lower = max(lower, A);
  }
  for (size_t n = 0; n < N; ++n){
    cin >> B;
    upper = min(upper, B);
  }
  cout << (upper >= lower ? upper - lower + 1 : 0) << endl;
  return 0;
}