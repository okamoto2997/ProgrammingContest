#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdarg>
namespace lib {
  using i64 = int64_t;
  using u64 = uint64_t;
  template<class T, class V>
  constexpr T max(const V& v) {
    return *max_element(begin(v), end(v));
  }
  constexpr u64 gcd(u64 m, u64 n) {
    return m == n ? m : m < n ? (n % m == 0 ? m : gcd(n % m, m)) : (m % n == 0 ? n : gcd(n, m % n));
  }
  constexpr u64 max_bit(u64 n) {
    return n == 0 ? 0 : max_bit(n >> 1) + 1;
  }
  std::string readline(std::istream& src = std::cin) {
    std::string line;
    std::getline(src, line);
    return line;
  }
  template<class T = int>
  T read(std::istream& src = std::cin) {
    T buf;
    src >> buf;
    return buf;
  }
  template<class T = int>
  std::vector<T> read_vector(size_t size, std::istream& src = std::cin) {
    std::vector<T> buf(size);
    for (auto& b : buf) src >> b;
    return buf;
  }
  namespace {
    template<size_t INDEX, class T>
    T& read_elem(T& buf, std::istream&) {
      return buf;
    }
    template<size_t INDEX, class T, class F, class... After>
    T& read_elem(T& buf, std::istream& src = std::cin) {
      std::get<INDEX>(buf) = read<F>(src);
      return read_elem<INDEX + 1, T, After...>(buf, src);
    }
  }
  template<class... T>
  std::tuple<T...> read_elems(std::istream& src = std::cin) {
    std::tuple<T...> buf;
    return read_elem<0, typeof(buf), T...>(buf, src);
  }
  namespace {
    template<class T>
    std::string to_string(const T& t, char) {
      return std::to_string(t);
    }
    template<>
    std::string to_string(const std::string& t, char) {
      return t;
    }
    template<class T>
    std::string to_string(const std::vector<T>& t, char delim) {
      std::string ret;
      if (t.size()) {
        auto iter = t.begin();
        ret = to_string(*iter, delim);
        for (++iter; iter != t.end(); ++iter)
          ret += delim + to_string(*iter, delim);
      }
      return ret;
    }
    template<class T>
    std::string print(const T& t, char delim) {
      return to_string(t, delim);
    }
    template<class T, class ...Args>
    std::string print(char delim, const T& t, const Args... args) {
      return to_string(t, delim) + delim + print(args...);
    }
  }
  template<class ...Args>
  std::string print(char delim, const Args... args) {
    return format(delim, args...);
  }
  std::string strprintf(const char* fmt, ...) {
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
  auto sort(V& v) {
    return sort(begin(v), end(v));
  }
}
using namespace std;
using namespace lib;
int main(){
  constexpr int W = 30, H = 30;
  map<int, map<int, int>> graph;
  auto idx = [W](int w, int h){return h * W + w;};
  for (int h = 0; h < H - 1; ++h)
    for (int w = 0; w < W; ++w){
      graph[idx(w, h)][idx(w, h + 1)] = 5000;
      graph[idx(w, h + 1)][idx(w, h)] = 5000;
    }
  for (size_t q = 0; q < 1000; ++q){
    ;
    auto [si, sj, ti, tj] = read_elems<int, int, int, int>();
    ;
    if (si < ti)
      for (int i = si; i < ti; ++i)
        cout << "D";
    else if (ti < si)
      for (int i = ti; i < si; ++i)
        cout << "U";
    if (sj < tj)
      for (int j = sj; j < tj; ++j)
        cout << "R";
    else if (tj < sj)
      for (int j = sj; tj < j; --j)
        cout << "L";
    cout << endl;
    int score = read();
    ;
  }
  return 0;
}
