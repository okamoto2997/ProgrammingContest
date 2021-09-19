#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <list>
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
}
using namespace std;
using namespace lib;
struct point {
  double x, y;
};
void move_to_origin(vector<point> &U) {
  point c = {0, 0};
  for (const auto &u : U)
    c.x += u.x, c.y += u.y;
  c.x /= U.size();
  c.y /= U.size();
  for (auto &u : U)
    u.x -= c.x, u.y -= c.y;
}
bool enough_near(const point &u1, const point &u2, double eps) {
  return hypot(u1.x - u2.x, u1.y - u2.y) < eps;
}
int main() {
  int N = read();
  vector<point> S(N), T(N);
  for (int n = 0; n < N; ++n)
    tie(S[n].x, S[n].y) = read_elems<int, int>();
  for (int n = 0; n < N; ++n)
    tie(T[n].x, T[n].y) = read_elems<int, int>();
  move_to_origin(S);
  move_to_origin(T);
  if (N == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  ;
  for (auto s : S)
    ;
  ;
  for (auto t : T)
    ;
  int pivot = (S[0].x * S[0].y ? 1 : 0);
  const double eps = 1e-6;
  const double dist = hypot(S[pivot].x, S[pivot].y);
  const double theta = atan2(S[pivot].y, S[pivot].x);
  ;
  ;
  for (int n = 0; n < N; ++n) {
    ;
    if (fabs(hypot(T[n].x, T[n].y) - dist) < eps) {
      ;
      const double dtheta = theta - atan2(T[n].y, T[n].x);
      const double c = cos(dtheta);
      const double s = sin(dtheta);
      ;
      ;
      list<point> tmp;
      for (int i = 0; i < N; ++i)
        tmp.emplace_back(
            point{T[i].x * c - T[i].y * s, T[i].x * s + T[i].y * c});
      for (int i = 0; i < N; ++i) {
        auto iter = tmp.end();
        for (iter = tmp.begin(); iter != tmp.end(); ++iter)
          if (enough_near(*iter, S[i], eps)) break;
        if (iter != tmp.end()) tmp.erase(iter);
        else {
          ;
          break;
        }
      }
      for (auto p : tmp)
        ;
      if (tmp.empty()) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  ;
  cout << "No" << endl;
  return 0;
}
