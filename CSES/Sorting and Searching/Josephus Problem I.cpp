#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=2; i<=n; i+=2) cout << i << " ";
	bool skip=(n&1^1);
	vector<int> odd;
	for(int i=1; i<=n; i+=2) odd.push_back(i);
	while(!odd.empty()){
		vector<int> notdone;
		for(int i=0; i<(int)odd.size(); i++){
			if(!skip){
				cout << odd[i] << " ";
			}else{
				notdone.push_back(odd[i]);
			}
			skip^=1;
		}
		odd=notdone;
	}
	return 0;
}
