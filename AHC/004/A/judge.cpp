#include <algorithm>
#include <cstdarg>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

bool is_substr(const string &str, int N, const vector<string> &G) {
  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c) {
      bool is_accepted = true;
      for (size_t i = 0; i < str.size(); ++i)
        if (G[r][(c + i) % N] != str[i]) {
          is_accepted = false;
          break;
        }
      if (!is_accepted) continue;
      cerr << "\"" << str << "\": "
           << "starts at (" << r << ", " << c << ")\n";
      return true;
    }

  for (int r = 0; r < N; ++r)
    for (int c = 0; c < N; ++c) {
      bool is_accepted = true;
      for (size_t i = 0; i < str.size(); ++i)
        if (G[(r + i) % N][c] != str[i]) {
          is_accepted = false;
          break;
        }
      if (!is_accepted) continue;
      cerr << "\"" << str << "\": "
           << "starts at (" << r << ", " << c << ")\n";
      return true;
    }

  return false;
}

int main(int argc, const char **argv) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " testcase output\n";
    return 0;
  }

  ifstream testcase(argv[1]);
  ifstream output(argv[2]);

  auto [N, M] = read_elems<int, int>(testcase);
  vector<string> s(M);
  vector<string> G(N);
  for (auto &str : s)
    str = read<string>(testcase);
  for (auto &g : G)
    g = read<string>(output);

  int count = 0;
  for (auto &str : s) {
    cerr << "check: \"" << str << "\"\n";
    if (is_substr(str, N, G) || is_substr(reverse(str), N, G)) {
      count++;
      cerr << "accepted\n";
    } else
      cerr << "rejected\n";
  }
  cout << count << "/ " << M << " accepted\n";
}