#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
namespace std
{
  typedef long unsigned int size_t;
  typedef long int ptrdiff_t;
  typedef decltype(nullptr) nullptr_t;
}
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
namespace std
{
  using ::va_list;
}
namespace lib{
  using i64 = int64_t;
  using u64 = uint64_t;
  template<class T, class V>
  constexpr T max(const V& v){
    return *max_element(begin(v), end(v));
  }
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
    std::string print(const T& t){
      return std::to_string(t);
    }
    template<class T, class ...Args>
    std::string print(char delim, const T& t, const Args... args){
      return std::to_string(t) + delim + print(args...);
    }
  }
  template<class ...Args>
  std::string print(char delim, const Args... args){
    return format(delim, args...);
  }
  std::string strprintf(const char* fmt, ...){
    va_list ap;
   __builtin_va_start(
   ap
   ,
   fmt
   )
                    ;
    char* buffer;
    [[maybe_unused]] int size = vasprintf(&buffer, fmt, ap);
   __builtin_va_end(
   ap
   )
             ;
    std::string ret(buffer);
    free(buffer);
    return ret;
  }
}
using namespace std;
using namespace lib;
int main(){
  int N = read();
  cout << strprintf("%02d:%02d:%02d", N / 3600, N / 60 % 60, N % 60) << endl;
  return 0;
}
