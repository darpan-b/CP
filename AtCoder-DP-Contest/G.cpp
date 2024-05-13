#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

const int MAXN = 1e5+5;
vector<int> adj[MAXN];
bool vis[MAXN];
int dp[MAXN]; // dp[i] = length of longest directed path ending at i

void dfs(int node) {
    vis[node] = true;
    for (auto u : adj[node]) {
        if (!vis[u]) dfs(u);
        dp[node] = max(dp[node], dp[u] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }
    cout << *max_element(dp, dp+n) << "\n";
    return 0;
}
