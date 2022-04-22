#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n,x;
	std::cin >> n >> x;
	std::vector<int> c(n);
	for(auto& i:c) std::cin >> i;
	const long long MOD = 1e9+7;
	std::vector<int> dp(x+1,0);
	dp[0] = 1;
	for(int i:c)
	{
		for(int j = 1; j <= x; j++)
		{
			if(j-i >= 0) dp[j] += dp[j-i];
			dp[j] %= MOD;
		}
	}
	std::cout << dp[x] << "\n";
	return 0;
}
