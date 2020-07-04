// bellman ford algorithm to find single source shortest path in a graph
// the graph is assumed to be directed and is stored in the form of a vector of edges
// complexity: O(|V|*|E|) 

ll dist[MAXN];

void check_neg_cycle(vector<pair<ll,pair<int,int>>> edges){
	for(auto edge: edges){
		if(dist[edge.second.second] > dist[edge.second.first]+edge.first){
			cout << "Negative cycle detected!";
			return;
		} 
	}
}

void bellman_ford(int src,int n, vector<pair<ll,pair<int,int>>> edges){
	for(int i = 0; i < n; i++) dist[i] = INF;
	dist[src] = 0;
	for(int i = 0; i < n-1; i++){
		for(auto edge:edges){
			int start = edge.second.first;
			int end = edge.second.second;
			ll wt = edge.first;
			if(dist[end] > dist[start]+wt){
				dist[end] = dist[start]+wt;
			}
		}
	}
	check_neg_cycle(edges);
}
