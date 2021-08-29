/*
 * Fenwick tree / Binary indexed tree
 * range query, point update, combine function: addition
 */
template<typename T>
struct FenwickTree
{
	int n;
	vector<T> fenwick;
	FenwickTree()
	{
		fenwick.clear();
	}
	FenwickTree(int _n)
	{
		n=_n;
		fenwick.assign(n+1,0);
	}
	void build(vector<T>& a)
	{
		for(int i=1;i<=n;i++){
			fenwick[i]+=a[i-1];
			if(i+(i&-i)<=n) fenwick[i+(i&-i)]+=fenwick[i];
		}
	}
	/*
	 * take note that it DOES NOT change idx to val
	 * it ADDS val to element at index idx
	 */
	void update(int idx,T val)
	{
		for(int i=idx+1;i<=n;i+=(i&-i)) fenwick[idx]+=val;
	}
	T query(int idx)
	{
		T res=0;
		for(int i=idx+1;i>=1;i-=(i&-1)) res+=fenwick[i];
		return res;
	}
	T query(int l,int r)
	{
		return query(r)-query(l-1);
	}
};
