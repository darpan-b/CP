#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<long long> xpre(n);
  xpre[0] = a[0];
  for (int i = 1; i < n; i++) {
    xpre[i] = xpre[i - 1] ^ a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    long long ans = xpre[r];
    if (l > 0) {
      ans ^= xpre[l - 1];
    }
    cout << ans << "\n";
  }
  return 0;
}
