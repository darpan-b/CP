#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  const long long MOD = 1e9 + 7;
  long long n;
  cin >> n;
  long long ans = 1;
  for (long long i = 1; i <= n; i++) {
    ans *= 2;
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
