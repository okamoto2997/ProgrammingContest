#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <map>
#include <random>
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
bool is_substr(const string &str, int N, const vector<vector<char>> &G) {
  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c) {
      bool is_accepted = true;
      for (size_t i = 0; i < str.size(); ++i)
        if (G[r][(c + i) % N] != str[i]) {
          is_accepted = false;
          break;
        }
      if (!is_accepted) continue;
      return true;
    }
  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c) {
      bool is_accepted = true;
      for (size_t i = 0; i < str.size(); ++i)
        if (G[(r + i) % N][c] != str[i]) {
          is_accepted = false;
          break;
        }
      if (!is_accepted) continue;
      return true;
    }
  return false;
}
int count(int N, const vector<string> &s, const vector<vector<char>> &G) {
  int counter = 0;
  for (auto &str : s)
    if (is_substr(str, N, G) || is_substr(reverse(str), N, G)) counter++;
  return counter;
}
int choose_best(int cur_score, int r, int c, int N, const vector<string> &s,
                vector<vector<char>> &G) {
  int record = cur_score;
  int record_char = G[r][c];
  int cur_gene = G[r][c];
  for (char ch = 'A'; ch <= 'H'; ++ch)
    if (ch != cur_gene) {
      G[r][c] = ch;
      if (int cur_score = count(N, s, G); cur_score > record) {
        record = cur_score;
        record_char = ch;
      }
    }
  G[r][c] = record_char;
  return record;
}
void rotate(bool row, bool reverse, int index, int N, vector<vector<char>> &G) {
  if (row)
    if (reverse) {
      char tmp = G[index][N - 1];
      for (int c = 0; c < N - 1; ++c)
        G[index][c + 1] = G[index][c];
      G[index][0] = tmp;
    } else {
      char tmp = G[index][0];
      for (int c = 1; c < N; ++c)
        G[index][c - 1] = G[index][c];
      G[index][N - 1] = tmp;
    }
  else {
    if (reverse) {
      char tmp = G[N - 1][index];
      for (int r = 0; r < N - 1; ++r)
        G[r + 1][index] = G[r][index];
      G[0][index] = tmp;
    } else {
      char tmp = G[0][index];
      for (int r = 1; r < N; ++r)
        G[r - 1][index] = G[r][index];
      G[N - 1][index] = tmp;
    }
  }
}
int main() {
  timer t;
  t.start();
  auto [N, M] = read_elems<int, int>();
  vector<string> s(M);
  for (auto &str : s)
    str = read<string>();
  vector<vector<char>> G(N, vector<char>(N, '.'));
  vector<vector<char>> prev_G(N, vector<char>(N, '.'));
  mt19937_64 engine;
  uniform_int_distribution<int> rand(0, 7);
  uniform_int_distribution<int> pos(0, N - 1);
  uniform_int_distribution<int> chg(1, 7);
  uniform_real_distribution<double> choose_mixier(0, 1);
  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c)
      G[r][c] = 'A' + rand(engine);
  int score = count(N, s, G);
  while (true) {
    if (t.watch() > 2.9) break;
    int new_score = 0;
    prev_G = G;
    if (auto mixier = choose_mixier(engine); mixier < 0.3) {
      int r = pos(engine);
      int c = pos(engine);
      new_score = choose_best(score, r, c, N, s, G);
    } else {
      int selector = rand(engine);
      bool row = selector & 1;
      bool reverse = selector & 2;
      int index = pos(engine);
      rotate(row, reverse, index, N, G);
      new_score = count(N, s, G);
    }
    if (new_score > score) {
      ;
      ;
      score = new_score;
      continue;
    } else {
      G = prev_G;
    }
  }
  for (auto &g : G) {
    for (auto &c : g)
      cout << c;
    cout << "\n";
  }
  cout << endl;
  return 0;
}
