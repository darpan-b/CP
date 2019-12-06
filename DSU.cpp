// implementation of union-find algorithm (DSU)
// union_(int u,int v) returns true iff nodes u & v are connected

int root[MAXN],ranks[MAXN];
 
int findroot(int node){
	if(root[node] == node) return node;
	else return root[node] = findroot(root[node]);
}
 
bool union_(int u,int v){
	if(findroot(u) == findroot(v)) return false;
	u = findroot(u);
	v = findroot(v);
	if(ranks[u] > ranks[v]){
		root[v] = u;
		ranks[u] += ranks[v];
	}else{
		root[u] = v;
		ranks[v] += ranks[u];
	}
	return true;
}
