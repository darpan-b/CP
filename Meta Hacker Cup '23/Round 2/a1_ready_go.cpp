#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

const int MAXN = 3005;
int n, m;
string grid[MAXN];
int colour[MAXN][MAXN];
int curcolour;
set<pair<int, int>> emptycolour[MAXN];

const int INF = 1e8 + 5;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

inline bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int c) {
	colour[x][y] = c;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && grid[nx][ny] == 'W' && colour[nx][ny] == -1) {
			dfs(nx, ny, c);
		}
	}
}

void solve(int testcase) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		grid[i].clear();
		emptycolour[i].clear();
		for (int j = 0; j < m; j++) colour[i][j] = -1;
	}
	curcolour = 0;

	for (int i = 0; i < n; i++) cin >> grid[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'W' && colour[i][j] == -1) {
				dfs(i, j, curcolour);
				curcolour++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'W') {
				assert(colour[i][j] != -1);
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (valid(nx, ny) && grid[nx][ny] == '.') {
						emptycolour[colour[i][j]].insert({nx, ny});
					}
				}
			}
		}
	}
	int mingap = INF;
	for (int i = 0; i < curcolour; i++) mingap = min(mingap, (int)emptycolour[i].size());
	
	cout << "Case #" << testcase << ": ";
	if (mingap <= 1) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	freopen("ready_go_part_1_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++) solve(i);
	return 0;
}
