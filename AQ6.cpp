#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;


struct Point {
    double x, y;
};

double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

double bruteForce(vector<Point> &p, int l, int r, pair<Point, Point> &bestPair) {
    double mn = 1e18;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            double d = dist(p[i], p[j]);
            if (d < mn) {
                mn = d;
                bestPair = {p[i], p[j]};
            }
        }
    }
    return mn;
}

double stripClosest(vector<Point> &strip, double d, pair<Point, Point> &bestPair) {
    double mn = d;
    sort(strip.begin(), strip.end(), [](const Point &a, const Point &b) {
        return a.y < b.y;
    });

    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size() && (strip[j].y - strip[i].y) < mn; j++) {
            double distVal = dist(strip[i], strip[j]);
            if (distVal < mn) {
                mn = distVal;
                bestPair = {strip[i], strip[j]};
            }
        }
    }
    return mn;
}

double closestUtil(vector<Point> &p, int l, int r, pair<Point, Point> &bestPair) {
    if (r - l <= 3)
        return bruteForce(p, l, r, bestPair);

    int mid = l + (r - l) / 2;
    Point midPoint = p[mid];

    pair<Point, Point> leftPair, rightPair;
    double dl = closestUtil(p, l, mid, leftPair);
    double dr = closestUtil(p, mid + 1, r, rightPair);

    double d;
    if (dl < dr) {
        d = dl;
        bestPair = leftPair;
    } else {
        d = dr;
        bestPair = rightPair;
    }

    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if (fabs(p[i].x - midPoint.x) < d)
            strip.push_back(p[i]);
    }

    pair<Point, Point> stripPair;
    double ds = stripClosest(strip, d, stripPair);

    if (ds < d) {
        bestPair = stripPair;
        return ds;
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Point> points = {
        {9,3}, {2,6}, {15,3}, {5,1},
        {1,2}, {12,4}, {7,2}, {4,7},
        {16,5}, {3,3}, {10,5}, {6,4},
        {14,6}, {8,6}, {11,1}, {13,2}
    };

    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });

    pair<Point, Point> bestPair;
    double minDist = closestUtil(points, 0, (int)points.size() - 1, bestPair);

    cout << "Closest Pair: (" << bestPair.first.x << ", " << bestPair.first.y << ") and ("
         << bestPair.second.x << ", " << bestPair.second.y << ")\n";
    cout << "Minimum Distance = " << fixed << setprecision(6) << minDist << "\n";

    return 0;
}
