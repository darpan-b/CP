#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> ans;
	ans.pb({1,3});
	for (int i=2; i<=n; i++)
	{
		vector<pair<int,int>> next;
		for (const auto &e : ans)
		{
			pair<int,int> cur = e;
			if (cur.first == 2)
				cur.first = 3;
			else if (cur.first == 3)
				cur.first = 2;

			if (cur.second == 2)
				cur.second = 3;
			else if (cur.second == 3)
				cur.second = 2;
			next.pb(cur);
		}
		next.pb({1,3});
		for (const auto &e : ans)
		{
			pair<int,int> cur = e;
			if (cur.first == 2)
				cur.first = 1;
			else if (cur.first == 1)
				cur.first = 2;

			if (cur.second == 2)
				cur.second = 1;
			else if (cur.second == 1)
				cur.second = 2;
			next.pb(cur);
		}
		ans = next;
	}
	printf("%lu\n", ans.size());
	for (auto e : ans)
		printf("%d %d\n", e.first, e.second);
	return 0;
}
