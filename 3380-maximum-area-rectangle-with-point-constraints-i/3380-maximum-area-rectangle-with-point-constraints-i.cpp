typedef pair<int, int> Point;
typedef long long ll;

class Solution {
public:
    struct PointHash {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
    bool hasPointsInsideOrOnBorder(int x1, int y1, int x2, int y2, const unordered_set<Point, PointHash>& pointSet) {
        for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
            for (int y = min(y1, y2); y <= max(y1, y2); ++y) {
                if (pointSet.count({x, y})) {
                    if (x == x1 || x == x2 || y == y1 || y == y2) {
                        if (!(x == x1 && y == y1) && !(x == x2 && y == y2) && !(x == x1 && y == y2) && !(x == x2 && y == y1)) {
                            return true; // Point on the border of another rectangle
                        }
                    } else {
                        return true; // Point inside
                    }
                }
            }
        }
        return false;
    }

    int maxRectangleArea(vector<vector<int>>& points) {
        unordered_set<Point, PointHash> pointSet;
        for (auto& point : points) {
            pointSet.insert({point[0], point[1]});
        }

        int maxArea = -1;

        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 != x2 && y1 != y2) { // Ensure they form a diagonal
                    if (pointSet.count({x1, y2}) && pointSet.count({x2, y1})) {
                        if (!hasPointsInsideOrOnBorder(x1, y1, x2, y2, pointSet)) {
                            int area = abs(x2 - x1) * abs(y2 - y1);
                            maxArea = max(maxArea, area);
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};