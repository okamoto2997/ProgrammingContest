#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

size_t count_color(vector<int> color, const vector<set<int>>& G){
  vector<int> stack(1, 0);
  vector<bool> visited(color.size(), false);
  int selected_vertex = -1;

  while (stack.size() > 0){
    int pivot = stack.back(); stack.pop_back();
    if (visited[pivot])
      break;
    else
      visited[pivot] = true;
    for (auto v : G[pivot])
      if (color[v] < 0){
        selected_vertex = v;
        break;
      }
      else if (!visited[v])
        stack.push_back(v);
    if (selected_vertex > 0)
      break;
  }

  if (selected_vertex < 0)
    return 1;

  vector<bool> candidate(3, true);

  for (auto v : G[selected_vertex])
    if (color[v] >= 0)
      candidate[color[v]] = false;

  size_t ret = 0;
  for (int i = 0; i < 3; ++i)
    if (candidate[i]){
      color[selected_vertex] = i;
      ret += count_color(color, G);
    }
  return ret;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<set<int>> G(N, set<int>());
  for (int m = 0; m < M; ++m){
    int A, B;
    cin >> A >> B;
    --A, --B;
    G[A].emplace(B);
    G[B].emplace(A);
  }
  vector<int> color(N, -1);
  vector<int> stack;
  vector<bool> visit(N, false);

  color[0] = 0;
  stack.push_back(0);
  while (stack.size() > 0){
    int pivot = stack.back(); stack.pop_back();
    if (visit[pivot])
      continue;
    else
      visit[pivot] = true;
    for (auto v : G[pivot])
      if (!visit[v]) stack.push_back(v);
  }

  uint64_t total = count_color(color, G);

  for (auto b : visit)
    if (!b)
      total *= 3;

  cout << 3 * total << endl;

  return 0;
}