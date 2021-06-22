#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
vector<int> adj[MAXN];
int depth[MAXN];
int anc[MAXN][25];

void dfs(int node, int par, int dep) {
    depth[node] = dep;
    anc[node][0] = par;
    for(int i = 1; i < 20; i++) {
        if(anc[node][i-1] == -1) anc[node][i] = -1;
        else anc[node][i] = anc[anc[node][i-1]][i-1];
    }
    for(int u:adj[node]) {
        if(u == par) continue;
        dfs(u,node,dep+1);
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u,v);
    for(int i = 19; i >= 0; i--) {
        if(depth[u]-(1<<i) >= depth[v]) {
            u = anc[u][i];
        }
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if(anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

int dist(int u, int v) {
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}

int main() {
    int n,q; cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int u,v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1,0);
    while(q--) {
        int u,v; cin >> u >> v;
        --u; --v;
        cout << dist(u,v) << "\n";
    }
}
