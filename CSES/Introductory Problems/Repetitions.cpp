#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  cin >> s;
  int cur = 1, ans = 1;
  for (int i = 1; i < (int) s.size(); i++) {
    if (s[i] == s[i - 1]) {
      ++cur;
    } else {
      cur = 1;
    }
    ans = max(ans, cur);
  }
  cout << ans;
  
  return 0;
}
