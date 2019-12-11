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
