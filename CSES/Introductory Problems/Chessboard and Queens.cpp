#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  vector<string> a(8);
  for (int i = 0; i < 8; i++) cin >> a[i];
  vector<int> perm(8);
  iota(perm.begin(), perm.end(), 0);
  int ans = 0;
  while (next_permutation(perm.begin(), perm.end())) {
    set<int> leftDiag, rightDiag, col;
    set<pair<int, int>> valid;
    for (int i = 0; i < 8; i++) {
      leftDiag.insert(perm[i] - i);
      rightDiag.insert(perm[i] + i);
      col.insert(perm[i]);
      if (a[i][perm[i]] == '.') valid.insert({i, perm[i]});
    }
    if (leftDiag.size() == 8 && rightDiag.size() == 8 && col.size() == 8 && valid.size() == 8) {
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
