#pragma once

namespace lib {

struct graph {
  const u64 V;
  std::vector<std::vector<u64>> edge;
  graph(u64 V) : V(V), edge(V) {}

  void add_edge(u64 from, u64 to, bool is_directed = false) {
    edge[from].push_back(to);
    if (not is_directed) edge[to].push_back(from);
  }

  std::vector<u64> simple_tree(u64 root = 0) const {
    std::vector<u64> ret(V, V);
    ret[root] = root;
    std::vector<u64> stack(1, root);
    while (stack.size()) {
      auto top = stack.back();
      stack.pop_back();
      for (auto to : edge[top])
        if (ret[to] == V) {
          ret[to] = top;
          stack.push_back(to);
        }
    }
    return ret;
  }
};

std::vector<u64> calc_depth(const std::vector<u64> &parent, u64 root = 0) {
  std::vector<u64> depth(parent.size(), parent.size());
  depth[root] = 0;

  auto set = [&](u64 idx, auto &&self) {
    if (depth[parent[idx]] < parent.size()) {
      if (parent[idx] != idx) return depth[idx] = depth[parent[idx]] + 1;
      else
        return depth[idx];
    } else
      return depth[idx] = self(parent[idx], self) + 1;
  };

  for (size_t i = 0; i < depth.size(); ++i)
    set(i, set);
  return depth;
}

// u64 max_flow(const small_graph &g, u64 start, u64 goal) {
//   std::vector<std::vector<u64>> remains = g.edge;
// }

} // namespace lib