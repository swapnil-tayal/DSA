class Solution {
public:
    
    int f(int i, int n, vector<int> &cost, vector<int> &dp){
        
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(f(i+1, n, cost, dp), f(i+2, n, cost, dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(f(0, n, cost, dp), f(1, n, cost, dp));
    }
};