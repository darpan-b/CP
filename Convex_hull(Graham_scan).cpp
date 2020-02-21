/**
 * This code finds the convex hull for a given set of points using Graham's scan algorithm.
 * It is basically a copy of the code here : https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
 * but commented.
 * Instead of the pt struct I am using pair<T,T> here
 */

#include <bits/stdc++.h>
using namespace std;

#define pt pair<int,int>
#define x first
#define y second

// Comparator function for sorting the points
bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}


// Returns true if points a, b and c are clockwise oriented
bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}


// Returns true if points a, b and c are counter clockwise oriented
bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}


// Returns the convex hull of the set of points, a 
vector<pt> convex_hull(vector<pt>& a) {
    
    // Convex hull for a single point is that point itself
    if (a.size() == 1)
        return a;

    // Sorts the points in the order of leftmost point to rightmost point
    sort(a.begin(), a.end(), &cmp);
    
    // p1 is leftmost point, p2 is rightmost point
    pt p1 = a[0], p2 = a.back();

    // up vector stores the points in the upper part of the hull
    // down vector stores the points in the lower part of the hull
    vector<pt> up, down;
    
    // the leftmost point and rightmost point are included in both hulls
    up.push_back(p1);
    down.push_back(p1);

    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            
            // rejecting all the interior points of the hull
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
                
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            
            // rejecting all the interior points of the hull
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            
            down.push_back(a[i]);
        }
    }
    
    // stores the convex hull of the set of points a
    vector<pt> hull;
    
    // Adding all the points of the upper part of the hull
    for (int i = 0; i < (int)up.size(); i++)
        hull.push_back(up[i]);
        
    // Adding all the points of the lower part of the hull 
    // ignoring the leftmost and rightmost point that has already been added earlier
    for (int i = down.size() - 2; i > 0; i--)
        hull.push_back(down[i]);
        
    // returning the convex hull of the set of points a
    return hull;
}


// Driver code
int main() {
                                                                                                            
    // n stores the number of points
    int n; cin >> n;                                                        
    
    // stores the set of points
    vector<pt> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    
    // stores the convex hull of the set of points a
    vector<pt> hull = convex_hull(a);
    
    // printing the convex hull
    cout << "Convex hull = " << endl;
    for(auto& i: hull) {
        cout << "(" <<  i.x << " " << i.y << ")" << endl;
    }

    return 0;
}
