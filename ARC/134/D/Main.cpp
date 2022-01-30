#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sys/time.h>
#include <vector>

#include "lib/log.hpp"
#include "lib/utility.hpp"

using namespace std;
using namespace lib;

int main() {
  int N = read();
  vector<int> a = read_vector(2 * N);

  map<int, deque<int>> data;
  for (int i = 0; i < N; ++i)
    data[a[i]].push_back(i);

  vector<int> indices;
  int last_index = -1;
  for (auto [value, index_list] : data) {
    if (indices.size() == 0) {
      int min_value = value + 1, min_index = -1;
      for (auto i : index_list)
        if (a[i + N] < min_value) min_value = a[i + N], min_index = i;
      if (min_value < value) indices.push_back(min_index);
    }
    if (indices.size() == 0 or (value <= a[indices.front() + N]))
      for (int i : index_list)
        if (last_index < i) {
          indices.push_back(i);
          last_index = i;
        }
  }

  for (auto i : indices)
    cout << a[i] << " ";
  for (auto i : indices)
    cout << a[i + N] << " ";
  cout << endl;
  return 0;
}