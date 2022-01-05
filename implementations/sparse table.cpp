template<typename T>
class SparseTable {
public:
  int n, logn;
  vector<vector<T>> sparse;

  SparseTable() = default;

  SparseTable(int n) {
    this->n = n;
    logn = __lg(n) + 2;
    sparse.assign(n, vector<T>(logn, 0));
  }

  inline T combine(const T& lhs, const T& rhs) {
    return min(lhs, rhs);
  }

  void build(const vector<T>& a) {
    for (int i = 0; i < n; i++) sparse[i][0] = a[i];
    for (int i = 1; i < logn; i++) {
      for (int j = 0; j < n; j++) {
        if (j + (1 << (i - 1)) >= n) continue;
        sparse[j][i] = combine(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
      }
    }
  }

  T query(int l, int r) {
    int logsz = __lg(r - l + 1);
    return combine(sparse[l][logsz], sparse[r - (1 << logsz) + 1][logsz]);
  }
};
