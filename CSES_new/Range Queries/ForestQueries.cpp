#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,q;
	cin>>n>>q;
	vector<string> grid(n);
	for(auto &i:grid)cin>>i;
	
	vector<vector<int>> pre(n,vector<int>(n,0));
	pre[0][0]=(grid[0][0]=='*');
	for(int i=1;i<n;i++)
	{
		pre[0][i]=pre[0][i-1]+(grid[0][i]=='*');
		pre[i][0]=pre[i-1][0]+(grid[i][0]=='*');
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(grid[i][j]=='*');
	}

	while(q--)
	{
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		l1--; l2--; r1--; r2--;
		int ans=pre[l2][r2]; dbg(ans);
		if(l1)ans-=pre[l1-1][r2]; dbg(ans);
		if(r1)ans-=pre[l2][r1-1]; dbg(ans);
		if(l1 && r1)ans+=pre[l1-1][r1-1];
		cout<<ans<<"\n";
	}
	return 0;
}
