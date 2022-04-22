#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	const long long INF = 1e9;
	std::vector<int> dp(n+1,INF);
	dp[n] = 0;
	for(int i = n; i > 0; i--)
	{
		auto obtainDigits = [&](int num)
		{
			std::vector<int> res;
			while(num > 0)
			{
				res.push_back(num%10);
				num /= 10;
			}
			return res;
		};
		auto dig = obtainDigits(i);
		for(auto j:dig)
		{
			if(i-j >= 0)
			{
				dp[i-j] = std::min(dp[i-j],dp[i]+1);
			}
		}
	}
	std::cout << dp[0] << "\n";
	return 0;
}
