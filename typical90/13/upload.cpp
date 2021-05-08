#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
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
void dijkstra(int start, vector<int> &len, map<int, map<int, int>> &G){
  len[start] = 0;
  std::priority_queue<pair<int, int>> que;
  que.push({0, start});
  while(que.size()){
    auto [time, current] = que.top();
    que.pop();
    for(auto &[v, t] : G[current])
      if(len[v] > -time + t){
        len[v] = -time + t;
        que.push({time - t, v});
      }
  }
}
int main(){
  auto [N, M] = read_elems<int, int>();
  map<int, map<int, int>> G;
  for(int m = 0; m < M; ++m){
    auto [A, B, C] = read_elems<int, int, int>();
    --A, --B;
    G[A][B] = C;
    G[B][A] = C;
  }
  vector<int> length_1(N, 2e9);
  vector<int> length_N(N, 2e9);
  dijkstra(0, length_1, G);
  dijkstra(N - 1, length_N, G);
  for(int k = 0; k < N; ++k)
    cout << length_1[k] + length_N[k] << "\n";
  return 0;
}
