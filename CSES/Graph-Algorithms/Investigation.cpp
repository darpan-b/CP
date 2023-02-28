#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 5;
const int INF = 1e9 + 5;
const ll LINF = 1e18 + 5;
const ll MOD = 1e9 + 7;
vector<pair<int, ll>> adj[MAXN];
ll dist[MAXN], routes[MAXN];
int minroute[MAXN], maxroute[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        dist[i] = LINF;
        minroute[i] = INF;
        maxroute[i] = -INF;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
    }
    set<pair<ll, int>> s;
    s.insert({0, 0});
    dist[0] = 0;
    routes[0] = 1;
    minroute[0] = 0;
    maxroute[0] = 0;
    while(!s.empty()){
        auto topele = *s.begin();
        s.erase(s.begin());
        int node = topele.second;
        for(auto u : adj[node]){
            if(dist[u.first] > dist[node] + u.second){
                s.erase({dist[u.first], u.first});
                dist[u.first] = dist[node] + u.second;
                routes[u.first] = routes[node];
                minroute[u.first] = minroute[node] + 1;
                maxroute[u.first] = maxroute[node] + 1;
                s.insert({dist[u.first], u.first});
            }
            else if(dist[u.first] == dist[node] + u.second){
                routes[u.first] += routes[node];
                routes[u.first] %= MOD;
                minroute[u.first] = min(minroute[u.first], minroute[node] + 1);
                maxroute[u.first] = max(maxroute[u.first], maxroute[node] + 1);
                s.insert({dist[u.first], u.first});
            }
        }
    }
    cout << dist[n - 1] << " " << routes[n - 1] << " " << minroute[n - 1] << " " << maxroute[n - 1] << "\n";
    return 0;
}
