#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
  int T = read();
  auto [L, X, Y] = read_elems<i64, i64, i64>();
  int Q = read();
  cout.precision(15);
  for(int q = 0; q < Q; ++q){
    int E = read();
    const double theta = 2*M_PI*E/T;
    const double x = 0;
    const double y = -0.5*L*sin(theta);
    const double z = 0.5*L*(1 - cos(theta));
    const double d_xy = hypot(X - x, Y - y);
    const double d_xyz = hypot(d_xy, 0 - z);
    cout << 360*acos(d_xy / d_xyz)/(2*M_PI) << "\n";
  }
  return 0;
}
