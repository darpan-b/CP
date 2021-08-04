#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n+5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int li = 0;
    map<long long,int> mp;
    int ans = 0, cur = 0;
    for(int i = 1; i <= n; i++){
        if(mp[a[i]] <= li){
            mp[a[i]] = i;
            ++cur;
        } else{
            li = mp[a[i]];
            cur = i-li;
            mp[a[i]] = i;
        }
        ans = max(ans,cur);
    }
    cout << ans;
    return 0;
}
