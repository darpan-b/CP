// full c madness

#include <stdio.h>
#include <string.h>

int main(int argv, char** argc)
{
    int n,m;
    scanf("%d%d", &n,&m);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    const long long MOD = 1e9+7;
    long long dp[n][m+2];
    memset(dp,0,sizeof(dp));
    if(a[0] == 0)
    {
        for(int i = 1; i <= m; i++) dp[0][i] = 1;
    }
    else
    {
        dp[0][a[0]] = 1;
    }
    for(int i = 1; i < n; i++)
    {
        if(a[i] == 0)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
        else
        {
            dp[i][a[i]] = dp[i-1][a[i]];
            dp[i][a[i]] %= MOD;
            dp[i][a[i]] += dp[i-1][a[i]-1];
            dp[i][a[i]] %= MOD;
            dp[i][a[i]] += dp[i-1][a[i]+1];
            dp[i][a[i]] %= MOD;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= m; i++)
    {
        ans += dp[n-1][i];
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
