#include <iostream>
#include <vector>
#include <queue>

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
	std::vector<int> color(n,0);
	std::queue<int> bfs;
	for(int i = 0; i < n; i++)
	{
		if(color[i] == 0)
		{
			color[i] = 1;
			bfs.push(i);
			while(!bfs.empty())
			{
				int node = bfs.front();
				bfs.pop();
				for(auto j:adj[node])
				{
					if(color[j] == color[node])
					{
						std::cout << "IMPOSSIBLE\n";
						return 0;
					}
					if(color[j] == 0)
					{
						if(color[node] == 1) color[j] = 2;
						else color[j] = 1;
						bfs.push(j);
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
		std::cout << color[i] << " ";
	std::cout << "\n";
	return 0;
}
