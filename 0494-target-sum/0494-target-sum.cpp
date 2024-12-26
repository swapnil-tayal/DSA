class Solution {
public:
    
    int f(int i, int sum, int &target, vector<int> &nums, vector<vector<int>> &dp){
        
        if(i == nums.size()){
            return target == sum;
        }
        if(dp[i][sum+1000] != -1) return dp[i][sum+1000];
        int ans = 0;
        ans += f(i+1, sum + nums[i], target, nums, dp);
        ans += f(i+1, sum - nums[i], target, nums, dp);
        return dp[i][sum+1000] = ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2000, -1));
        return f(0, sum, target, nums, dp);
    }
};