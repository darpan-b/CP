#include <bits/stdc++.h>
#define mp make_pair
#define rep(i, n) for (int i = 0; i < (int) n; i ++)
#define fr(i, a, b) for (int i = (int) a; i <= (int) b; i ++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

void dfs(int r, int c, int col, const vector<string> &a, vector<vector<int>> &color)
{
	color[r][c] = col;
	if (r - 1 >= 0 && a[r - 1][c] == '.' && color[r - 1][c] == 0) dfs(r - 1, c, col, a, color);
	if (c - 1 >= 0 && a[r][c - 1] == '.' && color[r][c - 1] == 0) dfs(r, c - 1, col, a, color);
	if (r + 1 < (int) a.size() && a[r + 1][c] == '.' && color[r + 1][c] == 0) dfs(r + 1, c, col, a, color);
	if (c + 1 < (int) a[r].size() && a[r][c + 1] == '.' && color[r][c + 1] == 0) dfs(r, c + 1, col, a, color);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &e : a) cin >> e;
	vector<vector<int>> color(n, vector<int>(m, 0));
	int curcolor = 1;
	rep(i, n) rep(j, m) if (a[i][j] == '.' && color[i][j] == 0) dfs(i, j, curcolor ++, a, color);
	cout << curcolor - 1 << "\n";
	return 0;
}
 
