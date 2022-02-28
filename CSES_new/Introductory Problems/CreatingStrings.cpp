#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	cin >> str;
	sort(str.begin(), str.end());
	vector<string> ans{ str };
	while(next_permutation(str.begin(),str.end()))
		ans.push_back(str);
	cout << ans.size() << "\n";
	for (const auto &e : ans)
		cout << e << "\n";
	return 0;
}
