#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    long long sum=0;
    for(int i=0; i<n; i++) sum+=a[i];
    long long ans=1e18;
    
    sort(a.begin(),a.end());
    vector<long long> pre(n),suf(n);
    pre[0]=a[0];
    for(int i=1; i<n; i++) pre[i]=pre[i-1]+a[i];
    suf[n-1]=a[n-1];
    for(int i=n-2; i>=0; i--) suf[i]=suf[i+1]+a[i];
    for(int i=0; i<n; i++){
        long long cur=0;
        int prev=i;
        if(prev>0) cur+=prev*a[i]-pre[i-1];
        int nxt=n-i-1;
        if(nxt>0) cur+=suf[i+1]-nxt*a[i];
        ans=min(ans,cur);
    }
    
    cout << ans;
    return 0;
}
