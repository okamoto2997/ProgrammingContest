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
constexpr u64 mod2 = 998244353;
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
namespace lib {
struct graph {
  const u64 V;
  std::vector<std::vector<u64>> edge;
  graph(u64 V) : V(V), edge(V) {}
  void add_edge(u64 from, u64 to, bool is_directed = false) {
    edge[from].push_back(to);
    if (not is_directed) edge[to].push_back(from);
  }
  std::vector<u64> simple_tree(u64 root = 0) const {
    std::vector<u64> ret(V, V);
    ret[root] = root;
    std::vector<u64> stack(1, root);
    while (stack.size()) {
      auto top = stack.back();
      stack.pop_back();
      for (auto to : edge[top])
        if (ret[to] == V) {
          ret[to] = top;
          stack.push_back(to);
        }
    }
    return ret;
  }
};
std::vector<u64> calc_depth(const std::vector<u64> &parent, u64 root = 0) {
  std::vector<u64> depth(parent.size(), parent.size());
  depth[root] = 0;
  auto set = [&](u64 idx, auto &&self) {
    if (depth[parent[idx]] < parent.size()) {
      if (parent[idx] != idx) return depth[idx] = depth[parent[idx]] + 1;
      else
        return depth[idx];
    } else
      return depth[idx] = self(parent[idx], self) + 1;
  };
  for (size_t i = 0; i < depth.size(); ++i)
    set(i, set);
  return depth;
}
}
using namespace std;
using namespace lib;
int main() {
  auto [N, M] = read_elems<int, int>();
  graph g(N);
  for (int i = 0; i < M; ++i) {
    auto [A, B] = read_elems<int, int>();
    --A, --B;
    g.add_edge(A, B);
  }
  vector<vector<int>> ff_table(N, vector<int>(N, 0));
  for (int i = 0; i < N; ++i) {
    int total_ff = 0;
    for (auto f : g.edge[i])
      for (auto ff : g.edge[f])
        ff_table[i][ff] = 1;
    for (auto f : g.edge[i])
      ff_table[i][f] = 0;
    ff_table[i][i] = 0;
    for (int j = 0; j < N; ++j)
      total_ff += ff_table[i][j];
    cout << total_ff << endl;
  }
  return 0;
}
