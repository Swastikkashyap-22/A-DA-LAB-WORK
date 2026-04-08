// Convex Hull

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono> 
using namespace std;
using namespace std::chrono;

class Point {
public:
    int x, y;

    Point(int xCoord = 0, int yCoord = 0) : x(xCoord), y(yCoord) {}
};

class ConvexHull {
private:
    vector<Point> hull;

    int crossProduct(const Point& a, const Point& b, const Point& c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    void findHull(const vector<Point>& points, Point A, Point B) {
        int index = -1;
        int maxDistance = 0;

        for (int i = 0; i < points.size(); ++i) {
            int dist = abs(crossProduct(A, B, points[i]));
            if (dist > maxDistance) {
                maxDistance = dist;
                index = i;
            }
        }

        if (index == -1) return;

        Point P = points[index];
        hull.push_back(P);

        vector<Point> leftSet1, leftSet2;

        for (const auto& pt : points) {
            if (crossProduct(A, P, pt) > 0)
                leftSet1.push_back(pt);
            else if (crossProduct(P, B, pt) > 0)
                leftSet2.push_back(pt);
        }

        findHull(leftSet1, A, P);
        findHull(leftSet2, P, B);
    }

public:
    void computeHull(const vector<Point>& points) {
        hull.clear();
        if (points.size() < 3) return;

        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].x < points[minIdx].x)
                minIdx = i;
            if (points[i].x > points[maxIdx].x)
                maxIdx = i;
        }

        Point leftMost = points[minIdx];
        Point rightMost = points[maxIdx];

        hull.push_back(leftMost);
        hull.push_back(rightMost);

        vector<Point> upper, lower;
        for (const auto& pt : points) {
            int pos = crossProduct(leftMost, rightMost, pt);
            if (pos > 0)
                upper.push_back(pt);
            else if (pos < 0)
                lower.push_back(pt);
        }

        findHull(upper, leftMost, rightMost);
        findHull(lower, rightMost, leftMost);
    }

    void printHull() const {
        cout << "Convex Hull Points:\n";
        for (const auto& pt : hull)
            cout << "(" << pt.x << ", " << pt.y << ") ";
        cout << endl;
    }
};

int main() {
    vector<Point> points = {
        {2, 5}, {4, 7}, {-3, 6}, {6, 2}, 
        {1, -1}, {-5, 3}, {0, 4}, {3, -2}
    };

    ConvexHull ch;

    auto start = high_resolution_clock::now(); 
    ch.computeHull(points);
    auto stop = high_resolution_clock::now();  

    ch.printHull();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by computeHull: " << duration.count() << " microseconds" << endl;

    return 0;
}