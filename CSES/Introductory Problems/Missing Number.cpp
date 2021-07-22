#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 1; i < n - 1; i++) {
    if (a[i] != a[i - 1] + 1) {
      cout << a[i - 1] + 1;
      return 0;
    }
  }
  if (a[0] == 1) cout << n;
  else cout << 1;
  
  return 0;
}
