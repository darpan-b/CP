/*
 * Segment Tree with point update and range query
 */
template<typename T>
class SegmentTree
{
public:
	vector<T> seg;
	SegmentTree()
	{
		seg.clear();
	}
	SegmentTree(int _n)
	{
		seg.assign(4*_n,0);
	}
	/*
	 * modify this function according to the problem
	 */
	T combine(T a,T b)
	{
		return a+b;
	}
	void build(int node,int ss,int se,vector<T>& a)
	{
		if(ss>se) return;
		if(ss==se){
			seg[node]=a[ss];
		}else{
			int mid=(ss+se)/2;
			build(node*2+1,ss,mid,a);
			build(node*2+2,mid+1,se,a);
			seg[node]=combine(seg[node*2+1],seg[node*2+2]);
		}
	}
	void update(int node,int ss,int se,int idx,T val)
	{
		if(ss>se || idx>se || idx<ss) return;
		if(ss==se && ss==idx){
			seg[node]=val;
		}else{
			int mid=(ss+se)/2;
			update(node*2+1,ss,mid,idx,val);
			update(node*2+2,mid+1,se,idx,val);
			seg[node]=combine(seg[node*2+1],seg[node*2+2]);
		}
	}
	T query(int node,int ss,int se,int qs,int qe)
	{
		if(ss>se || qs>se || qe<ss) return 0;
		if(ss>=qs && se<=qe) return seg[node];
		int mid=(ss+se)/2;
		T q1=query(node*2+1,ss,mid,qs,qe);
		T q2=query(node*2+2,mid+1,se,qs,qe);
		return combine(q1,q2);
	}
};
