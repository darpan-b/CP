#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans{0, 1};
  int cur = 1;
  while (cur < n) {
    vector<int> temp = ans;
    reverse(temp.begin(), temp.end());
    for (auto& e : temp) {
      ans.push_back(e | (1 << cur));
    }
    cur++;
  }
  auto print = [&](int x) {
    for (int i = n - 1; i >= 0; i--) {
      if (x & (1 << i)) cout << 1; else cout << 0;
    }
    cout << '\n';
  };
  for (auto& e : ans) print(e);
  return 0;
}
