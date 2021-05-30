#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <numeric>
namespace lib {
  using i64 = int64_t;
  using u64 = uint64_t;
  constexpr u64 mod = 1000000007;
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
  int N = read();
  vector<u64> a(2 * N);
  vector<char> c(2 * N);
  int R = 0, G = 0, B = 0;
  for (int n = 0; n < 2 * N; ++n){
    tie(a[n], c[n]) = read_elems<u64, char>();
    switch (c[n]){
    case 'R':
      ++R;
      break;
    case 'G':
      ++G;
      break;
    case 'B':
      ++B;
      break;
    }
  }
  R %= 2;
  G %= 2;
  B %= 2;
  if (R + G + B == 0){
    cout << 0 << endl;
    return 0;
  }
  char balanced = '\0';
  if (R == 0) balanced = 'R';
  if (G == 0) balanced = 'G';
  if (B == 0) balanced = 'B';
  vector<int> index; index.reserve(2 * N);
  for (int n = 0; n < 2 * N; ++n)
    if (c[n] != balanced)
      index.push_back(n);
  sort(index.begin(), index.end(), [&a](int i, int j){return a[i] < a[j];});
  u64 min = 1e16;
  u64 prev_a = a[index[0]];
  char prev_c = c[index[0]];
  for (auto i : index){
    if (c[i] != prev_c){
      min = std::min(min, a[i] - prev_a);
      prev_c = c[i];
      if (min == 0) break;
    }
    prev_a = a[i];
  }
  cout << min << "\n";
  return 0;
}
