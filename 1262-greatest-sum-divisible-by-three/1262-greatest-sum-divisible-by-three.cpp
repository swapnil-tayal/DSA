class Solution {
public:
    
    int f(int i, vector<int> &nums, int sum, vector<vector<int>> &dp){
        
        if(i == nums.size()){
            
            if(sum == 0) return 0;
            else return -1e9;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int pick = nums[i] + f(i+1, nums, (sum + nums[i]) % 3, dp);
        int npick = f(i+1, nums, sum, dp);
        
        return dp[i][sum] = max(pick, npick);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(0, nums, 0, dp);
    }
};