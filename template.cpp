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
using o_tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define F0R(i,a) FOR(i,0,(a)-1)
#define ROF(i,a,b) for(auto (i) = (a); (i >= (b); (i)--)
#define R0F(i,a) ROF(i,(a),0)
#define trav(i,a) for(auto& i:a)

#define ins insert
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define rall(x) x.begin(),x.rend()

ll fxp(ll x,ll y,ll p = MOD) {
    if(y == 0) return 1; if(y == 1) return (x % p);
    ll res = 1; res *= fxp(x,y/2,p); res %= p; res *= res; res %= p; if(y&1) res *= x; res %= p;
    return res;
}

template<class T> void re(complex<T>& x);
template<class T1, class T2> void re(pair<T1,T2>& p);
template<class T> void re(vector<T>& a);
template<class T> void re(T& x) { cin >> x; }
void re(double& x) { string t; re(t); x = stod(t); }
void re(ld& x) { string t; re(t); x = stold(t); }
template<class T, class... Ts> void re(T& t, Ts&... ts) { re(t); re(ts...); }
template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.first,p.second); }
template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
template<class T> void re(T a[],int start,int end) { FOR(i,start,end) re(a[i]); } 

void pr(int x) { cout << x; }
void pr(long x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(unsigned x) { cout << x; }
void pr(unsigned long x) { cout << x; }
void pr(unsigned long long x) { cout << x; }
void pr(float x) { cout << x; }
void pr(double x) { cout << x; }
void pr(ld x) { cout << x; }
void pr(char x) { cout << x; }
void pr(const char* x) { cout << x; }
void pr(const string& x) { cout << x; }
void pr(bool x) { pr(x ? "true" : "false"); }
template<class T> void pr(const complex<T>& x) { cout << x; }
template<class T1, class T2> void pr(const pair<T1,T2>& x);
template<class T> void pr(const T& x);
template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { pr(t); pr(ts...); }
template<class T1, class T2> void pr(const pair<T1,T2>& x) { pr("{",x.first,", ",x.second,"}"); }

template<class T> 
void pr(const vector<T>& x) { pr("{"); bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; pr("}"); }
template<class T> 
void pr(const set<T>& x) { pr("{"); bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; pr("}"); }
template<class T, class T1> 
void pr(map<T,T1> x) { pr("{"); bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",make_pair(a.first,a.second)), fst = 0; pr("}"); }
template<class T> 
void pr(stack<T> x) { pr("{"); bool fst = 1; while(!x.empty()) { pr(!fst?", ":"", x.top()); fst = 0; x.pop(); } pr("}"); }
template<class T> 
void pr(queue<T> x) { pr("{"); bool fst = 1; while(!x.empty()) { pr(!fst?", ":"", x.front()); fst = 0; x.pop(); } pr("}"); }
template<class T> 
void pr(priority_queue<T> x) { pr("{"); bool fst = 1; while(!x.empty()) { pr(!fst?", ":"", x.top()); fst = 0; x.pop(); } pr("}"); }
template<class T>
void pr(T a[],int start,int end) { pr("("); pr(a[start]); for(int i = start+1; i <= end; i++) pr(", ",a[i]); pr("}"); } 
template<class T>
void ps(T a[],int start,int end) { pr(a,start,end); pr("\n"); }

void ps() { pr("\n"); } 
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); }

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void fin(string s) { freopen(s.c_str(),"r",stdin); }
void fout(string s) { freopen(s.c_str(),"w",stdout); }
#ifdef LOCAL
#define fileio fin("inp.txt");
#else
#define fileio do{} while(false); 
#endif

/*Template ends*/ 

void solve() {
} 

int32_t main() {
    fileio fastio
    int t = 1; // re(t); 
    while(t--) solve();
    return 0;
}

/**
 * Author: DB
 * Date:
 * Contest name/Problem link:
 */
 
