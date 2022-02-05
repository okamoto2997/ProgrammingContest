#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sys/time.h>
#include <vector>

#include "lib/log.hpp"
#include "lib/utility.hpp"

#include "lib/graph.hpp"

using namespace std;
using namespace lib;

int main() {
  auto [N, G, E] = read_elems<int, int, int>();
  auto p = read_vector(G);
  small_graph g(N + 1);
  for (auto girl : p)
    g.add_edge(0, girl);
  for (int i = 0; i < E; ++i) {
    auto [a, b] = read_elems<int, int>();
    g.add_edge(a, b);
  }
  return 0;
}