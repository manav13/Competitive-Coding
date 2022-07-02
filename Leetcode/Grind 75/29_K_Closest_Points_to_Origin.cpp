#include<bits/stdc++.h>
using namespace std;

class Point {
    int dist, x, y;
    public:
    
    Point(int dist, int x, int y) {
        this->dist = dist;
        this->x = x;
        this->y = y;
    }
    int getDist() const {return dist;}    
    int getX() const {return x;}
    int getY() const {return y;}
};

class myComparator {
    public:
    
    bool operator() (const Point &p1, const Point &p2) {
        return p1.getDist() > p2.getDist();
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, myComparator> minHeap;
        
        for(auto point : points) {
            int dist = pow(point[0], 2) + pow(point[1], 2);
            minHeap.push(Point(dist, point[0], point[1]));
        }
        vector<vector<int>> result;
        while(k--) {
            Point p = minHeap.top();
            minHeap.pop();
            result.push_back({p.getX(), p.getY()});
        }
        return result;
    }
};

int main() {
    return 0;
}