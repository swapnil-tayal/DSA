class Solution {
public:
    
    long long f(int i, vector<int> &nums, int k, int cnt, vector<vector<long long>> &dp){
        
        if(i == nums.size()) return 0;
        
        if(dp[i][cnt] != -1) return dp[i][cnt];
        
        long long pick = max(0, k-nums[i]) + f(i+1, nums, k, 2, dp);
        long long npick = 1e18;
        if(cnt > 0) npick = f(i+1, nums, k, cnt-1, dp);
        
        return dp[i][cnt] = min(pick, npick);
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(3, -1));
        return f(0, nums, k, 2, dp);
    }
};