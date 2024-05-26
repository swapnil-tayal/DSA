class Solution {
public:
    
    int f(int i, int cntA, int isLastL, vector<vector<vector<int>>> &dp){
        
        if(i == 0) return 1;
        
        if(dp[i][cntA][isLastL] != -1) return dp[i][cntA][isLastL]; 
        int ans = 0;
        ans += f(i-1, cntA, 0, dp);
        
        if(cntA < 1) ans = (ans + f(i-1, cntA+1, 0, dp)) % (int)(1e9+7);
        if(isLastL < 2) ans = (ans + f(i-1, cntA, isLastL+1, dp)) % (int)(1e9+7);
        return dp[i][cntA][isLastL] = ans;
    }
    
    int checkRecord(int n) {
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(n, 0, 0, dp);
    }
};