#define ll long long 

namespace Math {
	const ll mod = 1e9+7;
	const int SIZE = 1e6+5; 
	template <typename T> T gcd(T a, T b) { if(a > b) swap(a,b); return (a > 0 ? __gcd(a,b) : b); }
	template <typename T> T lcm(T a, T b) { return (a*b)/gcd(a,b); }
 
	ll add(ll a, ll b, ll p = mod) { ll res = a+b; if(res >= p) res -= p; return res; }
	ll sub(ll a, ll b, ll p = mod) { ll res = a-b; if(res < 0) res += p; return res; }
	ll mult(ll a, ll b, ll p = mod) { ll res = a*b; res %= p; return res; }
	ll fxp(ll a, ll b, ll p = mod) {
		if(b == 0) return 1;
		ll res = fxp(a,b/2,p); res %= p;
		res *= res; res %= p; if(b&1) res *= a; res %= p;
		return res;
	}
	template <typename T> T extendedEuclid(T a, T b, T& x, T& y) {
		if(b == 0) { x = 1; y = 0; return a; }
		ll x1, y1; ll g = extendedEuclid(b,a%b,x1,y1); x = y1; y = x1-y1*(a/b);
		return g;		
	}
	template <typename T> T modinv(T x, T p = mod) {
		T x1,y1,z = 0; T g = extendedEuclid(x,p,x1,y1); 
		return (g > 1 ? -1: sub(x1,z,p));
	}
	ll fact[SIZE],ifact[SIZE];
	void precompute(ll p = mod) {
		fact[0] = 1;
		for(int i = 1; i <= SIZE; i++) fact[i] = mult(fact[i-1],i,p);
		ifact[SIZE-1] = modinv(fact[SIZE-1],p);
		for(int i = SIZE-2; i >= 0; i--) ifact[i] = mult(ifact[i+1],i+1,p);
	}	
	ll nCr(ll n, ll r, ll p = mod) { return mult(mult(ifact[r],ifact[n-r],p),fact[n],p); }
} 
using namespace Math;
