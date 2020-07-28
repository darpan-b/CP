struct BIT {
	int n;
	ll bit[MAXN]; // 1-indexed, so add 1 to parameters before calling
	void update(int idx, ll val) {
		// val will be ADDED to idx, not changed to what the value at idx was
		while(idx <= n) {
			bit[idx] += val; idx += (idx&-idx);
		}
	}
	ll query(int idx) {
		ll res = 0;
		while(idx > 0) {
			res += bit[idx]; idx -= (idx&-idx);
		}
		return res;
	}
	ll query(int u, int v) {
		return query(v)-query(u-1);
	}
};
