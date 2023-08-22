struct DSU {
  vector<int> roots, ranks;

  DSU() {
    roots.clear();
    ranks.clear();
  }

  DSU(int n) {
    roots.assign(n + 1, 0);
    ranks.assign(n + 1, 0);
    iota(roots.begin(), roots.end(), 0);
  }

  int findroot(int u) {
    if (roots[u] == u) return u;
    return roots[u] = findroot(roots[u]);
  }

  bool unite(int u, int v) {
    u = findroot(u), v = findroot(v);
    if (u == v) return false;
    if (ranks[v] > ranks[u]) swap(u, v);
    roots[v] = u;
    ranks[u] += ranks[v];
    return true;
  }
};
