#include <algorithm>
#include <cstdarg>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
namespace lib{
  using i64 = int64_t;
  using u64 = uint64_t;
  constexpr u64 mod = 1000000007;
  template<class T, class V>
  constexpr T max(const V& v){
    return *max_element(begin(v), end(v));
  }
  constexpr u64 gcd(u64 m, u64 n){
    return m == n ? m : m < n ? (n % m == 0 ? m : gcd(n % m, m)) : (m % n == 0 ? n : gcd(n, m % n));
  }
  constexpr u64 max_bit(u64 n){
    return n == 0 ? 0 : max_bit(n >> 1) + 1;
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
  namespace{
    template<size_t INDEX, class T>
    T& read_elem(T& buf, std::istream&){
      return buf;
    }
    template<size_t INDEX, class T, class F, class... After>
    T& read_elem(T& buf, std::istream& src = std::cin){
      std::get<INDEX>(buf) = read<F>(src);
      return read_elem<INDEX + 1, T, After...>(buf, src);
    }
  }
  template<class... T>
  std::tuple<T...> read_elems(std::istream& src = std::cin){
    std::tuple<T...> buf;
    return read_elem<0, typeof(buf), T...>(buf, src);
  }
  namespace{
    template<class T>
    std::string to_string(const T& t, char){
      return std::to_string(t);
    }
    template<>
    [[maybe_unused]] std::string to_string(const std::string& t, char){
      return t;
    }
    template<class T>
    std::string to_string(const std::vector<T>& t, char delim){
      std::string ret;
      if (t.size()){
        auto iter = t.begin();
        ret = to_string(*iter, delim);
        for (++iter; iter != t.end(); ++iter)
          ret += delim + to_string(*iter, delim);
      }
      return ret;
    }
    template<class T>
    std::string print(const T& t, char delim){
      return to_string(t, delim);
    }
    template<class T, class ...Args>
    std::string print(char delim, const T& t, const Args... args){
      return to_string(t, delim) + delim + print(args...);
    }
  }
  template<class ...Args>
  std::string print(char delim, const Args... args){
    return format(delim, args...);
  }
  std::string strprintf(const char* fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    char* buffer;
    [[maybe_unused]] int size = vasprintf(&buffer, fmt, ap);
    va_end(ap);
    std::string ret(buffer);
    free(buffer);
    return ret;
  }
  template<class V>
  auto sort(V& v){
    return sort(begin(v), end(v));
  }
}
using namespace std;
using namespace lib;
int main() {
  auto [H, W] = read_elems<int, int>();
  auto [rs, cs] = read_elems<int, int>();
  auto [rt, ct] = read_elems<int, int>();
  vector<vector<int>> S(H + 2, vector<int>(W + 2, -2));
  for (int r = 1; r <= H; ++r) {
    for (int c = 1; c <= W; ++c)
      S[r][c] = (read<char>() == '.' ? -1 : -2);
  }
  constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  S[rs][cs] = 0;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      check_list;
  check_list.emplace(0, rs, cs);
  while (check_list.size()) {
    auto [level, r, c] = check_list.top();
    check_list.pop();
    for (auto [dr, dc] : dirs) {
      int step = 1;
      while (S[r + step * dr][c + step * dc] != -2) {
        const int R = r + step * dr;
        const int C = c + step * dc;
        if (S[R][C] == -1) S[R][C] = level;
        for (auto [dR, dC] : dirs)
          if (dr != dR && dc != dC && S[R + dR][C + dC] == -1)
            check_list.emplace(level + 1, R, C);
        ++step;
      }
    }
    if (S[rt][ct] != -1) break;
  }
  cout << S[rt][ct] << "\n";
  return 0;
}
