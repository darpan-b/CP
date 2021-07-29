#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    long long x;
    cin>> n >> x;
    vector<pair<long long,int>> a(n);
    for(int i=0; i<n; i++) cin>>a[i].first, a[i].second=i;
    sort(a.begin(),a.end());
    for(int i=0; i<n; i++){
        long long req=x-a[i].first;
        int lo=0, hi=n-1, mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(a[mid].first>req) hi=mid-1;
            else if(a[mid].first<req) lo=mid+1;
            else{
                if(2*req==x) {
                    if(a[mid].second==a[i].second){
                        if(mid+1< n && a[mid+1].first==req) {
                            cout << a[i].second+1 << ' ' << a[mid+1].second+1 << '\n';
                            return 0;
                        }else if(mid-1>=0 && a[mid-1].first==req) {
                            cout << a[i].second+1 << ' ' << a[mid-1].second+1 << '\n';
                        } else {
                            cout << "IMPOSSIBLE\n";
                        }
                    }else{
                        cout << a[i].second+1 << ' ' << a[mid].second+1 << '\n';
                    }
                }else{
                    cout << a[i].second+1 << ' ' << a[mid].second+1 << '\n';
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
