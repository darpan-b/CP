// trying out a new coding style

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto &i : a) { cin >> i; }
  
  const long long INF = 1e18;
  vector<vector<long long>> sparse(n, vector<long long>(20, INF));
  for (int i = 0; i < n; i++) { sparse[i][0] = a[i]; }
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n; j++) {
      if (j + (1 << (i - 1)) >= n) { continue; }
      sparse[j][i] = min(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
    }
  }
  
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    int logSz = __lg(r - l + 1);
    cout << min(sparse[l][logSz], sparse[r - (1 << logSz) + 1][logSz]) << "\n";
  }
  return 0;
}
