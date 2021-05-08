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
int find_root(int index, vector<int> &root){
  if(root[index] == index) return index;
  return root[index] = find_root(root[index], root);
}
int main(){
  auto [H, W] = read_elems<int, int>();
  auto idx = [W = W](int r, int c){return r*W + c;};
  vector<int> root(H*W, -1);
  int Q = read();
  vector<int> neighbor; neighbor.reserve(4);
  for(int q = 0; q < Q; ++q){
    int t = read();
    if(t == 1){
      auto [r, c] = read_elems<int, int>();
      --r, --c;
      int index = idx(r, c);
      if(root[index] < 0){
        if(r > 0 && root[idx(r - 1, c)] > 0) neighbor.emplace_back(idx(r - 1, c));
        if(H - 1 > r && root[idx(r + 1, c)] > 0) neighbor.emplace_back(idx(r + 1, c));
        if(c > 0 && root[idx(r, c - 1)] > 0) neighbor.emplace_back(idx(r, c - 1));
        if(W - 1 > c && root[idx(r, c + 1)] > 0) neighbor.emplace_back(idx(r, c + 1));
        if(neighbor.size() == 0){
          root[index] = index;
          continue;
        }else if(neighbor.size() == 1){
          root[index] = find_root(neighbor.back(), root);
          continue;
        }else{
          root[index] = index;
          for(auto n : neighbor)
            root[n] = index;
        }
      }
    }else if (t == 2){
      auto [ra, ca, rb, cb] = read_elems<int, int, int, int>();
      --ra, --ca, --rb, --cb;
      const int ia = idx(ra, ca);
      const int ib = idx(rb, cb);
      cout << (root[ia] > 0 && root[ib] > 0 && root[ia] == root[ib] ? "Yes" : "No") << "\n";
    }
  }
  cout << flush;
  return 0;
}
