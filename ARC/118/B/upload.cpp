#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
namespace lib{
  using i64 = int64_t;
  using u64 = uint64_t;
  template<class T, class V>
  constexpr T max(const V& v){
    return *max_element(begin(v), end(v));
  }
  constexpr u64 gcd(u64 m, u64 n){
    return m == n ? m : m < n ? (n % m == 0 ? m : gcd(n % m, m)) : (m % n == 0 ? n : gcd(n, m % n));
  }
  std::string readline(std::istream& src = std::cin){
    std::string line;
    std::getline(src, line);
    return line;
  }
  template<class T = int>
  T read(std::istream& src = std::cin){
    T buf;
    src >> buf;
    return buf;
  }
  template<class T = int>
  std::vector<T> read_vector(size_t size, std::istream& src = std::cin){
    std::vector<T> buf(size);
    for (auto& b : buf) src >> b;
    return buf;
  }
  template<size_t INDEX, class T>
  T& read_elem(T& buf, std::istream&){
    return buf;
  }
  template<size_t INDEX, class T, class F, class... After>
  T& read_elem(T& buf, std::istream& src = std::cin){
    std::get<INDEX>(buf) = read<F>(src);
    return read_elem<INDEX + 1, T, After...>(buf, src);
  }
  template<class... T>
  std::tuple<T...> read_elems(std::istream& src = std::cin){
    std::tuple<T...> buf;
    return read_elem<0, typeof(buf), T...>(buf, src);
  }
}
using namespace std;
using namespace lib;
int main(){
  auto [K, N, M] = read_elems<u64, u64, u64>();
  auto A = read_vector<u64>(K);
  auto B = vector<u64>(K, 0);
  for (size_t k = 0; k < K; ++k)
    B[k] = M * A[k] / N;
  int res = M - accumulate(B.begin(), B.end(), 0);
  ;
  priority_queue<pair<double, int>> error_queue;
  for (size_t k = 0; k < K; ++k)
    error_queue.push({ abs(1.0 * A[k] / N - 1.0 * B[k] / M), k });
  for (size_t r = 0; r < res; ++r){
    auto [error, k] = error_queue.top(); error_queue.pop();
    ;
    ;
    error_queue.push({ abs(1.0 * A[k] / N - 1.0 * ++B[k] / M), k });
  }
  for (auto b : B)
    cout << b << " ";
  cout << endl;
  return 0;
}
