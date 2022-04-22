#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	std::vector<long long> dp(n+1,0);
	const long long MOD = 1e9+7;
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 6; j++)
		{
			if(i-j >= 0)
			{
				dp[i] += dp[i-j];
				dp[i] %= MOD;
			}
		}
	}
	std::cout << dp[n] << "\n";
	return 0;
}
