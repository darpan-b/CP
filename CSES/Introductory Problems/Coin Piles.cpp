#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);
  long long q = (2 * b - a) / 3, p = q + a - b;
  if ((2 * b - a) % 3 == 0 && 2 * b - a >= 0 && a == 2 * p + q && b == 2 * q + p) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) solve();
  return 0;
}
