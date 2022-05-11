// in pbds lower_bound = upper_bound in normal multiset and vice versa?!
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define oset tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update>

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin >> n >> q;
	vector<long long> a(n);
	for(auto &i: a) cin >> i;
	oset s;
	for(auto i: a) s.insert(i);
	while(q--){
		char type;
		cin >> type;
		if(type == '?'){
			long long lo,hi;
			cin >> lo >> hi;
			int ans = s.order_of_key(hi+1)-s.order_of_key(lo);
			cout << ans << "\n";
		}else{
			int idx;
			long long val;
			cin >> idx >> val;
			idx--;
			s.erase(s.upper_bound(a[idx]));
			a[idx] = val;
			s.insert(val);
		}
		dbg(s);
	}
	return 0;
}
