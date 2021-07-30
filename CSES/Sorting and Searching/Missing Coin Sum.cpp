#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>> n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    long long ans=1;
    sort(a.begin(),a.end());
    for(int i=0; i<n && a[i]<=ans; i++) ans+=a[i];
    cout << ans;
    return 0;
}
