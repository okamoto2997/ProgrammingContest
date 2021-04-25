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
int main(){
  int N = read();
  int cur_t = 0, cur_x = 0, cur_y = 0;
  bool impossibble = false;
  for (size_t n = 0; n < N; ++n){
    auto [t, x, y] = read_elems<int, int, int>();
    impossibble |= (t % 2 != (x + y) % 2);
    impossibble |= (t - cur_t) < abs(x - cur_x) + abs(y - cur_y);
    if (impossibble) break;
    cur_t = t;
    cur_x = x;
    cur_y = y;
  }
  cout << (impossibble ? "No" : "Yes") << endl;
  return 0;
}
