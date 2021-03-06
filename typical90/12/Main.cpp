#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdarg>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int find_root(int index, vector<int>& root) {
  // cerr << "find root of " << index << ", parent: " << root[index] << "\n";
  if (root[index] == index) return index;
  return root[index] = find_root(root[index], root);
}

int main() {
  auto [H, W] = read_elems<int, int>();
  auto idx = [W = W](int r, int c) {return r * W + c;};
  vector<int> root(H * W, -1);
  int Q = read();
  vector<int> neighbor; neighbor.reserve(4);
  for (int q = 0; q < Q; ++q) {
    // cerr << "current state:\n";
    // for (int h = 0; h < H; ++h) {
    //   for (int w = 0; w < W; ++w)
    //     cerr << (root[idx(h, w)] < 0 ? 'o' : 'X');
    //   cerr << "\n";
    // }
    int t = read();
    if (t == 1) {
      // cerr << "draw:\n";
      auto [r, c] = read_elems<int, int>();
      --r, --c;
      // cerr << "r: " << r << ", c: " << c << "\n";
      int index = idx(r, c);
      if (root[index] < 0) {
        neighbor.clear();
        if (r > 0 && root[idx(r - 1, c)] >= 0) neighbor.emplace_back(idx(r - 1, c));
        if (H - 1 > r && root[idx(r + 1, c)] >= 0) neighbor.emplace_back(idx(r + 1, c));
        if (c > 0 && root[idx(r, c - 1)] >= 0) neighbor.emplace_back(idx(r, c - 1));
        if (W - 1 > c && root[idx(r, c + 1)] >= 0) neighbor.emplace_back(idx(r, c + 1));

        // if (neighbor.size() == 0) {
        //   root[index] = index;
        // }
        // else if (neighbor.size() == 1) {
        //   root[index] = find_root(neighbor[0], root);
        // }
        // else {
        root[index] = index;
        for (auto n : neighbor)
          root[find_root(n, root)] = index;
        // }
      }
    }
    else if (t == 2) {
      // cerr << "check:\n";
      auto [ra, ca, rb, cb] = read_elems<int, int, int, int>();
      --ra, --ca, --rb, --cb;
      // cerr << "from (" << ra << ", " << ca << ") to (" << rb << ", " << cb << ")\n";
      const int ia = idx(ra, ca);
      const int ib = idx(rb, cb);
      // cerr << "root of a: " << (root[ia] >= 0 ? find_root(ia, root) : root[ia]) << "\n";
      // cerr << "root of b: " << (root[ib] >= 0 ? find_root(ib, root) : root[ib]) << "\n";
      cout << (root[ia] >= 0 && root[ib] >= 0 && find_root(ia, root) == find_root(ib, root) ? "Yes" : "No") << "\n";
    }
    // cerr << "\n";
  }
  cout << flush;
  return 0;
}