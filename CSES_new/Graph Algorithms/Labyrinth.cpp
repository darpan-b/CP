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
	std::vector<std::string> a(n);
	for(auto& i:a) std::cin >> i;
	std::priority_queue<std::pair<int, std::pair<int,int>>, std::vector<std::pair<int, std::pair<int,int>>>, std::greater<std::pair<int, std::pair<int,int>>>> q;
	std::pair<int,int> A,B;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] == 'A') A = {i,j};
			if(a[i][j] == 'B') B = {i,j};
		}
	}
	q.push({0,A});
	std::vector<int> xd = {1,-1,0,0};
	std::vector<int> yd = {0,0,-1,1};
	const int INF = (int)1e9;
	std::vector<std::vector<int>> dist(n, std::vector<int>(m,INF));
	std::vector<std::vector<std::pair<int,int>>> par(n, std::vector<std::pair<int,int>>(m,{-1,-1}));
	dist[A.first][A.second] = 0;
	auto isValid = [&](int x,int y)
	{
		return x >= 0 && x < n && y >= 0 && y < m;
	};
	while(!q.empty())
	{
		auto cur = q.top();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = cur.second.first+xd[i];
			int ny = cur.second.second+yd[i];
			if(isValid(nx,ny) && a[nx][ny] != '#' && dist[nx][ny] > cur.first+1)
			{
				dist[nx][ny] = cur.first+1;
				par[nx][ny] = cur.second;
				q.push({dist[nx][ny], {nx,ny}});
			}
		}
	}
	if(dist[B.first][B.second] == INF)
	{
		std::cout << "NO\n";
	}
	else
	{
		std::cout << "YES\n";
		std::cout << dist[B.first][B.second] << "\n";
		std::vector<char> ans;
		int cx = B.first, cy = B.second;
		while(par[cx][cy].first != -1)
		{
			if(par[cx][cy] == std::make_pair(cx-1,cy))
			{
				cx--;
				ans.push_back('D');
			}
			else if(par[cx][cy] == std::make_pair(cx+1,cy))
			{
				cx++;
				ans.push_back('U');
			}
			else if(par[cx][cy] == std::make_pair(cx,cy+1))
			{
				cy++;
				ans.push_back('L');
			}
			else
			{
				cy--;
				ans.push_back('R');
			}
		}
		std::reverse(ans.begin(), ans.end());
		for(auto i:ans) std::cout << i;
		std::cout << "\n";
	}
	return 0;
}
