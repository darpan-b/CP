template<typename T>
struct SegmentTree
{
	vector<T> seg;
	SegmentTree(){}
	SegmentTree(int n){ seg.assign(4*n,0LL); }
	void build(int node, int ss, int se, vector<T>& arr)
	{
		if(ss>se) return;
		if(ss == se) seg[node] = arr[ss];
		else
		{
			int mid = (ss+se)/2;
			build(node*2+1, ss, mid, arr);
			build(node*2+2, mid+1, se, arr);
			seg[node] = seg[node*2+1]+seg[node*2+2];
		}
	}
	void update(int node, int ss, int se, int uidx, T val)
	{
		if(ss>se || uidx>se || uidx<ss) return;
		if(ss>=uidx && se<=uidx) seg[node] = val;
		else
		{
			int mid = (ss+se)/2;
			update(node*2+1,ss,mid,uidx,val);
			update(node*2+2,mid+1,se,uidx,val);
			seg[node] = seg[node*2+1]+seg[node*2+2];
		}
	}
	T query(int node, int ss, int se, int qs, int qe)
	{
		if(ss>se || qs>se || qe<ss) return 0;
		if(ss>=qs && se<=qe) return seg[node];
		int mid = (ss+se)/2;
		T q1 = query(node*2+1,ss,mid,qs,qe);
		T q2 = query(node*2+2,mid+1,se,qs,qe);
		return q1+q2;
	}
};
