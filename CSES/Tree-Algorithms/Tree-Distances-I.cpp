#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif
const int MAXN = 2e5+5;
vector<int> adj[MAXN];
multiset<int> dist[MAXN];
int answer[MAXN];
void dfs(int node, int par)
{
    for(auto e: adj[node])
    {
        if(e == par) continue;
        dfs(e,node);
        dist[node].insert(*dist[e].rbegin()+1);
    }
    if(dist[node].empty()) dist[node].insert(0);
}
void dfs1(int node, int par)
{
    answer[node] = max(answer[node],*dist[node].rbegin());
    for(auto e: adj[node])
    {
        if(e == par) continue;
        // rerooting part
        auto itr = dist[node].end(); itr--;
        if(*itr == *dist[e].rbegin()+1)
        {
            if(itr != dist[node].begin())
            {
                itr--;
                dist[e].insert(*itr+1);
                dfs1(e,node);
                dist[e].erase(dist[e].find(*itr+1));
            }
            else
            {
                dist[e].insert(1);
                dfs1(e,node);
                dist[e].erase(dist[e].find(1));
            }
        }
        else
        {
            dist[e].insert(*itr+1);
            dfs1(e,node);
            dist[e].erase(dist[e].find(*itr+1));
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    dfs1(0,-1);
    for(int i=0; i<n; i++) cout << answer[i] << " ";
    cout << "\n";
    return 0;
}
