#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int depth[MAXN];
int dist1[MAXN], dist2[MAXN];

void dfs(int node, int par, int dep, int& extreme_node) {
    depth[node] = dep;
    if (depth[node] > depth[extreme_node]) {
        extreme_node = node;
    }
    
    for (int u : adj[node]) {
        if (u == par)
            continue;
        dfs(u, node, dep + 1, extreme_node);
    }
}

void dfs1(int node, int par, int distance) {
    dist1[node] = distance;
    
    for (int u : adj[node]) {
        if (u == par)
            continue;
        dfs1(u, node, distance + 1);
    }
}

void dfs2(int node, int par, int distance) {
    dist2[node] = distance;
    
    for (int u : adj[node]) {
        if (u == par)
            continue;
        dfs2(u, node, distance + 1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int extreme_node = 0;
    dfs(0, -1, 0, extreme_node);
    int extreme_node2 = 0;
    dfs(extreme_node, -1, 0, extreme_node2);
    dfs1(extreme_node, -1, 0);
    dfs2(extreme_node2, -1, 0);
    
    for (int i = 0; i < n; i++)
        cout << max(dist1[i], dist2[i]) << " ";
}
