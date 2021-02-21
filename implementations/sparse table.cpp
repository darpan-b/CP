struct Sparse {
	vector<vector<ll>> t;
	int n;
	void init(int _n, vector<ll>& a) {
		n = _n;
		t.assign(n,vector<ll>(21,(ll)1e18));
		for(int i = 0; i < n; i++) t[i][0] = a[i];
		for(int sz = 1; (1<<sz) <= n; sz++) {
			for(int i = 0; i+(1<<sz)-1 < n; i++) {
				t[i][sz] = min(t[i][sz-1],t[i+(1<<(sz-1))][sz-1]);
			}
		}
	}
	ll q(int s,int e) {
		if(e-s+1 <= 0) return (ll)1e15;
		int sz = log2(e-s+1);
		return min(t[s][sz],t[e-(1<<sz)+1][sz]);
	}
};
