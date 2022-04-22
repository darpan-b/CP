#include <stdio.h>
#include <string.h>

int main()
{
	int n,x;
	scanf("%d%d", &n,&x);
	long long c[n];
	for(int i = 0; i < n; i++) scanf("%lld",&c[i]);
	const long long MOD = 1e9+7;
	long long dp[x+1];
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= x; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i-c[j] >= 0)
			{
				dp[i] += dp[i-c[j]];
				dp[i] %= MOD;
			}
		}
	}
	printf("%lld\n",dp[x]);
	return 0;
}
