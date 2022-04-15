#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
	const int INF = (int)1e9;
	std::vector<int> dist(n,INF);
	std::vector<int> par(n, -1);
	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> q;
	dist[0] = 0;
	q.push({0,0});
	while(!q.empty())
	{
		auto cur = q.top();
		q.pop();
		for(auto i:adj[cur.second])
		{
			if(dist[i] > cur.first+1)
			{
				dist[i] = cur.first+1;
				par[i] = cur.second;
				q.push({dist[i],i});
			}
		}
	}
	if(dist[n-1] == INF)
	{
		std::cout << "IMPOSSIBLE\n";
	}
	else
	{
		std::vector<int> path;
		int cnode = n-1;
		while(par[cnode] != -1)
		{
			path.push_back(cnode);
			cnode = par[cnode];
		}
		path.push_back(0);
		std::cout << dist[n-1]+1 << "\n";
		std::reverse(path.begin(), path.end());
		for(auto i:path) std::cout << i+1 << " ";
		std::cout << "\n";
	}
	return 0;
}
