class Solution {
public:
    
    int f(int s, int e, vector<vector<int>> &dp){
        
        if(s > e) return 1;
        if(s == e) return 1;
        if(dp[s][e] != -1) return dp[s][e];
        
        int cnt = 0;
        for(int i=s; i<=e; i++){
            cnt += f(s, i-1, dp) * f(i+1, e, dp);
        }
        return dp[s][e] = cnt;
    }
    
    int numTrees(int n) {
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, dp);
    }
};