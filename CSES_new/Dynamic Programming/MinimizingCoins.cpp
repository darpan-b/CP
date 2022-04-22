#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n,x;
	std::cin >> n >> x;
	std::vector<long long> c(n);
	for(auto& coin:c) std::cin >> coin;
	const long long INF = 1e8;
	std::vector<long long> dp(x+1,INF);
	dp[0] = 0;
	for(int i = 1; i <= x; i++)
	{
		for(int j:c)
		{
			if(i-j >= 0)
			{
				dp[i] = std::min(dp[i],dp[i-j]+1);
			}
		}
	}
	std::cout << ((dp[x] == INF)?-1:dp[x]) << "\n";
	return 0;
}
