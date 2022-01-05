#include <bits/stdc++.h>
 
#ifdef LOCAL
#include "debugger.h"
#define dbg(...) cerr << "LINE(" << __LINE__<< ") -> [" << #__VA_ARGS__<< "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#endif
 
using namespace std;

template<typename T>
class SegmentTree {
public:
  vector<long long> seg;

  SegmentTree() = default;

  SegmentTree(int n) {
    seg.assign(4 * n, 0);
  }

  inline T combine(const T& lhs, const T& rhs) {
    return lhs + rhs;
  }

  void build(int node, int ss, int se, const vector<T>& a) {
    if (ss > se) return;
    if (ss == se) {
      seg[node] = a[ss];
      return;
    }
    int mid = (ss + se) / 2;
    build(node * 2 + 1, ss, mid, a);
    build(node * 2 + 2, mid + 1, se, a);
    seg[node] = combine(seg[node * 2 + 1], seg[node * 2 + 2]);
  }

  void update(int node, int ss, int se, int uidx, const T& val) {
    if (ss > se || uidx > se || uidx < ss) return;
    if (ss == se && ss == uidx) {
      seg[node] = val;
      return;
    }
    int mid = (ss + se) / 2;
    update(node * 2 + 1, ss, mid, uidx, val);
    update(node * 2 + 2, mid + 1, se, uidx, val);
    seg[node] = combine(seg[node * 2 + 1], seg[node * 2 + 2]);
  }

  T query(int node, int ss, int se, int qs, int qe) {
    if (ss > se || qs > se || qe < ss) return 0LL;
    if (ss >= qs && se <= qe) return seg[node];
    int mid = (ss + se) / 2;
    long long leftQuery = query(node * 2 + 1, ss, mid, qs, qe);
    long long rightQuery = query(node * 2 + 2, mid + 1, se, qs, qe);
    return combine(leftQuery, rightQuery);
  }
};

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto& e : a) cin >> e;
  SegmentTree<long long> st(n);
  st.build(0, 0, n - 1, a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int idx;
      long long val;
      cin >> idx >> val;
      idx--;
      st.update(0, 0, n - 1, idx, val);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << st.query(0, 0, n - 1, l, r) << "\n";
    }
  }
  return 0;
}
