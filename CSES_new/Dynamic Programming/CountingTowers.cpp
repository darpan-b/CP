// https://www.youtube.com/watch?v=51AkVn5Urno
// excellent solution by stefdasca
// we need to compute the number of ways we can go from one state to another when:
// 1. last block was united and this block is also united -> 2 ways
// 2. last block was united and this block is not united -> 1 way
// 3. last block was not united and this block is united -> 1 way
// 4. both last block and this block are not united -> 4 ways
// from this information, compute the dp[i][0]=block united, dp[i][1]=block divided

#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
const long long MOD=1e9+7;
long long dp[MAXN][2];

void solve()
{
    int n;
    cin>>n;
    cout<<(dp[n][0]+dp[n][1])%MOD<<"\n";
}

int main()
{
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<MAXN;i++)
    {
        dp[i][0]+=dp[i-1][0]*2+dp[i-1][1];
        dp[i][1]+=dp[i-1][0]+dp[i-1][1]*4;
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    while(test--) solve();
    return 0;
}
