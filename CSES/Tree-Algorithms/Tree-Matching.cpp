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
int dp[MAXN][2];

void dfs(int node, int par)
{
    for(auto u:adj[node])
    {
        if(u==par) continue;
        dfs(u, node);
        dp[node][1]=max(dp[node][0]+dp[u][0]+1, dp[node][1]+max(dp[u][0], dp[u][1]));
        dp[node][0]+=max(dp[u][0], dp[u][1]);
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
    dfs(0, -1);
    cout<<max(dp[0][0], dp[0][1])<<'\n';
    return 0;
}
