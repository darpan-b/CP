#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,W;
    cin >> N >> W;
    
    vector<ll> wt(N+1), val(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> wt[i] >> val[i];
    }

    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= W; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j-wt[i] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-wt[i]] + val[i]);
            }
        }
    }

    ll ans = 0;
    for(auto e:dp[N]) ans = max(ans,e);

    cout << ans << "\n";
    return 0;
}
