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

int main() {
    int n,q; cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        --x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(0,-1,0);
    while(q--) {
        int u,v; cin >> u >> v;
        --u; --v;
        cout << lca(u,v)+1 << "\n";
    }
}
