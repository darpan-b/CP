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
int subtree_size[MAXN];

void dfs(int node,int par)
{
    subtree_size[node]=1;
    for(auto u:adj[node]){
        if(u==par){
            continue;
        }
        dfs(u,node);
        subtree_size[node]+=subtree_size[u];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        p--;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++){
        cout<<subtree_size[i]-1<<' ';
    }
    return 0;
}
