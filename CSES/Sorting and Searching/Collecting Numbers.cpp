#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    vector<int> idx(n+5);
    for(int i=0; i<n; i++) idx[a[i]] = i;
    int ans=1;
    for(int i=2; i<=n; i++){
        if(idx[i]<idx[i-1]) ++ans;
    }
    cout << ans;
    
    return 0;
}
