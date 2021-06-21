#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

vector<int> adj[MAXN];
int depth[MAXN];

void dfs(int node, int par, int dep, int& extreme) {
    depth[node] = dep;
    if(depth[node] > depth[extreme]) extreme = node;
    for(auto& e:adj[node]) {
        if(e == par) continue;
        dfs(e,node,dep+1,extreme);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int extreme = 0;
    dfs(0,-1,0,extreme);
    dfs(extreme,-1,0,extreme);
    cout << depth[extreme];
}
