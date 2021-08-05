#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<long long> sizes;
    set<long long> lights;
    long long x,n;
    cin >> x >> n;
    sizes.insert(x);
    while(n--){
        long long l;
        cin >> l;
        lights.insert(l);
        auto itr = lights.find(l);
        long long leftl,rightl;
        if(itr == lights.begin()){
            leftl = 0;
        }
        else{
            --itr;
            leftl = *itr;
            ++itr;
        }
        ++itr;
        if(itr == lights.end()){
            rightl = x;
        }
        else{
            rightl = *itr;
        }
        sizes.erase(sizes.find(rightl-leftl));
        sizes.insert(l-leftl);
        sizes.insert(rightl-l);
        cout << *sizes.rbegin() << '\n';
    }
    return 0;
}
