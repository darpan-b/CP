#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long ans = 0, cur = 1;
  while (true) {
    ans += n / pow(5, cur);
    ++cur;
    if (n < pow(5, cur)) break;
  }
  cout << ans << '\n';
  return 0;
}
