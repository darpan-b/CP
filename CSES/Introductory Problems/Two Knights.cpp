#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cout << (i * i * (i * i - 1)) / 2 - 4 * (i - 1) * (i - 2) << '\n';
  }
  return 0;
}
