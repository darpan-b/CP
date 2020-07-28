struct SegTree {
	ll seg[4*MAXN];
	ll combine(ll a, ll b) {
		return a+b;
	}
 	void build(int node, int ss, int se, ll* a) {
		if(ss > se) return;
		if(ss == se) {
			seg[node] = a[ss]; return;
		}
		int mid = ss+se >> 1;
		build(node*2+1,ss,mid,a);
		build(node*2+2,mid+1,se,a);
		seg[node] = combine(seg[node*2+1],seg[node*2+2]);
 	}
 	void update(int node, int ss, int se, int idx, ll val) {
 		if(ss > se || idx > se || idx < ss) return;
 		if(ss == se && se == idx) {
 			seg[node] = val; return;
 		}
 		int mid = ss+se >> 1;
 		update(node*2+1,ss,mid,idx,val);
 		update(node*2+2,mid+1,se,idx,val);
 		seg[node] = combine(seg[node*2+1],seg[node*2+2]);
 	}
 	ll query(int node, int ss, int se, int qs, int qe) {
 		if(ss > se || qs > se || qe < ss) return 0;
 		if(ss >= qs && se <= qe) return seg[node];
 		int mid = ss+se >> 1;
 		ll q1 = query(node*2+1,ss,mid,qs,qe);
 		ll q2 = query(node*2+2,mid+1,se,qs,qe);
 		return q1+q2;
 	}
};
