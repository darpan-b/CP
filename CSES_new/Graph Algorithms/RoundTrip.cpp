#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int par,int col, vector<vector<int>>& adj,vector<int>& parent, vector<int>& color) 
{
	color[node] = col;
	parent[node] = par;
	for(auto u:adj[node]) 
	{
		if(u == par) continue;
		if(color[u] == col) 
		{
			int curNode = node;
			vector<int> ans;
			while(true) 
			{
				ans.push_back(curNode);
				if(parent[curNode] == -1 || curNode == u) break;
				curNode = parent[curNode];
			}
			ans.push_back(node);
			cout << ans.size() << "\n";
			for(auto e:ans) cout << e+1 << " ";
			cout << "\n";
			exit(0);
		} 
		else 
		{
			dfs(u,node,col,adj,parent,color);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; i++) 
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> parent(n,-1),color(n,-1);
	int curColor = 1;
	for(int i = 0; i < n; i++) 
	{
		if(color[i] == -1) dfs(i,-1,curColor++,adj,parent,color);
	}
	cout << "IMPOSSIBLE\n";
}
