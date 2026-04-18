class Solution {
public:
    int mirrorDistance(int n) {
        
        int rev = 0;
        int temp = n;
        while(temp > 0){
            rev = rev * 10 + (temp % 10);
            temp = temp / 10;
        }
        return abs(rev - n);
    }
};