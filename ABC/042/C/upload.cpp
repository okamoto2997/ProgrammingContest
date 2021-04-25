#include <iostream>
#include <ctime>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> D(K);
  for (auto& d : D) cin >> d;
  vector<int> all_num(10); iota(all_num.begin(), all_num.end(), 0);
  vector<int> acceptable; acceptable.reserve(10);
  set_difference(all_num.begin(), all_num.end(), D.begin(), D.end(), std::inserter(acceptable, acceptable.end()));
  for (auto& a : acceptable)
    ;
  int digit = 1;
  int carry_up = 0;
  int ret = 0;
  while (N > 0){
    int n = N % 10 + carry_up;
    carry_up = n == 10 ? 1 : 0;
    n = n == 10 ? 0 : n;
    if (binary_search(acceptable.begin(), acceptable.end(), n))
      ret += digit * n;
    else{
      ;
      bool found_accept = false;
      for (auto a : acceptable)
        if (a >= n){
          ret += digit * a;
          found_accept = true;
          break;
        }
      if (!found_accept){
        ret += acceptable[0] * digit;
        carry_up = 1;
      }
    }
    digit *= 10;
    N /= 10;
  }
  if (carry_up){
    ret += digit * (acceptable[0] ? acceptable[0] : acceptable[1]);
  }
  cout << ret << endl;
  return 0;
}
