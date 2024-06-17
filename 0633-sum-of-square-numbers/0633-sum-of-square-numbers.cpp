class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long long i=0; i<=1000000; i++){
            
            long long a = i*i;
            long long left = c - a; 
            if(left < 0) return 0;
            
            long long x = sqrt(left);
            if(x*x == left) return 1;
        }
        return 1;
    }
};