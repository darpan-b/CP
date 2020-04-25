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

/**
  * Description: Code to find the convex hull of a given set of points on the 2D plane
  * Source: Own
  * Verification: 
		:: Problem: https://www.codechef.com/problems/ECJAN20I
	  	:: Solution: https://www.codechef.com/viewsolution/31999285
  * Tips:
  		:: default datatype used for storing points here is int
  		   change it to long long or double if required
  * Date: 25 April 2020
  */

const int MX = 1e4+5;
int n,r;
pii a[MX]; // stores all the points on the plane
vector<pii> hull; // stores the convex hull of the points

/*  returns the signed area of the triangle formed by the points a,b,c
	if the signed area is +ve it means that the orientation of the points is anticlockwise
	else the orientation od the points a,b,c is clockwise
	Reference: https://cp-algorithms.com/geometry/oriented-triangle-area.html
*/
ll cross(pii& a,pii& b,pii& c) {
	ll x1 = b.F-a.F;
	ll x2 = c.F-b.F;
	ll y1 = b.S-a.S;
	ll y2 = c.S-b.S;
	return x1*y2-x2*y1;
}

/*  returns true if the points a,b,c are clockwise oriented */
bool cw(pii& a,pii& b,pii& c) {
	return cross(a,b,c) < 0;
}

/*  finds the convex hull of the points in the array a[] 
	and stores them in the the "hull" vector
*/
void convexHull() {
	pii leftmost = a[0], rightmost = a[n-1];
	hull.pb(leftmost);

	// traverses clockwise and finds the upper part of the convex hull 
	F0R(i,n) {
		if(i == n-1 || cw(leftmost,a[i],rightmost)) {
			while(SZ(hull) >= 2 && !cw(hull[SZ(hull)-2],hull[SZ(hull)-1],a[i])) hull.pop_back();
			hull.pb(a[i]);
		}
	}

	// reverses the points (otherwise we would have to traverse anticlockwise) 
	reverse(a,a+n);

	//finds the lower part of the hull
	FOR(i,1,n-2) {
		if(cw(rightmost,a[i],leftmost)) {
			while(SZ(hull) >= 2 && !cw(hull[SZ(hull)-2],hull[SZ(hull)-1],a[i])) hull.pop_back();
			hull.pb(a[i]);
		}
	}
}

/* Driver code */
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	hull.clear();	
	cin >> n;
	F0R(i,n) cin >> a[i].F >> a[i].S;

	// points are sorted from left to right and bottom to top
	sort(a,a+n);

	// finding out the convex hull 
	convexHull();
}	
