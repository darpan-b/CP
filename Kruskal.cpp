// kruskal's algorithm to find minimum spanning tree in a graph
// kruskal() returns the total edge cost of the mst
// this algorithm works by considering all possible edges and then selecting the edges with minimum cost

int root[MAXN],sz[MAXN],cost[MAXN][MAXN];
 
int findroot(int node){
	if(root[node] == node){
		return node;
	}else{
		return root[node] = findroot(root[node]);
	}
}
 
bool union_(int u,int v){
	if(findroot(u) == findroot(v)) return false;
	u = findroot(u);
	v = findroot(v);
	if(sz[u] > sz[v]){
		sz[u] += sz[v];
		root[v] = u;
	}else{
		sz[v] += sz[u];
		root[u] = v;
	}
	return true;
}

int kruskal(){
	vector<pair<int,pair<int,int>>> edges;	// {cost,{node1,node2}}
	for(int i = 0; i < m; i++){
    for(int j = 0; j < i; j++){
      edges.push_back({cost[i][j],{j,i}});
    }
  }
	sort(edges.begin(),edges.end());
	int tot = 0;
	for(auto edge:edges){
		bool willunite = union_(edge.ss.ff,edge.ss.ss);
		if(willunite){
			tot += edge.ff;
		}
	}
  return tot;
}
