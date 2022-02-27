#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	cin >> str;
	int cur = 1, ans = 1;
	for (int i = 1; i < (int) str.size(); i++)
	{
		if (str[i] == str[i - 1])
			cur++;
		else
		{
			ans = max(ans, cur);
			cur = 1;
		}
	}
	ans = max(ans, cur);
	cout << ans << "\n";
	return 0;
}
