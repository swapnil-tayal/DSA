class Solution {
    const int mod = ((1e9)+7);
public:

    long long f(long long n, long long k, map<string,long long> &dp){

        if(n == 1) return ((k==0) ? 5 : 4);
        if(n == 2) return 20;
        string str = to_string(n) + "_" + to_string(k);
        if(dp.count(str)) return dp[str];
        long long ans = ((f(n/2, 0, dp) % mod)  * (f(n/2, 1, dp) % mod)) % mod;
        if(n%2 == 1) ans = (ans * ((k==0) ? 5 : 4)) % mod;
        dp[str] = ans;
        return ans;
    }

    int countGoodNumbers(long long n) {
        
        if(n == 1) return 5;
        map<string,long long> dp;
        return f(n, 0, dp);
    }
};