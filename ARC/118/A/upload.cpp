#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
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
  auto [t, N] = read_elems<int, int>();
  ;
  const int res = N % t;
  ;
  const int quotient = (N / t);
  ;
  u64 price = (u64)quotient * 100;
  ;
  u64 prev_price = (u64)quotient * (100 + t);
  ;
  int count = 0;
  while (count < res){
    if (price * (100 + t) / 100 - prev_price > 1){
      ;
      ;
      ++count;
    }
    prev_price = price * (100 + t) / 100;
    price++;
  }
  cout << prev_price - 1 << endl;
  return 0;
}
