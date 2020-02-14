/*Template begins*/
// Headers
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// Namespaces
using namespace std;
using namespace __gnu_pbds;
// Typenames
#define ll long long 
#define ld long double
// Pairs
#define pi pair<int,int> 
#define pl pair<ll,ll>
#define pd pair<ld,ld>
// Vectors
#define vi vector<int> 
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define vpd vector<pd>
#define vd vector<ld>
#define vvi vector<vi>
// For loops
#define re(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define rep(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define per(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)
#define trav(i,x) for(auto i:x)
// PBDS
template<class T> 
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// Constants
const int MOD = 1e9+7;
const int MAXN = 1e5+5;
const int INF = (1<<28);
const ll LINF = (1ULL<<56);
// Miscellaneous
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
// I/O
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void fin(string s){freopen(s.c_str(),"r",stdin);}
void fout(string s){freopen(s.c_str(),"w",stdout);}
#ifdef LOCAL
#define fileio fin("inp.txt");
#else
#define fileio 17;
#endif
/*Template ends*/ 

void solve() { 
}

int32_t main() {
    fileio fastio
    int t = 1;
    //cin >> t; 
    while(t--) solve();
    return 0;
}
