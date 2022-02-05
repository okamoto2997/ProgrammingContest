#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <sys/time.h>
#include <vector>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

// void update(int a, int b, int left, int size, int idx, vector<int> &heap) {
//   int c = size / 2 + left;

//   if(a == left and b - a - 1 == size )

//   if (b <= c) {
//     update(a, b, left, size / 2, idx * 2, heap);
//   } else if (a < c) {
//     update(a, a + size / 2, left, size / 2, idx * 2, heap);
//     update(a + size / 2, b, left + size / 2, size / 2, idx * 2 + 1, heap);
//   } else {
//     update(a, b, left + size / 2, size / 2, idx * 2 + 1, heap);
//   }
// }

int main() {
  const int n = read();
  vector<int> imos(1000001, 0);
  for (int i = 0; i < n; ++i) {
    auto [a, b] = read_elems<int, int>();
    imos[a]++;
    if (b < 1000000) imos[b + 1]--;
  }

  for (int i = 1; i < imos.size(); ++i)
    imos[i] += imos[i - 1];

  int max_pop = 0;
  for (auto i : imos)
    max_pop = max(max_pop, i);
  cout << max_pop << endl;

  //  size_t heap_size = 1;
  // while (heap_size < n)
  //   heap_size <<= 1;
  // heap_size <<= 1;
  // vector<int> popularity(heap_size, 0);
  // list<pair<int, int>> popurarity;
  // popurarity.emplace_front(1000001, 0);

  // for (int i = 0; i < n; ++i) {
  //   auto [a, b] = read_elems<int, int>();
  //   ++b;
  //   int prev = 0;
  //   for (auto iter = popurarity.begin(); iter != popurarity.end();
  //   ++iter) {
  //     auto [sup, pop] = *iter;
  //     // cout << "current intv: " << sup << ") = " << pop << "\n";
  //     if (prev < a and a < sup) popurarity.insert(iter, make_pair(a,
  //     pop)); if (b < sup) {
  //       popurarity.insert(iter, make_pair(b, pop + 1));
  //       break;
  //     }
  //     if (a < sup and b >= sup) iter->second++;
  //     prev = sup;
  //   }
  //   prev = 0;
  //   // cout << "# " << i + 1 << " times intervals\n";
  //   // for (auto [sup, pop] : popurarity)
  //   //   cout << "[" << prev << ", " << sup << ") = " << pop << "\n",
  //   prev =
  //   //   sup;
  // }

  // int max_pop = 0;
  // for (auto [sup, pop] : popurarity)
  //   max_pop = max(max_pop, pop);

  // cout << max_pop << endl;

  return 0;
}