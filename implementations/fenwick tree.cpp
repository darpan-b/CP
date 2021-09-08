template<typename T>
struct FenwickTree {
    int n;
    vector<T> tree;
    FenwickTree(): n(), tree() {}
    FenwickTree(int _n): n(_n), tree(n + 5, 0) {}

    void update(int idx, T val) {
        idx++;
        while (idx <= n) {
            tree[idx] += val;
            idx += (idx & (-idx));
        }
    }
    T query(int idx) {
        idx++;
        long long res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= (idx & (-idx));
        }
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
