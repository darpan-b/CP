#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset((x),(a),sizeof(x)) 
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;

/*
	Description: Kadane's algo to find maximum contiguous subarray sum
	Source: Own
	Verification: 
	Tips:
  		:: change value of INF and datatype of a according to problem
	Complexity: O(N)
	Date: 25 April 2020
*/

ll kadane(ll a[],int n){
	ll maxsum = -1e18,currsum = 0;
	for(int i = 0; i < n; i++){
		currsum += a[i];
		maxsum = max(maxsum,currsum);
		currsum = max(currsum,0);
	}
	return maxsum;
}
