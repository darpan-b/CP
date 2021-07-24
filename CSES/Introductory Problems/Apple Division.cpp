#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 1e18;
  for (int bit = 0; bit < (1 << n); bit++) {
    long long s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) s1 += a[i]; else s2 += a[i];
    }
    ans = min(ans, abs(s1 - s2));
  }
  cout << ans;
  return 0;
}
