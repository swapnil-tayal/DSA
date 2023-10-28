class Solution {
public:
    
    int f(int i, vector<int> &nums, int target, vector<vector<int>> &dp){
        
        if(target < 0) return -1e9;
        if(i == nums.size()){
            return target == 0 ? 0 : -1e9;
        }
        if(dp[i][target] != -1) return dp[i][target];
        
        int pick = 1 + f(i+1, nums, target - nums[i], dp);
        int npick = f(i+1, nums, target, dp);
        return dp[i][target] = max(pick, npick);
    }
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        int x = f(0, nums, target, dp);
        return x <= 0 ? -1 : x;
    }
};