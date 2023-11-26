#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int subtree_size[MAXN];

void dfs(int node, int par) {
	subtree_size[node] = 1;
	for(auto e: adj[node]) {
		if(e == par) {
			continue;
		}
		dfs(e, node);
		subtree_size[node] += subtree_size[e];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int p;
		scanf("%d", &p);
		p--;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	dfs(0, -1);
	for(int i = 0; i < n; i++) {
		printf("%d ", subtree_size[i] - 1);
	}
	return 0;
}
