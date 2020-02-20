/**
 * @author Darpan Bhattacharya
 * Created on: 
 * Description:
 */ 

/*Template begins*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define mp make_pair
#define F first
#define S second

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
#define pb push_back

const ll MOD = 1e9+7;
const int INF = 1e9+9;
const ll LINF = 1e18+18;
const int MAXN = 2e5+5;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> 
using o_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define F0R(i,a) FOR(i,0,(a)-1)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)
#define R0F(i,a) ROF(i,(a),0)
#define trav(i,a) for(auto& i:a)

#define ins insert
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

ll fxp(ll x,ll y,ll p = MOD) {
    if(y == 0) return 1; if(y == 1) return (x % p);
    ll res = 1; res *= fxp(x,y/2,p); res %= p; res *= res; res %= p; if(y&1) res *= x; res %= p;
    return res;
}

template<class P,class Q>
ostream& operator << (ostream& out, pair<P,Q> p) {
    out << "(" << p.first << ", " << p.second << ")";
}
template<class T>
ostream& operator << (ostream& out, vector<T> x) { 
    out << "{"; bool f = true; 
    for(auto i:x) { if(f) out << i; else out << ", " << i; f = false; }
    out << "}\n";
}

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void fin(string s) { freopen(s.c_str(),"r",stdin); }
void fout(string s) { freopen(s.c_str(),"w",stdout); }
#ifdef LOCAL
#define fileio fin("inp.txt");
#else
#define fileio do{} while(false); 
#define cerr if(false) cerr
#endif
/*Template ends*/ 

void solve() {
} 

int32_t main() {
    fileio fastio
    int t = 1; // cin >> t; 
    while(t--) solve();
    return 0;
}
