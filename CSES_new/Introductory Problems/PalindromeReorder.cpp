#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	cin >> str;
	vector<int> count(26, 0);
	for (char ch : str)
		count[ch-'A']++;
	int countOdd = 0;
	for (int e : count)
		countOdd += (e%2 != 0);
	if (countOdd > 1)
	{
		printf("NO SOLUTION");
		return 0;
	}
	string lhs="", rhs="";
	char odd = '\0';
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < count[i]/2; j++)
		{
			lhs += (char)('A'+i);
			rhs += (char)('A'+i);
		}
		if(count[i] & 1)
			odd = (char)('A'+i);
	}
	reverse(rhs.begin(), rhs.end());
	cout << lhs;
	if (odd != '\0')
		cout << odd;
	cout << rhs << "\n";
	return 0;
}
