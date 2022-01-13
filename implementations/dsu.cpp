class DSU
{
public:
	vector<int> root, ranks;
	
	DSU() = default;
	
	DSU(int n)
	{
		root.assign(n + 1, 0);
		ranks.assign(n + 1, 0);
		iota(root.begin(), root.end(), 0);
	}
	
	int findRoot(int node)
	{
		if (root[node] == node)
			return node;
		else
			return root[node] = findRoot(root[node]);
	}

	bool unite(int u, int v)
	{
		u = findRoot(u);
		v = findRoot(v);
		if (u == v)
			return false;
		
		if (ranks[u] > ranks[v])
		{
			root[v] = u;
			ranks[u] += ranks[v];
		}
		else
		{
			root[u] = v;
			ranks[v] += ranks[u];
		}
		return true;
	}
};
