#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int penalty(vector<int> &A, int q){
  size_t left = 0;
  size_t right = A.size() - 1;
  while(right - left > 1){
    int center = (right + left)/2;
    if(A[center] - q < 0)
      left = center;
    else 
      right = center;
  }
  return min(abs(A[right] - q), abs(A[left] - q));
}

int main(){
  int N = read();
  vector<int> A = read_vector<int>(N);
  sort(A.begin(), A.end());
  for(auto a : A)
    cerr << "score: " << a << "\n";
  int Q = read();
  for(int q = 0; q < Q; ++q){
    int b = read();
    cout << penalty(A, b) << "\n";
  }
  return 0;
}