#include <bits/stdc++.h>

#ifdef LOCAL

#include "/home/winxtron/CLionProjects/cp_clion/debugger.h"

#define dbg(...) cerr << "LINE(" << __LINE__<< ") -> [" << #__VA_ARGS__<< "]: [", debug(__VA_ARGS__)
#else
#define dbg(...) 5
#endif

using namespace std;

int main() {
    /*
     * f(x)={f(x-1), f(x-2), ... f(x-6)} + 1
     */
    int n;
    cin >> n;
    const long long mod=1e9+7;
    vector<long long> dp(n+10,0);
    for(int i=1;i<=6;i++) dp[i]=1;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=6;j++) {
            if(i-j>=1) dp[i] += dp[i-j];
            dp[i]%=mod;
        }
    }
    cout << dp[n];
    return 0;
}
