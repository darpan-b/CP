#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

const int MAXN=2e5+5;
vector<int> adj[MAXN];
int dist[MAXN];

void dfs(int node, int par, int d)
{
    dist[node]=d;
    for(auto u:adj[node])
    {
        if(u==par) continue;
        dfs(u, node, d+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0);
    int root=0;
    for(int i=0; i<n; i++)
    {
        if(dist[i]>dist[root]) root=i;
    }
    dfs(root, -1, 0);
    int ans=0;
    for(int i=0; i<n; i++) ans=max(ans, dist[i]);
    cout<<ans<<"\n";
    return 0;
}
