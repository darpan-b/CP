const int MAXN = 2e5+5;

struct DSU {
	int root[MAXN],ranks[MAXN];
	void init() {
		F0R(i,MAXN) {
			root[i] = i; ranks[i] = 1;
		}
	}
	int getRoot(int node) {
		if(root[node] == node) return node;
		else return root[node] = getRoot(root[node]);
	}
	bool sameComp(int u,int v) {
		u = getRoot(u); v = getRoot(v);
		return (u == v);
	}
	bool unite(int u,int v) {
		u = getRoot(u); v = getRoot(v);
		if(u == v) return false;
		if(ranks[u] > ranks[v]) {
			ranks[u] += ranks[v]; root[v] = u;
		} else {
			ranks[v] += ranks[u]; root[u] = v;
		}
		return true;
	}
};
