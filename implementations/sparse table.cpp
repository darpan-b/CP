// sparse table is used for range queries on static arrays in O(1) time
// build() takes O(nlogn) time
// this table computes range min queries
// sparse[i][j] contains min in range [i, i+2^j-1]

ll sparse[MX][30];

void build(ll a[],int n){
	for(int i = 0; i < n; i++){
		sparse[i][0] = a[i];
	}
	for(int sz = 1; (1<<sz) <= n; sz++){
		for(int i = 0; i+(1<<sz)-1 < n; i++){
			sparse[i][sz] = min(sparse[i][sz-1],sparse[i+(1<<(sz-1))][sz-1]);
		}
	}
}

ll query(int start,int end){
	int sz = log2(end-start+1);
	return min(sparse[start][sz],sparse[end-(1<<sz)+1][sz]);
}
