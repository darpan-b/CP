#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

vector<int> adj[MAXN];
int subtrsz[MAXN];

void dfs(int node, int par) {
    subtrsz[node] = 1;
    for(auto& e: adj[node]) {
        if(e == par) continue;
        dfs(e,node);
        subtrsz[node] += subtrsz[e];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        --x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(0,-1);
    for(int i = 0; i < n; i++) cout << subtrsz[i]-1 << " ";
    cout << "\n";
}
