class Solution {
    long long k;
    int n;
public:
    
    long long f(int src, int isXor, vector<int> &nums, vector<vector<long long>> &dp){
        
        if(src == n){
            return (isXor==0) ? 0 : -INT_MAX;
        }
        if(dp[src][isXor] != -1) return dp[src][isXor];
        
        long long npick = nums[src] + f(src+1, isXor, nums, dp);
        long long pick = (nums[src]^k) + f(src+1, (isXor+1)%2, nums, dp);
        
        return dp[src][isXor] = max(pick, npick);
    }
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        this->k = k;
        this->n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, 0, nums, dp);
    }
};