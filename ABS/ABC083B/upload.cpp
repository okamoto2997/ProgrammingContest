#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
namespace lib{
  std::string readline(std::istream& src = std::cin){
    std::string line;
    std::getline(src, line);
    return line;
  }
  template<class T>
  T read(std::istream& src = std::cin){
    T buf;
    src >> buf;
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
constexpr int digit_sum(int n){
  int ret = 0;
  while (n)
    ret += n % 10, n /= 10;
  return ret;
}
int main(){
  auto [N, A, B] = read_elems<int, int, int>();
  int ret = 0;
  for (int n = 1; n <= N; ++n){
    int sum = digit_sum(n);
    ret += (A <= sum && sum <= B ? n : 0);
  }
  cout << ret << endl;
  return 0;
}
