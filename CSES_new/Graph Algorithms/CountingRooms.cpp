#include <iostream>
#include <vector>

void dfs(int x,int y, int n, int m, std::vector<std::vector<bool>>& vis, std::vector<std::string>& a)
{
	auto isValid = [&](int cx,int cy)
	{
		return cx >= 0 && cx < n && cy >= 0 && cy < m;
	};
	vis[x][y] = true;
	std::vector<int> xd = {1,-1,0,0};
	std::vector<int> yd = {0,0,-1,1};
	for(int i = 0; i < 4; i++)
	{
		if(isValid(x+xd[i], y+yd[i]) && !vis[x+xd[i]][y+yd[i]] && a[x+xd[i]][y+yd[i]] == '.')
		{
			dfs(x+xd[i], y+yd[i], n,m,vis,a);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	for(auto& i:a) std::cin >> i;
	std::vector<std::vector<bool>> vis(n, std::vector<bool>(m,false));
	int color = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == '.' && !vis[i][j])
			{
				vis[i][j] = true;
				color++;
				dfs(i,j,n,m,vis,a);
			}
		}
	}
	std::cout << color << "\n";
	return 0;
}
