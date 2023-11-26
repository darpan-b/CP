#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dp[MAXN][2];

void dfs(int node, int par) {
	for(auto e: adj[node]) {
		if(e == par) {
			continue;
		}
		dfs(e, node);
		dp[node][1] += dp[e][0];
	}
	for(auto e: adj[node]) {
		if (e == par) {
			continue;
		}
		dp[node][0] = max(dp[node][0], dp[node][1] - dp[e][0] + dp[e][1]);
	}
	if(par != -1) {
		dp[node][1]++;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, -1);
	for(int i = 0; i < n; i++) {
		dbg(i + 1, dp[i][0], dp[i][1]);
	}
	printf("%d\n", max(dp[0][0], dp[0][1]));
	return 0;
}
