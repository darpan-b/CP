#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> grid(n);
	for(auto& e:grid) cin >> e;
	const long long MOD = 1e9+7;
	vector<vector<long long>> dp(n,vector<long long>(n,0));
	dp[0][0] = (grid[0][0] == '.'? 1:0);
	auto isValid = [&](int x,int y)
	{
		return x >= 0 && y >= 0 && x < n && y < n;	
	};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(grid[i][j] == '*') continue;
			if(isValid(i-1,j))
			{
				dp[i][j] += dp[i-1][j];
				dp[i][j] %= MOD;
			}
			if(isValid(i,j-1))
			{
				dp[i][j] += dp[i][j-1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout << dp[n-1][n-1] << "\n";
	return 0;
}
