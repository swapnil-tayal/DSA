class DetectSquares {
    map<pair<int,int>, int> mp;
public:
    DetectSquares() {
        // do nothing
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];
        int ans = 0;
        for (auto &[p, cnt] : mp) {
            
            int x2 = p.first;
            int y2 = p.second;
            if (y2 != y || x2 == x) continue;
            int side = abs(x2 - x);
            ans += cnt * mp[{x, y + side}] * mp[{x2, y + side}];
            ans += cnt * mp[{x, y - side}] * mp[{x2, y - side}];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */