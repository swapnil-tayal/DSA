class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int x = abs(sx-fx)+1;
        int y = abs(sy-fy)+1;
        
        int sm = 0;
        if(x == 1 and y == 1) return t != 1;
        sm = min(x,y)-1;
        sm += max(x,y) - min(x,y);
        return sm <= t;
    }
        
};