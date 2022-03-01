#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debugger.h"
#else
#define dbg(...) 5
#endif

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	set<int> done { 0 };
	vector<int> ans { 0 };
	int cur=0, fixed=1;
	while ((int)ans.size() < (1<<n))
	{
		bool found=false;
		for (int bit=fixed-1; bit>=0; bit--)
		{
			if (cur & (1<<bit))
			{
				int newcur = cur - (1<<bit);
				if (done.find(newcur) == done.end())
				{
					done.insert(newcur);
					ans.push_back(newcur);
					cur = newcur;
					found = true;
					break;
				}
			}
			else
			{
				int newcur = cur + (1<<bit);
				dbg(cur, newcur);
				if (done.find(newcur) == done.end())
				{
					done.insert(newcur);
					ans.push_back(newcur);
					cur = newcur;
					found = true;
					break;
				}
			}
		}
		dbg(cur, found);
		if (!found)
		{
			cur += (1<<fixed);
			ans.push_back(cur);
			done.insert(cur);
			fixed++;
		}
	}
	auto toBinary = [&](int num)
	{
		string res="";
		for (int bit=n-1; bit>=0; bit--)
		{
			if (num & (1<<bit))
				res += '1';
			else
				res += '0';
		}
		return res;
	};
	dbg(ans);
	for (const auto &e : ans)
		cout << toBinary(e) << "\n";
	return 0;
}
