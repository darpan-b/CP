#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int node, int p, int d) {
	dist[node] = d;
	for(auto e: adj[node]) {
		if(e == p) {
			continue;
		}
		dfs(e, node, d + 1);
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
	dfs(0, -1, 0);
	int root = 0;
	for(int i = 0; i < n; i++) {
		if(dist[i] > dist[root]) {
			root = i;
		}
	}
	dfs(root, -1, 0);
	printf("%d\n", *max_element(dist, dist + n));
	return 0;
}
