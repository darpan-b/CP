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

    int N;
    cin >> N;
    vector<int> h(N);
    for(auto& e:h) cin >> e;

    vector<int> dp(N, 1e9);
    dp[0] = 0;
    for(int i = 1; i < N; i++){
        if(i-1 >= 0) dp[i] = min(dp[i], dp[i-1] + abs(h[i]-h[i-1]));
        if(i-2 >= 0) dp[i] = min(dp[i], dp[i-2] + abs(h[i]-h[i-2]));
    }

    cout << dp[N-1] << "\n";
    return 0;
}
