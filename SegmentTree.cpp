// segment tree for range update and point query
// this code finds sum of elements in a given change
// lazy propagation will be uploaded in a separate file

int seg[4*MAXN];

void build(int node,int start,int end,int a[]){
	if(start == end){
		seg[node] = a[start];
	}else{
		int mid = start+end>>1;
		build(node*2+1,start,mid,a);
		build(node*2+2,mid+1,end,a);
		seg[node] = seg[node*2+1]+seg[node*2+2];
	}
}

void update(int node,int start,int end,int idx,int val){
	if(idx < start || idx > end) return;
	if(start == end){
		seg[node] = val;
	}else{
		int mid = start+end>>1;
		update(node*2+1,start,mid,idx,val);
		update(node*2+2,mid+1,end,idx,val);
		seg[node] = seg[2*node+1]+seg[2*node+2];
	}
}

int query(int node,int start,int end,int qstart,int qend){
	if(start > qend || end < qstart) return 0;
	if(start >= qstart && end <= qend) return seg[node];
	int res = 0;
	int mid = start+end>>1;
	res += query(node*2+1,start,mid,qstart,qend);
	res += query(node*2+2,mid+1,end,qstart,qend); 
	return res;
}
