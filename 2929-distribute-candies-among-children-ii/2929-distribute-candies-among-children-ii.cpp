class Solution {
public:

    long long f(long long n){
        return n*(n-1)/2;
    };
    
    long long distributeCandies(int n, int limit) {
        
        if(n > 3*limit) return 0;
        
        long long res = f(n+2);
        if(n-2 >= 2*limit){
            res += 3*f(n-2 * limit);
        }
        if(n > limit){
            res -= 3*f(n - limit + 1);
        }
        return res;
    }
};