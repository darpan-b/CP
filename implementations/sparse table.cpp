/*
 * Sparse table for range max/min queries in O(1)
 * O(N log N) building time
 */
template<typename T>
struct SparseTable
{
	int n;
	int log_n;
	vector<vector<T>> sparse;
	SparseTable()
	{
		n=0;
		sparse.clear();
	}
	SparseTable(int _n)
	{
		n=_n;
		log_n=__lg(n)+2;
		sparse.assign(n,vector<T>(log_n,0));
	}
	/*
	 * modify the combine function to max or min as required
	 */
	T combine(T a,T b)
	{
		return max(a,b);
	}
	void build(vector<T>& a,int _n)
	{
		n=_n;
		log_n=__lg(n)+2;
		sparse.assign(n,vector<T>(log_n,0));
		for(int i=0;i<n;i++) sparse[i][0]=a[i];
		for(int i=1;i<log_n;i++){
			for(int j=0;j<n;j++){
				if(j+(1<<(i-1))>=n) continue;
				sparse[j][i]=combine(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
			}
		}
	}
	T query(int l,int r)
	{
		if(r-l<0) return 0;
		int log_sz=__lg(r-l+1);
		return combine(sparse[l][log_sz],sparse[r-(1<<log_sz)+1][log_sz]);
	}
};
