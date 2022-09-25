#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

#define ll long long

void solve(int test)
{
	string s;
	cin >> s;
	int n = (int)s.size();

	vector<vector<int>> cnt(n,vector<int>(26,0));
	cnt[0][s[0]-'a']++;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < 26; j++) cnt[i][j] = cnt[i-1][j];
		cnt[i][s[i]-'a']++;
	}

	int ans = 0;
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		l--; r--;

		if((r-l+1)%2 == 0)
		{
			continue;
		}

		int mid = l + ((r-l+1)/2);
		
		// cout << l << " " << mid << " " << r << endl;
		int one = 0;
		bool ok = true;
		for(int i = 0; i < 26; i++)
		{
			if((cnt[r][i]-cnt[mid][i]) - (cnt[mid][i]-(l > 0? cnt[l-1][i]:0)) == -1) one++;
			else if((cnt[r][i]-cnt[mid][i]) - (cnt[mid][i]-(l > 0? cnt[l-1][i]:0)) == 0);
			
			// if(cnt[mid][i]-cnt[mid-1][i] == 1) one++;
			// else if(cnt[mid][i]-cnt[mid-1][i] == 0);
			else
			{
				ok = false;
				break;
			}
		}
		if(ok && one == 1)
		{
			ans++;
			// cout << "WOW\n";
			continue;
		}
		ok = true;
		one = 0;
		mid--;
				// cout << l << " " << mid << " " << r << endl;

		for(int i = 0; i < 26; i++)
		{
			if((cnt[r][i]-cnt[mid][i]) - (cnt[mid][i]-(l > 0? cnt[l-1][i]:0)) == 1) one++;
			else if((cnt[r][i]-cnt[mid][i]) - (cnt[mid][i]-(l > 0? cnt[l-1][i]:0)) == 0);

			// if(cnt[mid][i]-cnt[mid-1][i] == 1) one++;
			// else if(cnt[mid][i]-cnt[mid-1][i] == 0);
			else
			{
				ok = false;
				break;
			}
		}
		if(ok && one == 1)
		{
			ans++;
		}
	}
	cout << "Case #" << test << ": " << ans << "\n";
}

int main()
{
	freopen("perfectly_balanced_chapter_1_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >> test;
	for(int i = 1; i <= test; i++) solve(i);
	return 0;
}
