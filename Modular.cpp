// code to calculate x^y % p
ll fxp(ll x,ll y,ll p){	
	if(y == 0) return 1;
	if(y == 1) return (x%p);
	ll res = 1;
	res *= fxp(x,y/2,p); res %= p;
	res *= res; res %= p;
	if(y&1) res *= x; res %= p;
    return res;
}

// returns n^(-1) mod p
ll modinv(ll n,ll p){
	return fxp(n,p-2,p);
}

// nCr % p  
ll nCr(ll n,ll r,ll p) { 
    if(r == 0) return 1; 
    ll fact[n+1]; 
    fact[0] = 1; 
    for(ll i = 1; i <= n; i++) fact[i] = (fact[i-1]*i)%p; 
    return (fact[n]*modinv(fact[r],p)%p*modinv(fact[n-r],p)%p)%p; 
}

//  n!%p  
ll modFact(ll n,ll p){ 
    if(p <= n) return 0; 
    ll res = (p - 1); 
    for (ll i = n + 1; i < p; i++) res = (res*fxp(i,p))%p; 
    return res; 
} 
