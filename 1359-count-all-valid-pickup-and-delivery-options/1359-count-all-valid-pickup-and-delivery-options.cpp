class Solution {
    const int mod = 1e9 + 7;
public:
    
    long long f(int n){
        
        if(n == 0) return 1;
        long long ans = f(n-1) * (2*n - 1) * n % mod;
        return ans;
    }
    
    int countOrders(int n) {
        return f(n);
    }
};