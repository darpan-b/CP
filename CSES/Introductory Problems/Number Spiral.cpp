#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long a, b;
  cin >> a >> b;
  long long prev = max(a, b) - 1;
  long long cur = prev + 1;
  long long ans = prev * prev;
  if (prev & 1) {
    if (a >= b) {
      ans += cur;
      ans += cur - b;
    } else {
      ans += a;
    }
  } else {
    if (a >= b) {
      ans += b;
    } else {
      ans += cur;
      ans += cur - a;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int test;
  cin >> test;
  while (test--) solve();
  return 0;
}
