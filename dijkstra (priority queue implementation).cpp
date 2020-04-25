#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x) memset(x,a,sizeof(x))
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

/*
	Description: Implementation of the dijkstra algorithm 
	Source: Own
	Verification:
		:: Problem: https://codeforces.com/contest/20/problem/C
		:: Solution: https://codeforces.com/contest/20/submission/76665758
	Tips: 
		:: edge weights must not be -ve
		:: look out for the max possible edge weight
	Complexity: O(V + E logV)
	Date: 25 April 2020
*/


const int MX = 1e5+5;
int n,m; // n = number of nodes, m = number of edges
vector<pair<int,ll>> adj[MX]; // adjacency list of the graph {node, distance}
ll dist[MX]; // stores the distance of the node from the source node

void dijkstra(int src) {
	// min priority queue which stores nodes in the order {distance, node}
	priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

	// initializing distance to inf
	F0R(i,MX) dist[i] = 1e18+5;

	pq.push({0,src});
	dist[src] = 0;
	
	while(!pq.empty()) {
		int node = pq.top().S;
		pq.pop();

		// updates all the paths passing through node
		for(auto& u:adj[node]) {
			// if the current distance of u is greater than 
			// the distance of node from the source + the edge weight, then update it
			if(dist[u.F] > dist[node]+u.S) {
				dist[u.F] = dist[node]+u.S;
				pq.push(mp(dist[u.F],u.F));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	F0R(i,m) {
		int u,v; ll w; 
		cin >> u >> v >> w;
		u--; v--;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}
	
	dijkstra(0);	
	// if there exists no path from the source vertex to destination, 
	// the dist[] will contain inf (1e18+5 here). 
}	
