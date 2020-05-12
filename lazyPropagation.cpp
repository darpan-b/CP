// code for lazy propagation on a segment tree
// this is a part of the solution to the problem FLIPCOIN on codechef

int seg[4*MAXN] = {0};
bool lazy[4*MAXN] = {false};

void update(int node,int range_start,int range_end,int seg_start,int seg_end){
	if(lazy[node]){
		seg[node] = seg_end-seg_start+1-seg[node];
		lazy[node] = false;
		if(seg_start != seg_end){
			lazy[2*node+1] ^= 1;
			lazy[2*node+2] ^= 1;
		}
	}
	if(seg_start > range_end || seg_end < range_start)return;
	if(seg_start >= range_start && seg_end <= range_end){
		seg[node] = seg_end-seg_start+1-seg[node];
		if(seg_start != seg_end){
			lazy[2*node+1] ^= 1;
			lazy[2*node+2] ^= 1;
		}
	}else{
		int mid = seg_start+seg_end >> 1;
		update(node*2+1,range_start,range_end,seg_start,mid);
		update(node*2+2,range_start,range_end,mid+1,seg_end);
		seg[node] = seg[2*node+1]+seg[2*node+2];
	}
}

int query(int node,int range_start,int range_end,int seg_start,int seg_end){
	if(lazy[node]){
		seg[node] = seg_end-seg_start+1-seg[node];
		lazy[node] = false;
		if(seg_start != seg_end){
			lazy[2*node+1] ^= 1;
			lazy[2*node+2] ^= 1;
		}
	}
	if(seg_start > range_end || seg_end < range_start)return 0;
	if(seg_start >= range_start && seg_end <= range_end){
		return seg[node];
	}else{
		int mid = seg_start+seg_end >> 1;
		int left_q = query(node*2+1,range_start,range_end,seg_start,mid);
		int right_q = query(node*2+2,range_start,range_end,mid+1,seg_end);
		return left_q+right_q;
	}
}
