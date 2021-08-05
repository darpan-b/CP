#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    multiset<long long> bases;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(bases.empty() || *bases.rbegin() <= a[i]){
            bases.insert(a[i]);
            ++ans;
        } else{
            auto itr = bases.upper_bound(a[i]);
            bases.erase(itr);
            bases.insert(a[i]);
        }
    }
    cout << ans;
    return 0;
}
