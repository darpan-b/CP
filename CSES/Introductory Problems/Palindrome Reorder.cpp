#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> count(26, 0);
  for (int i = 0; i < n; i++) {
    ++count[s[i] - 'A'];
  }
  int odd = 0;
  for (int i = 0; i < 26; i++) {
    odd += count[i] % 2 == 1;
  }
  if (odd <= 1) {
    int oi = -1;
    string ans = "";
    for (int i = 0; i < 26; i++) {
      if (count[i] & 1 ^ 1) {
        for (int j = 0; j < count[i] / 2; j++) {
          ans += (char) (i + 'A');
        }
      } else {
        oi = i;
      }
    }
    cout << ans;
    reverse(ans.begin(), ans.end());
    if (oi != -1) {
      for (int i = 0; i < count[oi]; i++) {
        cout << (char) (oi + 'A');
      }
    }
    cout << ans;
  } else {
    cout << "NO SOLUTION";
  }
  return 0;
}
