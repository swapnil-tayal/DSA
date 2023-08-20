class Solution {
public:
    
    int f(int i, vector<int> &nums, int prev, vector<vector<int>> &dp){
        
        if(i == nums.size()) return 0;
        
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int chg1 = 1e9, chg2 = 1e9, chg3 = 1e9;
        if(prev == 0 || prev == 1){
            
            chg1 = (nums[i] != 1) + f(i+1, nums, 1, dp);
            chg2 = (nums[i] != 2) + f(i+1, nums, 2, dp);
            chg3 = (nums[i] != 3) + f(i+1, nums, 3, dp);
            
        }else if(prev == 2){
            
            chg2 = (nums[i] != 2) + f(i+1, nums, 2, dp);
            chg3 = (nums[i] != 3) + f(i+1, nums, 3, dp);
        
        }else chg3 = (nums[i] != 3) + f(i+1, nums, 3, dp);
        
        return dp[i][prev] = min({ chg1, chg2, chg3 });
    }
    
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, nums, 0, dp);
    }
};