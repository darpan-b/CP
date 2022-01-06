#include <bits/stdc++.h>
 
#ifdef LOCAL
#include "debugger.h"
#define dbg(...) cerr << "LINE(" << __LINE__<< ") -> [" << #__VA_ARGS__<< "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#endif
 
using namespace std;

template<typename T>
class SegmentTreeLazy {
public:
  vector<T> seg, lazy;

  SegmentTreeLazy() = default;

  SegmentTreeLazy(int n) {
    seg.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
  }

  inline T combine(const T &lhs, const T &rhs) {
    return lhs + rhs;
  }

  void push(int node, int ss, int se) {
    if (ss != se) {
      seg[node * 2 + 1] = combine(seg[node * 2 + 1], lazy[node]);
      seg[node * 2 + 2] = combine(seg[node * 2 + 2], lazy[node]);
      lazy[node * 2 + 1] = combine(lazy[node * 2 + 1], lazy[node]);
      lazy[node * 2 + 2] = combine(lazy[node * 2 + 2], lazy[node]);
    }
    lazy[node] = 0;
  }

  void build(int node, int ss, int se, const vector<T> &a) {
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

  void update(int node, int ss, int se, int us, int ue, const T &val) {
    if (ss > se || us > se || ue < ss) return;
    push(node, ss, se);
    if (ss >= us && se <= ue) {
      seg[node] = combine(seg[node], val);
      lazy[node] = combine(lazy[node], val);
      return;
    }
    int mid = (ss + se) / 2;
    update(node * 2 + 1, ss, mid, us, ue, val);
    update(node * 2 + 2, mid + 1, se, us, ue, val);
    seg[node] = combine(seg[node * 2 + 1], seg[node * 2 + 2]);
  }

  T query(int node, int ss, int se, int qs, int qe) {
    if (ss > se || qs > se || qe < ss) return 0LL;
    push(node, ss, se);
    if (ss >= qs && se <= qe) return seg[node];
    int mid = (ss + se) / 2;
    T leftQuery = query(node * 2 + 1, ss, mid, qs, qe);
    T rightQuery = query(node * 2 + 2, mid + 1, se, qs, qe);
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
  for (auto &e : a) cin >> e;
  SegmentTreeLazy<long long> st(n);
  st.build(0, 0, n - 1, a);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      long long val;
      cin >> l >> r >> val;
      l--;
      r--;
      st.update(0, 0, n - 1, l, r, val);
    } else {
      int idx;
      cin >> idx;
      idx--;
      cout << st.query(0, 0, n - 1, idx, idx) << "\n";
    }
  }  
  return 0;
}
