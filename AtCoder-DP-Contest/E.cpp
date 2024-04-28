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

    ll V = 0;
    for(auto e:val) V += e;

    vector<vector<ll>> dp(N+1, vector<ll>(V+1, 1e18));
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= V; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(dp[i-1][j]+wt[i] <= W && j+val[i] <= V){
                dp[i][j+val[i]] = min(dp[i][j+val[i]], dp[i-1][j]+wt[i]);
            }
        }
    }

    ll ans = 0;
    for(int i = V; i >= 0; i--){
        if(dp[N][i] <= W){
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}
