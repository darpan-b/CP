#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  ans.push_back({1, 3});
  for (int i = 2; i <= n; i++) {
    vector<pair<int, int>> temp = ans;
    ans.clear();
    for (auto& e : temp) {
      auto cur = e;
      if (cur.first == 2) {
        cur.first = 3;
      } else if (cur.first == 3) {
        cur.first = 2;
      }
      if (cur.second == 2) {
        cur.second = 3;
      } else if (cur.second == 3){
        cur.second = 2;
      }
      ans.push_back(cur);
    }
    ans.push_back({1, 3});
    for (auto& e : temp) {
      auto cur = e;
      if (cur.first == 2) {
        cur.first = 1;
      } else if (cur.first == 1) {
        cur.first = 2;
      }
      if (cur.second == 2) {
        cur.second = 1;
      } else if (cur.second == 1){
        cur.second = 2;
      }
      ans.push_back(cur);
    }
  }
  cout << ans.size() << '\n';
  for (auto& e : ans) cout << e.first << ' ' << e.second << '\n';
  return 0;
}
