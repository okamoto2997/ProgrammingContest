#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
void set_parent(int pivot, const vector<vector<int>>& neighbor, vector<int>& parent, vector<int>& count) {
  count[pivot] = 1;
  for (auto n : neighbor[pivot])
    if (parent[n] < 0) {
      parent[n] = pivot;
      set_parent(n, neighbor, parent, count);
      count[pivot] += count[n];
    }
}
u64 count_func(int pivot, u64 others, const vector<vector<int>>& neighbor, const vector<int>& parent, const vector<int>& count) {
  u64 ret = others * count[pivot];
  for (auto n : neighbor[pivot])
    if (n != parent[pivot])
      ret += count_func(n, others + count[pivot] - count[n], neighbor, parent, count);
  return ret;
}
int main() {
  int N = read();
  vector<vector<int>> neighbor(N);
  for (int n = 0; n < N - 1; ++n) {
    auto [a, b] = read_elems<int, int>();
    --a, --b;
    neighbor[a].emplace_back(b);
    neighbor[b].emplace_back(a);
  }
  vector<int> parent(N, -1);
  vector<int> count(N, -1);
  parent[0] = 0;
  set_parent(0, neighbor, parent, count);
  cout << count_func(0, 0, neighbor, parent, count) << endl;
  return 0;
}
