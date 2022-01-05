#include <bits/stdc++.h>
 
#ifdef LOCAL
#include "debugger.h"
#define dbg(...) cerr << "LINE(" << __LINE__<< ") -> [" << #__VA_ARGS__<< "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#endif
 
using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  std::vector<long long> a(n);
  for (auto& e : a) cin >> e;
  partial_sum(a.begin(), a.end(), a.begin());
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    long long ans = a[r];
    if (l > 0) ans -= a[l - 1];
    cout << ans << "\n";
  }
}
