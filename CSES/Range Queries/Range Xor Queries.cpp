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
  for (int i = 1; i < n; i++) a[i] ^= a[i - 1];
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    long long answer = a[r];
    if (l > 0) answer ^= a[l - 1];
    cout << answer << "\n";
  }
  return 0;
}
