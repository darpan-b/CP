/**
 * Standard implementation of the Convex Hull Trick
 * CHT can be used to optimize dp problems from O(n^2) complexity to O(nlogn)
 * This can be only done for specific problem whose dp relation is somewhat like this:
 * dp[x] = a[x]*b[x] + dp[x]
 * Basically, the relation should be similar to the line equation, y = mx+c
 * In this problem, the dp relation is as follows:
 * dp[i] = min{a[i]*b[j] + dp[j]} for all j < i
 * Link to the problem: https://codeforces.com/contest/319/problem/C
 * The code may differ a bit for the problems that require max over some subset of indices.
 * For the min problem, we sort the lines in decreasing order of slope, while for the max problem, we sort in increasing order.
 * The comments may be updated after meooow answers the clarifications.
*/

#include <bits/stdc++.h>

#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define puro(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define MS(x,a) memset((x),(a),sizeof(x)) 
#define F0R(i,n) for(auto (i) = 0; (i) < (n); (i)++)
#define FOR(i,a,b) for(auto (i) = (a); (i) <= (b); (i)++)
#define ROF(i,a,b) for(auto (i) = (a); (i) >= (b); (i)--)

using namespace std;


struct Line {
	// m = slope of the line
	// c = y intercept of the line
	// xLeft = stores the intersection point, x with the previous line in the hull
	ll m,c; 
	ld xLeft;
	bool isQuery;
	Line(ll _m, ll _c) {
		m = _m; c = _c; xLeft = 0.0;
		isQuery = false;
	}
	Line() {
		m = c = xLeft = 0;
		isQuery = false;
	}

	// returns the x co-ordinate of the intersection point between this line and line l
	// returns inf if both the lines are parallel 
	ld meet(const Line l) {
		if(l.m == m) return 1e18;
		return 1.0*(c-l.c)/(l.m-m);
	}

	// if the line other is used for query, then sort according to x coordinate of intersection points
	// else sort according to slopes
	// if problem requires minimum over some range, then sort slopes in decreasing order
	// else sort slopes in increasing order
	bool operator < (const Line& other) const {
		if(other.isQuery) return xLeft < other.xLeft;
		else return m > other.m;
	}
};

struct CHT {
	// stores the lines of the hull
	set<Line> hull;
	typedef set<Line>::iterator itr;

	CHT() { hull.clear(); }

	// hasPrevious returns true if there is a line before it in the hull
	// hasNext returns true if there is a line after it in the hull
	bool hasPrevious(itr it) { return it != hull.begin(); }
	bool hasNext(itr it) { return (it != hull.end() && it != prev(hull.end())); }

	// the middle line is useless if the y co-ordinate of the meeting point between the left and the right lines
	// is more than the y co-ordinate of the meeting point between the middle and right lines.
	// (why ? to be updated later after reply from meooow on cf)
	bool useless(Line lft,Line mddle,Line rit) { 
		ld x = lft.meet(rit);
		ld yMiddle = x*mddle.m+mddle.c;
		ld yLeft = x*lft.m+lft.c;
		return yMiddle > yLeft;
	}
	bool useless(itr it) {
		if(hasPrevious(it) && hasNext(it)) {
			return useless(*prev(it),*it,*next(it));
		}
		return false;
	}

	// updates the borders of the hull if the given line is included in the hull
	// for the line to the right of the current line (if any), it updates the xLeft of the right line to the intersection point
	// between the cuurent line and the right line. for the line to the left of the current line, it updates the xLeft of the 
	// current line to the intersection point of the current line and the left line.
	// note that if the current line is the leftmost line, then it updates the xLeft value of the current line to -inf.
	void updateBorder(itr it) {
		if(hasNext(it)) {
			Line temp = *next(it);
			hull.erase(temp);
			temp.xLeft = temp.meet(*it);
			hull.insert(temp);
		}
		if(hasPrevious(it)) {
			Line temp = *it;
			temp.xLeft = temp.meet(*prev(it));
			hull.erase(it);
			hull.insert(temp);
		} else {
			Line cur = *it;
			hull.erase(it);
			cur.xLeft = -1e18;
			hull.insert(cur);
		}
	}

	// adds a line with slope m and y-intercept c to the hull.
	void addLine(ll m,ll c) {
		Line temp = Line(m,c);
		itr it;
		it = hull.lower_bound(temp);
		
		// if there exists a parallel line to that of the current line in the hull,
		// then keep it or erase it based on the y-intercept.
		// here it erases the already present line if the y-intercept of that line is lesser
		// than that of the current line. 
		// (why? maybe because this problem asks for min over a range? again, waiting for meooow reply)
		if(it != hull.end() && it->m == temp.m) {
			if(it->c > c) hull.erase(it);
			else return;
		}
		
		// insert the current line in the hull and make the iterator point to the current line
		hull.insert(temp);
		it = hull.find(temp);

		// if the line is useless, then delete it from the hull
		if(useless(it)) {
			hull.erase(it);
			return;
		}

		// while there are useless lines to before and after the current line, delete them
		while(hasPrevious(it) && useless(prev(it))) hull.erase(prev(it));
		while(hasNext(it) && useless(next(it))) hull.erase(next(it));

		// update the borders of the current line and the lines to the left and right of it (if any).
		updateBorder(it);
	}

	// let the line l cover the x-coordinate, x in the given hull.
	// this returns the y-coordinate of the point (x,y) present on that line.
	// this can be found out by creating another line, ask, parallel to the x-axis and left end at x.
	// the iterator it points to the line whose left index is just greater than x.
	// our required line is the line immediately previous to it, which covers the x-coordinate, x.
	ll query(ll x) {
		if(hull.empty())return 1e18;
		Line ask(0,0);
		ask.xLeft = x;
		ask.isQuery = true;
		itr it = hull.lower_bound(ask);
		it = prev(it);
		return it->m*x+it->c;
	}
};


// O(n^2) brute force of the problem for debugging purposes 
void brute(int n,ll a[],ll b[]) {
	ll dp[n];
	F0R(i,n) dp[i] = 1e18;
	dp[0] = 0;
	FOR(i,1,n-1) {
		F0R(j,i) {
			dp[i] = min(dp[i],dp[j]+a[i]*b[j]);
		}
	}
	cout << "BRUTE = ";
	F0R(i,n) cout << dp[i] << " "; cout<< endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	ll a[n],b[n],dp[n];
	F0R(i,n) cin >> a[i];
	F0R(i,n) cin >> b[i];
	CHT cht;
	dp[0] = 0;
	cht.addLine(b[0],0);
	FOR(i,1,n-1) {
		dp[i] = cht.query(a[i]);
		cht.addLine(b[i],dp[i]);
	}
	cout << dp[n-1];
}	
