struct DSU {
    vector<int> root;
    vector<int> ranks;
    DSU() {
        root.clear();
        ranks.clear();
    }
    DSU(int _n) {
        root.assign(_n, 0);
        ranks.assign(_n, 0);
        for (int i = 0; i < _n; i++) {
            root[i] = i;
            ranks[i] = 1;
        }
    }
    int findroot(int node) {
        if (root[node] == node) return node;
        else return root[node] = findroot(root[node]);
    }
    bool sameComp(int u, int v) {
        u = findroot(u);
        v = findroot(v);
        return u == v;
    }
    bool unite(int u, int v) {
        u = findroot(u);
        v = findroot(v);
        if (u == v) {
            return false;
        }
        if (ranks[u] > ranks[v]) {
            ranks[u] += ranks[v];
            root[v] = u;
        } else {
            ranks[v] += ranks[u];
            root[u] = v;
        }
        return true;
    }
};
