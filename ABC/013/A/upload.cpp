#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sys/time.h>
#include <vector>
namespace lib {
using i64 = int64_t;
using u64 = uint64_t;
constexpr u64 mod = 1000000007;
template <class T, class V> constexpr T max(const V &v) {
  return *max_element(begin(v), end(v));
}
constexpr u64 gcd(u64 m, u64 n) {
  return m == n ? m
         : m < n ? (n % m == 0 ? m : gcd(n % m, m))
                 : (m % n == 0 ? n : gcd(n, m % n));
}
constexpr u64 max_bit(u64 n) { return n == 0 ? 0 : max_bit(n >> 1) + 1; }
std::string readline(std::istream &src = std::cin) {
  std::string line;
  std::getline(src, line);
  return line;
}
template <class T = int> T read(std::istream &src = std::cin) {
  T buf;
  src >> buf;
  return buf;
}
template <class T = int>
std::vector<T> read_vector(size_t size, std::istream &src = std::cin) {
  std::vector<T> buf(size);
  for (auto &b : buf)
    src >> b;
  return buf;
}
namespace {
template <size_t INDEX, class T> T &read_elem(T &buf, std::istream &) {
  return buf;
}
template <size_t INDEX, class T, class F, class... After>
T &read_elem(T &buf, std::istream &src = std::cin) {
  std::get<INDEX>(buf) = read<F>(src);
  return read_elem<INDEX + 1, T, After...>(buf, src);
}
}
template <class... T>
std::tuple<T...> read_elems(std::istream &src = std::cin) {
  std::tuple<T...> buf;
  return read_elem<0, typeof(buf), T...>(buf, src);
}
namespace {
template <class T> std::string to_string(const T &t, char) {
  return std::to_string(t);
}
template <> [[maybe_unused]] std::string to_string(const std::string &t, char) {
  return t;
}
template <class T> std::string to_string(const std::vector<T> &t, char delim) {
  std::string ret;
  if (t.size()) {
    auto iter = t.begin();
    ret = to_string(*iter, delim);
    for (++iter; iter != t.end(); ++iter)
      ret += delim + to_string(*iter, delim);
  }
  return ret;
}
template <class T> std::string print(const T &t, char delim) {
  return to_string(t, delim);
}
template <class T, class... Args>
std::string print(char delim, const T &t, const Args... args) {
  return to_string(t, delim) + delim + print(args...);
}
}
template <class... Args> std::string print(char delim, const Args... args) {
  return format(delim, args...);
}
std::string strprintf(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char *buffer;
  [[maybe_unused]] int size = vasprintf(&buffer, fmt, ap);
  va_end(ap);
  std::string ret(buffer);
  free(buffer);
  return ret;
}
template <class V> auto sort(V &v) { return sort(begin(v), end(v)); }
std::string reverse(const std::string &str) {
  std::string tmp = str;
  std::reverse(tmp.begin(), tmp.end());
  return tmp;
}
class timer {
  timeval start_time;
  timeval watch_time;
  double diff(const timeval &end, const timeval &start) const {
    return end.tv_sec - start.tv_sec + 1e-6 * (end.tv_usec - start.tv_usec);
  }
public:
  void start() { gettimeofday(&start_time, nullptr); }
  double watch() {
    gettimeofday(&watch_time, nullptr);
    return diff(watch_time, start_time);
  }
};
std::vector<std::vector<u64>> comb(int n, u64 mod = 0) {
  std::vector<std::vector<u64>> v(n + 1, std::vector<u64>(n + 1, 0));
  for (size_t i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  if (mod == 0)
    for (size_t j = 1; j < v.size(); j++)
      for (size_t k = 1; k < j; k++)
        v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
  else
    for (size_t j = 1; j < v.size(); j++)
      for (size_t k = 1; k < j; k++)
        v[j][k] = ((v[j - 1][k - 1] + v[j - 1][k]) % mod);
  return v;
}
}
using namespace std;
using namespace lib;
int main() {
  char X = read<char>();
  cout << (int)(X - 'A' + 1) << endl;
  return 0;
}
