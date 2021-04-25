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
  template<class T>
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
  int N = read<int>();
  auto a = read_vector<int>(N);
  sort(a.begin(), a.end(), greater<int>());
  int diff = 0;
  for (int i = 0; i < a.size(); i += 2){
    if (a.size() - i > 1)
      diff += a[i] - a[i + 1];
    else
      diff += a[i];
  }
  cout << diff << endl;
  return 0;
}
