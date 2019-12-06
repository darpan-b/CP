// dijkstra algorithm to find shortest path from node start to node end
// shortest path ans is dist[end]

int n;
ll dist[MAXN];

void dijkstra(int start,int end){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({start,0});
	dist[start] = 0;
	for(int i = 0; i < n; i++) if(i != start) dist[i] = LINF;  
	while(!pq.empty()){
		int node = pq.top().second;
		pq.pop();
		for(auto i:g[node]){
			if(dist[i.first] > dist[node]+i.second){
				dist[i.first] = dist[node]+i.second;
				pq.push({dist[i.first],i.first});
			}
		}
	}
}
