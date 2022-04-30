#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<long long> a(n);
	for(auto &i:a)cin>>i;

	ordered_set currentIndices;
	for(int i=0;i<n;i++)currentIndices.insert(i);

	for(int i=0;i<n;i++)
	{

		int idx;
		cin>>idx;
		idx--;
		int ans=*currentIndices.find_by_order(idx);
		cout<<a[ans]<<" ";
		currentIndices.erase(ans);

	}
	cout<<"\n";
	return 0;

}
