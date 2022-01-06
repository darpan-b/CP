#include <bits/stdc++.h>
 
#ifdef LOCAL
#include "debugger.h"
#define dbg(...) cerr << "LINE(" << __LINE__<< ") -> [" << #__VA_ARGS__<< "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#endif
 
using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<string> a(n);
  for (auto &e : a) cin >> e;
  vector<vector<int>> pre(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i - 1 >= 0) pre[i][j] += pre[i - 1][j];
      if (j - 1 >= 0) pre[i][j] += pre[i][j - 1];
      pre[i][j] += a[i][j] == '*';
      if (i - 1 >= 0 && j - 1 >= 0) pre[i][j] -= pre[i - 1][j - 1];
    }
  }
  dbg("HELLO");
  while (q--) {
    int y1, x1, y2, x2;
    // cin >> y1 >> x1 >> y2 >> x2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    x2--;
    y1--;
    y2--;
    int answer = pre[x2][y2];
    dbg(answer);
    if (x1 - 1 >= 0) answer -= pre[x1 - 1][y2];
    if (y1 - 1 >= 0) answer -= pre[x2][y1 - 1];
    dbg(answer);
    if (x1 - 1 >= 0 && y1 - 1 >= 0) answer += pre[x1 - 1][y1 - 1];
    cout << answer << "\n";
    dbg("DONE");
  }
  return 0;
}
