class Solution {
public:
    
    int f(int i, int n, int k, vector<vector<int>> &dp){
        
        if(i == n+1) return k == 0;
        if(dp[i][k] != -1) return dp[i][k];
        int rem = n-i;
        
        if(k > (rem+1)*(rem)/2) return 0;
        
        int ans = f(i+1, n, k, dp);
        for(int j=1; j<=rem; j++){
            
            if(k-j < 0) break;
            ans = (ans + f(i+1, n, k-j, dp)) % int(1e9+7);
        }
        return dp[i][k] = ans;
    }
    
    int kInversePairs(int n, int k) {
        
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(1, n, k, dp);
    }
};