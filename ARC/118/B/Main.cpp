#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <deque>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main(){
  auto [K, N, M] = read_elems<u64, u64, u64>();
  auto A = read_vector<u64>(K);
  auto b = vector<double>(K, 0);
  auto B = vector<u64>(K, 0);

  for (size_t k = 0; k < K; ++k)
    B[k] = M * A[k] / N;

  int res = M - accumulate(B.begin(), B.end(), 0);
  DEBUG("res: %d", res);

  deque<pair<double, int>> error_queue;
  for (size_t k = 0; k < K; ++k)
    error_queue.emplace_back(1.0 * A[k] / N - 1.0 * B[k] / M, k);
  sort(error_queue.begin(), error_queue.end(), [](auto a, auto b){return abs(a.first) < abs(b.first);});

  for (int r = 0; r < res; ++r){
    auto iter = error_queue.begin();
    auto [signed_error, k] = *iter; error_queue.erase(iter);
    auto error = abs(signed_error);
//    error *= (M * A[k] > N * B[k] ? 1 : -1);

    DEBUG("error: %f", error);
    DEBUG("index: %d", k);
    error_queue.emplace_back(1.0 * A[k] / N - 1.0 * B[k] / M, k);
    sort(error_queue.begin(), error_queue.end(), [](auto a, auto b){return abs(a.first) < abs(b.first);});
  }

  while (true){

  }


  for (auto b : B)
    cout << b << " ";
  cout << endl;


  return 0;
}