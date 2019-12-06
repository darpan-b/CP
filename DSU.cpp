// implementation of union-find algorithm (DSU)

int root[200005],rank[200005];
 
int findroot(int node){
	if(root[node] == node) return node;
	else return root[node] = findroot(root[node]);
}
 
bool union_(int u,int v){
	if(findroot(u) == findroot(v)) return false;
	u = findroot(u);
	v = findroot(v);
	if(rank[u] > rank[v]){
		root[v] = u;
		rank[u] += rank[v];
	}else{
		root[u] = v;
		rank[v] += rank[u];
	}
	return true;
}
