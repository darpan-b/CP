#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

void dfs(int node,int col,std::vector<std::vector<int>>& adj, std::vector<bool>& vis, std::vector<int>& color)
{
	vis[node] = true;
	color[node] = col;
	for(auto i:adj[node])
	{
		if(vis[i]) continue;
		dfs(i,col,adj,vis,color);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n,m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> adj(n);
	for(int i = 0; i < m; i++)
	{
		int u,v;
		std::cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::vector<bool> vis(n,false);
	std::vector<int> color(n,0);
	int c = 1;
	for(int i = 0; i < n; i++)
	{
		if(!vis[i]) dfs(i,c++,adj,vis,color);
	}
	std::vector<int> vertices(n);
	std::iota(vertices.begin(),vertices.end(),0);
	std::sort(vertices.begin(),vertices.end(), [&](int u,int v)
	{
		return color[u] < color[v];
	});
	std::vector<int> req;
	for(int i = 0; i < n-1; i++)
	{
		if(color[vertices[i]] != color[vertices[i+1]])
			req.push_back(vertices[i]);
	}
	req.push_back(vertices.back());
	dbg(vertices,req);
	std::cout << req.size()-1 << "\n";
	for(int i = 0; i < (int)req.size()-1; i++)
		std::cout << req[i]+1 << " " << req[i+1]+1 << "\n";
	return 0;
}
