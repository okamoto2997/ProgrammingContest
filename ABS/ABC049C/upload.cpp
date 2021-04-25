#include <iostream>
#include <string>
#include <vector>
#include <set>
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
  auto S = read<string>();
  vector<string> candidates = { "dream", "dreamer", "erase", "eraser" };
  set<pair<int, int>> states;
  states.emplace(-1, 0);
  for (auto c : S){
    set<pair<int, int>> next_states;
    cerr << "char: " << c << "\n";
    for (auto iter = states.begin(); iter != states.end(); ++iter){
      auto [candidate, index] = *iter;
      if (candidate < 0){
        cerr << "emplty state detected\n";
        for (size_t i = 0; i < candidates.size(); ++i)
          if (c == candidates[i][0])
            next_states.emplace(i, 0);
      }
      else{
        cerr << "state: " << candidates[candidate] << "\n";
        if (candidates[candidate][index + 1] == c){
          if (candidates[candidate].size() == index + 2)
            next_states.emplace(-1, 0);
          else
            next_states.emplace(candidate, index + 1);
        }
      }
    }
    states = next_states;
    if (states.size() == 0)
      break;
  }
  for (auto [i, index] : states){
    cerr << "candidate: " << (i < 0 ? string("*") : candidates[i]) << " with index: " << index << "\n";
  }
  cout << (states.find(make_pair(-1, 0)) != states.end() ? "YES" : "NO") << endl;
  return 0;
}
