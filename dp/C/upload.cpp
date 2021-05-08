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
  int N = read();
  vector<vector<int>> happiness(3, vector<int>(N, 0));
  auto [a, b, c] = read_elems<int, int, int>();
  happiness[0][0] = a;
  happiness[1][0] = b;
  happiness[2][0] = c;
  for (int n = 1; n < N; ++n){
    auto score = read_vector<int>(3);
    for (int type = 0; type < 3; ++type)
      happiness[type][n] = score[type] + max(happiness[(type + 1) % 3][n - 1], happiness[(type + 2) % 3][n - 1]);
  }
  cout << max({ happiness[0].back(), happiness[1].back(), happiness[2].back() }) << endl;
  return 0;
}
