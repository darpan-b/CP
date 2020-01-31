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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int> 
// Vectors
#define vi vector<int> 
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpil vector<pil>
#define vpli vector<pli>
#define vd vector<ld>
#define vvi vector<vi>
#define vvl vector<vl>
// For loops
#define FOR0(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR1(i,n) for(auto (i) = 1; (i) <= (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define DFOR(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)
#define TRAV(i,x) for(auto i:x)
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
// I/O
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void fin(string s){freopen(s.c_str(),"r",stdin);}
void fout(string s){freopen(s.c_str(),"w",stdout);}
#ifdef LOCAL
#define fileio fin("inp.txt");
#else
#define fileio 42;
#endif
/*Template ends*/ 

void solve(){
}

int32_t main(){
	fileio fastio
	int t = 1;
	//cin >> t;
	while(t--)solve();
	return 0;
}
