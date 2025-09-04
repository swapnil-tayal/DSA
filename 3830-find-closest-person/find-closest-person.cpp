class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        x = abs(z-x);
        y = abs(z-y);
        if(x > y) return 2;
        else if(y > x) return 1;
        else return 0;
    }
};