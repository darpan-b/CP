#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  vector<int> odd, even;
  for (int i = 1; i <= n; i++) {
    if (i & 1) odd.push_back(i); else even.push_back(i);
  }
  if (even.size() > 0 && even.back() - odd[0] > 1) {
    for (auto& e : even) cout << e << ' ';
    for (auto& e : odd) cout << e << ' ';
  } else {
    cout << "NO SOLUTION";
  }
  
  return 0;
}
