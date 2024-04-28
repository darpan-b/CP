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

    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    for(auto& e:h) cin >> e;

    vector<int> dp(N, 1e9);
    dp[0] = 0;
    for(int i = 1; i < N; i++){
        for(int j = i-1; j >= max(0,i-K); j--){
            dp[i] = min(dp[i], dp[j] + abs(h[j]-h[i]));
        }
    }

    cout << dp[N-1] << "\n";
    return 0;
}
