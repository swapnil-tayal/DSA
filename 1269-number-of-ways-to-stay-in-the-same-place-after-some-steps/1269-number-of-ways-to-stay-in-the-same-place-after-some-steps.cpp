class Solution {
    int totalSteps;
    int arrLen;
    int const mod = 1000000007;
public:
    
    int f(int i, int steps, vector<vector<int>> &dp){
        
        if(i >= min(arrLen, totalSteps)) return 0;
        if(i < 0) return 0;
        if(steps == 0) return i == 0;
        if(dp[i][steps] != -1) return dp[i][steps];
        
        int stay = f(i, steps-1, dp);
        int left = f(i-1, steps-1, dp);
        int right = f(i+1, steps-1, dp);
        
        return dp[i][steps] = ((long long)stay + (long long)left + (long long)right) % mod;
    }
    
    int numWays(int steps, int arrLen) {
        this->totalSteps = steps;
        this->arrLen = arrLen;
        vector<vector<int>> dp(min(arrLen, totalSteps)+1, vector<int>(steps+1, -1));
        return f(0, steps, dp);
    }
};