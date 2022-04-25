#include <iostream>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

int main()
{
	int n,x;
	cin >> n >> x;
	vector<int> h(n),s(n);
	for(auto& e:h) cin >> e;
	for(auto& e:s) cin >> e;
	vector<int> dp(x+1,0);
	for(int i = 0; i < n; i++)
	{
		vector<int> newdp(x+1,0);
		for(int j = 1; j <= x; j++)
		{
			newdp[j] = dp[j];
			if(h[i] > j) continue;
			newdp[j] = max(newdp[j], dp[j-h[i]]+s[i]);
		}
		dp = newdp;
		dbg(dp);
	}
	cout << dp[x] << "\n";
	return 0;
}
