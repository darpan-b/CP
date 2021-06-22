#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int n;
vector<int> adj[MAXN];
int subtree[MAXN];
long long ans[MAXN];
long long sum = 0;

void dfs(int node, int par, int dep) {
    sum += dep;
    subtree[node] = 1;
    for(int u : adj[node]) {
        if(u == par) continue;
        dfs(u,node,dep+1);
        subtree[node] += subtree[u];
    }
}

void dfs2(int node, int par, long long s) {
    ans[node] = s;
    for(int u:adj[node]) {
        if(u == par) continue;
        // s -= subtree[u];
        // s += n-subtree[u];
        // dbg(u,node,s,subtree[u]);
        // cout << u << " " << node << " " << s << " " << subtree[u] << endl;
        dfs2(u,node,s-2*subtree[u]+n);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1,0);
    dfs2(0,-1,sum);
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
}
