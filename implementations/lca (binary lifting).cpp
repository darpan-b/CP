const int MAXN = 2e5+5;
const int MAXLOG = 20;

vi adj[MAXN];

struct LCA {
	int anc[MAXN][MAXLOG];
	int dep[MAXN];

	void dfs(int node,int p) {
		anc[node][0] = p;
		if(p == node)dep[node] = 0;
		else dep[node] = dep[p]+1;
		FOR(i,1,MAXLOG-1) {
			anc[node][i] = anc[anc[node][i-1]][i-1];
		}
		for(auto u:adj[node]) {
			if(u == p) continue;
			dfs(u,node);
		}
	}
	int lca(int u,int v) {
		if(dep[u] < dep[v]) swap(u,v);
		ROF(i,MAXLOG-1,0) if(dep[anc[u][i]] >= dep[v]) u = anc[u][i];
		if(u == v) return u;
		ROF(i,MAXLOG-1,0) if(anc[u][i] != anc[v][i]) {
			u = anc[u][i]; v = anc[v][i];
		}
		return anc[u][0];
 	} 
 	int dist(int u,int v) {
 		return dep[u]+dep[v]-2*dep[lca(u,v)];
 	}
	void init(int root) {
		dfs(root,root);
	}
};
