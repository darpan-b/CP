#include <bits/stdc++.h>
using namespace std;
#pragma GCC "-O3,-Ofast"

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,long long>>> adj(n);
	for(int i = 0; i < m; i++){
		int u,v;
		long long w;
		cin >> u >> v >> w;
		u--; v--;
		adj[u].push_back({v,w});
	}
	const long long INF = 1e18;
	vector<vector<long long>> dist(n,vector<long long>(2,INF));
	dist[0][0] = 0;
	priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<>> pq;
	pq.push({0,{0,0}});
	while(!pq.empty()){
		int node = pq.top().second.first;
		int halved = pq.top().second.second;
		if(dist[node][halved] < pq.top().first){
			pq.pop();
			continue;
		}
		pq.pop();
		for(auto &u: adj[node]){
			int neigh = u.first;
			long long edw = u.second;
			if(halved == 1){
				if(dist[neigh][1] > dist[node][halved]+edw){
					dist[neigh][1] = dist[node][halved]+edw;
					pq.push({dist[neigh][1],{neigh,1}});
				}
			}else{
				if(dist[neigh][0] > dist[node][halved]+edw){
					dist[neigh][0] = dist[node][halved]+edw;
					pq.push({dist[neigh][0],{neigh,0}});
				}
				if(dist[neigh][1] > dist[node][halved]+(edw/2)){
					dist[neigh][1] = dist[node][halved]+(edw/2);
					pq.push({dist[neigh][1],{neigh,1}});
				}
			}
		}
	}
	cout << min(dist[n-1][0],dist[n-1][1]) << "\n";
	return 0;
}
