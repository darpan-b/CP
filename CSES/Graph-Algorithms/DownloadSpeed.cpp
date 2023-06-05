#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

const int N = 505;
const ll LINF = 1e18+5;
int n,m;
ll capacity[N][N];
vector<pair<int,ll>> adj[N];

ll bfs(vector<int>& parent){
    fill(parent.begin(),parent.end(),-1);
    parent[0] = -2;
    queue<pair<int,ll>> q;
    q.push({0,LINF});
    while(!q.empty()){
        int curnode = q.front().first;
        ll curflow = q.front().second;
        q.pop();
        for(auto u:adj[curnode]){
            if(parent[u.first] != -1 || capacity[curnode][u.first] == 0) continue;
            parent[u.first] = curnode;
            ll newflow = min(curflow,u.second);
            if(u.first == n-1) return newflow;
            q.push({u.first,newflow});
        }
    }
    return 0LL;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        capacity[u][v] += w;
    }
    ll total_flow = 0;
    vector<int> parent(n);
    ll newflow = 0;
    while(newflow = bfs(parent)){
        total_flow += newflow;
        int curnode = n-1;
        while(curnode != 0){
            int par = parent[curnode];
            capacity[curnode][par] += newflow;
            capacity[par][curnode] -= newflow;
            curnode = par;
        }
    }
    cout << total_flow << '\n';
    return 0;
}
