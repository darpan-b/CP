#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const long long INF = 1e18;

long long a[MAXN];
long long seg[4 * MAXN];

void build(int node, int ss, int se)
{
  if (ss > se) {
    return;
  }
  if (ss == se) {
    seg[node] = a[ss];
  } else {
    int mid = (ss + se) / 2;
    build(node * 2 + 1, ss, mid);
    build(node * 2 + 2, mid + 1, se);
    seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
  }
}

void update(int node, int ss, int se, int idx, long long val)
{
  if (ss > se || idx > se || idx < ss) {
    return;
  }
  if (ss == se && ss == idx) {
    seg[node] = val;
  } else {
    int mid = (ss + se) / 2;
    update(node * 2 + 1, ss, mid, idx, val);
    update(node * 2 + 2, mid + 1, se, idx, val);
    seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
  }
}

long long query(int node, int ss, int se, int qs, int qe)
{
  if (ss > se || qs > se || qe < ss) {
    return INF;
  }
  if (ss >= qs && se <= qe) {
    return seg[node];
  }
  int mid = (ss + se) / 2;
  long long ql = query(node * 2 + 1, ss, mid, qs, qe);
  long long qr = query(node * 2 + 2, mid + 1, se, qs, qe);
  return min(ql, qr);
}

int main(int argc, const char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, 0, n - 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k;
      long long u;
      cin >> k >> u;
      k--;
      update(0, 0, n - 1, k, u);
    } else {
      int l, r;
      cin >> l >> r;
      l--; r--;
      cout << query(0, 0, n - 1, l, r) << "\n";
    }
  }
  return 0;
}
