#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> idx(n+5,-1);
    for(int i = 0; i < n; i++) idx[a[i]] = i;
    vector<bool> sp(n+5,-1);
    sp[1] = true;
    for(int i = 2; i <= n; i++) sp[i] = idx[i] < idx[i-1];
    
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += sp[i];
    
    while(m--){
        int idx1,idx2;
        cin >> idx1 >> idx2;
        --idx1; --idx2;
        idx[a[idx1]] = idx2;
        idx[a[idx2]] = idx1;
        swap(a[idx1],a[idx2]);
        
        set<int> checked;
        auto check = [&](int num){
            if(num <= 1) return;
            if(checked.find(num) != checked.end()) return;
            if(idx[num] < idx[num-1]){
                if(sp[num]) return;
                sp[num] = true;
                ++ans;
            } else{
                if(!sp[num]) return;
                sp[num] = false;
                --ans;
            }
        };
        
        for(int i = -1; i <= 1; i++){
            check(a[idx1]+i);
            check(a[idx2]+i);
        }
        cout << ans << '\n';
    }
    return 0;
}
