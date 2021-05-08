#include <iostream>
#include <vector>
#include <set>
#include <map>
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
int score(vector<int> &players, const vector<vector<int>> &A){
  int ret = 0;
  for(size_t i = 0; i < players.size(); ++i)
    ret += A[players[i]][i];
  return ret;
}
void search_minscore(int current_level, vector<int> &players, set<int> &bench, int N, int &min_score, const vector<vector<int>> &A, map<int, set<int>> &bad){
  if(score(players, A) > min_score) return;
  if(current_level == N){
    min_score = min(min_score, score(players, A));
  }else{
    for(auto iter = bench.begin(); iter != bench.end(); ++iter){
      int player = *iter;
      if(players.size() > 0 && bad[players.back()].count(player))
        continue;
      else{
        players.push_back(player);
        bench.erase(iter);
        search_minscore(current_level + 1, players, bench, N, min_score, A, bad);
        iter = bench.insert(player).first;
        players.pop_back();
      }
    }
  }
}
int main(){
  int N = read();
  vector<vector<int>> A(N);
  for(auto &a : A)
    a = read_vector<int>(N);
  int M = read();
  map<int, set<int>> bad;
  for(int m = 0; m < M; ++m){
    auto [X, Y] = read_elems<int, int>();
    --X, --Y;
    bad[X].emplace(Y);
    bad[Y].emplace(X);
  }
  vector<int> players; players.reserve(N);
  set<int> bench; for(int i = 0; i < N; ++i) bench.emplace(i);
  int min_score = 1000000;
  search_minscore(0, players, bench, N, min_score, A, bad);
  cout << (min_score == 1000000 ? -1 : min_score) << endl;
  return 0;
}
