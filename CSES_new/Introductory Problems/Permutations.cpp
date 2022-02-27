#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n >= 2 && n <= 3)
	{
		cout << "NO SOLUTION\n";
		return 0;
	}
	int m = n;
	if (n & 1)
		n--;
	vector<int> left, right;
	for (int i = 1; i <= n / 2; i++)
	{
		if (i & 1)
		{
			left.push_back(i);
			right.push_back(n - i + 1);
		}
		else
		{
			right.push_back(i);
			left.push_back(n - i + 1);
		}
	}
	if (m > n)
		n++;
	if (n & 1)
		left.push_back(n);
	reverse(left.begin(), left.end());
	for (const auto &e : left)
		cout << e << " ";
	for (const auto &e : right)
		cout << e << " ";
	cout << "\n";
	return 0;
}
