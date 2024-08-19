class Solution {
public:
    
    int f(int curr, int tar, vector<int> &dp){
        
        if(curr == tar) return 0;
        if(curr > tar) return 1e9;
        if(dp[curr] != -1) return dp[curr];
        
        int paste = 1e9;
        for(int i=1; i<1000; i++){
            paste = min(paste, 1 + i + f(curr + (i*curr), tar, dp));
        }
        return dp[curr] = paste;
    }
    
    int minSteps(int n) {
        
        vector<int> dp(n, -1);
        return f(1, n, dp);
    }
};