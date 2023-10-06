class Solution {
public:
    
    int f(int s, int e, vector<vector<int>> &dp){
        
        if(s == e) return 1;
        if(dp[s][e] != -1) return dp[s][e];
        
        int ans = 1;
        for(int k=s; k<=e; k++){
            ans =  max(ans, (k-s+1) * f(k+1, e, dp));
        }
        return dp[s][e] = ans;
    }
    
    int integerBreak(int n) {
        
        if(n == 2) return 1;
        if(n == 3) return 2;
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return f(1, n, dp);
    }
};