// Finds convex hull of a given set of points on a 2D plane.
//Adjust #define point __ as per problem.

#define point pair<long long, long long>
#define x first
#define y second

// Returns the signed area of the three points passed as parameters.
// Check https://cp-algorithms.com/geometry/oriented-triangle-area.html if confused.
long long crossProduct(point a, point b, point c) {
    long long x1 = b.x - a.x;
    long long x2 = c.x - b.x;
    long long y1 = b.y - a.y;
    long long y2 = c.y - b.y;
    return x1 * y2 - x2 * y1;
}

// Returns true if points a, b, c are clockwise oriented
bool clockwise(point a, point b, point c) {
    return crossProduct(a, b, c) < 0;
}

// returns the convex hull of the given set of points
vector<point> convexHull(vector<point>& points) {
    int totalPoints = points.size();
    sort(points.begin(), points.end());
    point leftmost = points[0], rightmost = points.back();
    vector<point> hull;
    
    // traverses clockwise and finds the upper part of the hull
    for (int i = 0; i < totalPoints; i++) {
        if (i == totalPoints - 1 || clockwise(leftmost, points[i], rightmost)) {
            while (hull.size() >= 2 && !clockwise(hull[hull.size() - 2], hull.back(), points[i])) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
    }
    
    // traverses anticlockwise and finds the lower part of the hull
    for (int i = totalPoints - 2; i >= 1; i--) {
        if (clockwise(rightmost, points[i], leftmost)) {
            while (hull.size() >= 2 && !clockwise(hull[hull.size() - 2], hull.back(), points[i])) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
    }
    return hull;
}
