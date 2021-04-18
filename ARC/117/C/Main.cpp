#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

constexpr uint64_t MOD = 1000000007;

int main(){
  int N;
  cin >> N;
  string C;
  cin >> C;

  unordered_map<string, string> rule;

  rule["BB"] = "BB";
  rule["BW"] = "RW";
  rule["BR"] = "WR";
  rule["WB"] = "RB";
  rule["WW"] = "WW";
  rule["WR"] = "BR";
  rule["RB"] = "WB";
  rule["RW"] = "BW";
  rule["RR"] = "RR";

  for (size_t i = 1; i < C.size(); ++i){
    string prev = C;
    int j = i;
    set<pair<int, int>> log;
    while (j > 0){
      for (int k = 0; k < j; ++k){
        if (rule.find(C.substr(k, j - k + 1)) != rule.end()){
          C.replace(k, j - k + 1, rule[C.substr(k, j - k + 1)]);
          // cerr << "\"" << C << "\"" << endl;
          j = k + 1;
          break;
        }
        else
          log.emplace(k, j - k + 1);
      }
    }

    for (auto [start, len] : log)
      if (rule.find(prev.substr(start, len)) == rule.end())
        rule[prev.substr(start, len)] = C.substr(start, len);

    cerr << "rule: \n";
    for (auto [key, value] : rule){
      cerr << key << " -> " << value << "\n";
    }

    // for (size_t skip = 4; skip <= i; skip += 2)
    //   for (size_t k = 0; k + skip <= i; ++k)
    //     if (rule.find(prev.substr(k, skip)) == rule.end())
    //       rule[prev.substr(k, skip)] = C.substr(k, skip);

    cerr << "\"" << C << "\"" << endl;
  }

  cout << C[0] << endl;

  return 0;
  while (C.size() > 1){
    for (size_t i = 0; i < C.size() - 1; ++i)
      C[i] = rule[C.substr(i, 2)].back();
    C.pop_back();
    cerr << "\"" << C << "\"" << endl;
  }
  cout << C.back() << endl;


  return 0;
}