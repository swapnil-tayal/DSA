class Solution {
public:
    
    int f(int i, vector<int> &nums, int len, vector<vector<int>> &dp){
        
        if(len < 0) return 1e9;
        if(i == nums.size()-1) return 1;
        
        if(dp[i][len] != -1) return dp[i][len];
        int pick = 1e9;
        if(len >= 0) pick = 1 + f(i+1, nums, nums[i]-1, dp);
        int npick = f(i+1, nums, len-1, dp);
        return dp[i][len] = min(pick, npick);
    }
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(1001, -1));
        return f(0, nums, nums[0], dp);
    }
};