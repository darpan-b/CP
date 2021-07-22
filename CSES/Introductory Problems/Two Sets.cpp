#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> set1, set2;
  if (n % 4 == 0) {
    for (int i = 1; i <= n; i++) {
      if (i % 4 == 0 || i % 4 == 1) {
        set1.push_back(i);
      } else {
        set2.push_back(i);
      }
    }
  } else {
    if ((n - 3) % 4 == 0) {
      set1.push_back(1);
      set1.push_back(2);
      set2.push_back(3);
      for (int i = 4; i <= n; i++) {
        if (i % 4 == 0 || i % 4 == 3) {
          set1.push_back(i);
        } else {
          set2.push_back(i);
        }
      }
    }
  }
  if (!set1.empty()) {
    cout << "YES\n";
    cout << set1.size() << '\n';
    for (auto& e : set1) cout << e << ' ';
    cout << '\n';
    cout << set2.size() << '\n';
    for (auto& e : set2) cout << e << ' ';
    cout << '\n';
  } else {
    cout << "NO\n";
  }
  return 0;
}
