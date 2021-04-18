#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr uint64_t MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto& a : A) cin >> a;
  sort(A.begin(), A.end());

  int current_step = 0;
  uint64_t ret = 1;
  for (auto a : A){
    ret = ret * (a - current_step + 1) % MOD;
    current_step = a;
  }
  cout << ret << endl;

  return 0;
}