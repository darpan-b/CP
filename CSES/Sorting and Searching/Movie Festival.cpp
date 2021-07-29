#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<pair<long long,int>> a;
    for(int i=0; i<n; i++) {
        long long x;
        cin >>x;
        a.push_back({x,i});
        cin>>x;
        a.push_back({-x,i});
    }
    
    sort(a.begin(),a.end(),[&](pair<long long,int> x,pair<long long,int> y){
        if(abs(x.first)<abs(y.first)) return true;
        else if(abs(x.first)==abs(y.first) && x.first<0 && y.first>0) return true;
        else return false;
    });
    
    vector<int> canwatch(n,0);
    int curmovies=1;
    for(int i=0; i<2*n; i++){
        if(a[i].first>0){
            canwatch[a[i].second]=curmovies;
        } else{
            curmovies=max(curmovies,canwatch[a[i].second]+1);
        }
    }
    
    cout<<*max_element(canwatch.begin(),canwatch.end()) << '\n';
    return 0;
}
