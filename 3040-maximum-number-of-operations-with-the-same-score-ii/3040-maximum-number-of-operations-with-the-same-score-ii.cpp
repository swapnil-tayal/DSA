class Solution {
public:
    
    int f(int i, int j, vector<int> &nums, int tar, vector<vector<int>> &dp){
        
        if(i >= nums.size() || j < 0) return 0;
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(nums[i] + nums[j] == tar){
            ans = max(ans, 1 + f(i+1, j-1, nums, tar, dp));
        }
        if(nums[i] + nums[i+1] == tar){
            ans = max(ans, 1 + f(i+2, j, nums, tar, dp));
        }
        if(nums[j] + nums[j-1] == tar){
            ans = max(ans, 1 + f(i, j-2, nums, tar, dp));
        }
        return dp[i][j] = ans;
    }
    
    int maxOperations(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        vector<vector<int>> dp3(n, vector<int>(n, -1));
        
        int ans = 1;
        ans = max(ans, f(0, n-1, nums, nums[0]+nums[1], dp1));
        ans = max(ans, f(0, n-1, nums, nums[n-2]+nums[n-1], dp2));
        ans = max(ans, f(0, n-1, nums, nums[0]+nums[n-1], dp3));
        return ans;
    }
};