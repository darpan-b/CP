#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    long long ans=a[0];
    long long sum=0;
    for(int i=0; i<n; i++){
        sum+=a[i];
        ans=max(ans,sum);
        sum=max(sum,0LL);
    }
    cout << ans;
    return 0;
}
