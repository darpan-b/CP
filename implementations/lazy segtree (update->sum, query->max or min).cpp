#define ll long long
 
const int MAXN = 2e5+5;
ll seg[4*MAXN], lazy[4*MAXN];
int n;
ll a[MAXN];

void build(int node, int ss, int se) {
	if(ss > se) return;
	if(ss == se) {
		seg[node] = a[i];
		return;
	}
	
	int mid = ss+se >> 1;
	build(node*2+1,ss,mid);
	build(node*2+2,mid+1,se);
	seg[node] = max(seg[node*2+1], seg[node*2+2]);
}
 
void push(int node, int ss, int se) {
	if(ss < se) {
		lazy[node*2+1] += lazy[node];
		lazy[node*2+2] += lazy[node];
		seg[node*2+1] += lazy[node];
		seg[node*2+2] += lazy[node];
	}
	lazy[node] = 0;
}
 
void update(int node, int ss, int se, int us, int ue, ll val) {
	if(ss > se || us > se || ue < ss) return;
	
	if(ss >= us && se <= ue) {
		seg[node] += val;
		lazy[node] += val;
		return;
	}
	
	push(node,ss,se);
	int mid = ss+se >> 1;
	update(node*2+1,ss,mid,us,ue,val);
	update(node*2+2,mid+1,se,us,ue,val);
	seg[node] = max(seg[2*node+1], seg[2*node+2]);
}
 
ll query(int node, int ss, int se, int qs, int qe) {
	if(ss > se || qs > se || qe < ss) return -1e18;
	push(node,ss,se);
	
	if(ss >= qs && se <= qe) {
		return seg[node];
	}
	
	push(node,ss,se);
	int mid = ss+se >> 1;
	ll q1 = query(node*2+1,ss,mid,qs,qe);
	ll q2 = query(node*2+2,mid+1,se,qs,qe);
	return max(q1, q2);
}
 
