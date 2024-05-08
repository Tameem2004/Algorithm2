#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

struct Point
{
	int x, y;
};

// A global point --> reference point Used in compare function of qsort()
Point p0;

// function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

// function to swap two points
void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

// function to find square of distance between p1 and p2
int distSq(Point p1, Point p2)
{
	return (pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
}

// function to find orientation of ordered triplet (p, q, r).
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // collinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

// function used by library function qsort() to sort an array of points wrt 1st point
int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}

// function to print convex hull of a set of n points.
void convexHull(Point points[], int n)
{
    // Find the bottom-most point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // bottom-most or left most point (if its a tie)
        if ((y < ymin) || (ymin == y &&
            points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at first position
    swap(points[0], points[min]);

    // Sorting n-1 points wrt the first point.
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++)
    {
        while (i < n-1 && orientation(p0, points[i],
                                        points[i+1]) == 0)
            i++;


        points[m] = points[i];
        m++; 
    }

    if (m < 3) return; //convex hull possible with number of points more than 3

    // Stack to push first three points
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // for the remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // printing contents of stack
    while (!S.empty())
    {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y <<")" << endl;
        S.pop();
    }
}
int main() 
{
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    Point points[n];
    cout << "Enter the coordinates of each point [Format for point p --> px py]:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Point " << i+1 << ": ";
        cin >> points[i].x >> points[i].y;
    }
    cout << "\nConvex Hull points are:\n";
    convexHull(points, n);
    return 0;
}