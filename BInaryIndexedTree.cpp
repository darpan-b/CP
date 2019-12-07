// implementation of BIT (also called Fenwick tree) to find sum of a given range
// array is assumed to be 1-indexed
// fenwick[] is 1-indexed
// int may be changed to long long if required

int fenwick[MAXN],n;

void update(int idx,int val){
	while(idx <= n){
		fenwick[idx] += val;
		idx += (idx&(-idx));
	}
}

int query(int idx){
	int res = 0;
	while(idx > 0){
		res += fenwick[idx];
		idx -= (idx&(-idx)); 
	}
	return res;
}
