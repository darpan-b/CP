#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif
const int MAXN = 2e5+5;
int n;
vector<int> adj[MAXN];
long long sum[MAXN], answer[MAXN];
long long ss[MAXN];
void dfs_pre(int node, int par)
{
    ss[node] = 1;
    for(auto e: adj[node])
    {
        if(e == par) continue;
        dfs_pre(e,node);
        ss[node] += ss[e];
    }
}
void dfs(int node, int par)
{
    for(auto e: adj[node])
    {
        if(e == par) continue;
        dfs(e,node);
        sum[node] += sum[e]+ss[e];
    }
}
void dfs1(int node, int par)
{
    answer[node] = sum[node];
    for(auto e: adj[node])
    {
        if(e == par) continue;
        long long extra = sum[node]-ss[e]-sum[e];
        dbg(node+1, e+1, extra, sum[node]);
        sum[e] += extra+n-ss[e];
        dfs1(e,node);
        sum[e] -= extra+n-ss[e];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_pre(0,-1);
    dfs(0,-1);
    for(int i=0; i<n; i++) dbg(i+1, sum[i]);
    dfs1(0,-1);
    for(int i=0; i<n; i++) cout << answer[i] << " ";
    cout << "\n";
    return 0;
}
