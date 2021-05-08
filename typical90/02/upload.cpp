#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
namespace lib{
  using i64 = int64_t;
  using u64 = uint64_t;
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
  const int N = read();
  if(N & 1) return 0;
  vector<vector<string>> catalogue(N/2);
  catalogue[0].reserve(1);
  catalogue[0].push_back("()");
  for(int n = 1; 2*n < N; ++n){
    catalogue[n].reserve(catalogue[n].size() + catalogue[n - 1].size());
    for(auto &s : catalogue[n - 1])
      catalogue[n].emplace_back("(" + s + ")");
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        if(2*(i + 1) + 2*(j + 1) == 2*(n + 1)){
          catalogue[n].reserve(catalogue[n].size() + catalogue[i].size()*catalogue[j].size());
          for(auto &s : catalogue[i])
            for(auto &t : catalogue[j])
              catalogue[n].emplace_back(s + t);
        }
    sort(catalogue[n].begin(), catalogue[n].end());
    auto end = unique(catalogue[n].begin(), catalogue[n].end());
    catalogue[n].erase(end, catalogue[n].end());
  }
  for(auto & s: catalogue.back())
    cout << s << "\n";
  cout << flush;
  return 0;
}
