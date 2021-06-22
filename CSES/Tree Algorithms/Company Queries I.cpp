#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
vector<int> adj[MAXN];
int boss[MAXN][30];

void dfs(int node, int par) {
    boss[node][0] = par;
    for(int i = 1; i < 30; i++) {
        if(boss[node][i-1] == -1) boss[node][i] = -1;
        else boss[node][i] = boss[boss[node][i-1]][i-1];
    }
    for(int u:adj[node]) {
        if(u == par) continue;
        dfs(u,node);
    }
}

int main() {
    int n,q; cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        --x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(0,-1);
    while(q--) {
        int node,level; cin >> node >> level;
        --node;
        int cur = node;
        for(int i = 0; i < 30; i++) {
            if(cur == -1) break;
            if(level&(1<<i)) {
                cur = boss[cur][i];
            }
        }
        cout << (cur == -1?-1:cur+1) << "\n";
    }
}
