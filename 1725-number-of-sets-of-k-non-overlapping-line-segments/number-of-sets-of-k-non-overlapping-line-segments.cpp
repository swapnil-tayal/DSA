class Solution {
    vector<vector<vector<int>>> dp;
    int mod = 1e9+7;
public:

    int f(int n, int k, int isOn){

        if(n == 0) return k == 0;
        if(k < 0) return 0;
        if(dp[n][k][isOn] != -1) return dp[n][k][isOn];
        int ans = 0;
        if(!isOn){
            ans = (ans + f(n-1, k, 0)) % mod;
            ans = (ans + f(n-1, k-1, 1)) % mod;
        }else{
            ans = (ans + f(n-1, k, 0)) % mod;
            ans = (ans + f(n-1, k-1, 1)) % mod;
            ans = (ans + f(n-1, k, 1)) % mod;
        }
        return dp[n][k][isOn] = ans;
    }

    int numberOfSets(int n, int k) {
        
        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return f(n-1, k, 0);
    }
};