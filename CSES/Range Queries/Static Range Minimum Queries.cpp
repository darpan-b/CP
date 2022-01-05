#include <bits/stdc++.h>
 
#ifdef LOCAL
#include "debugger.h"
#define dbg(...) cerr << "LINE(" << __LINE__<< ") -> [" << #__VA_ARGS__<< "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#endif
 
using namespace std;

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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto& e : a) cin >> e;
  SparseTable<long long> st(n);
  st.build(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << st.query(l, r) << "\n";
  }
  return 0;
}
