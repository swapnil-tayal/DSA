class Solution {
public:
    
    int f(vector<int> &nums, int target, vector<int> &dp){
        
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        
        int pick = 0;
        
        for(int j=0; j<nums.size(); j++){
            pick += f(nums, target-nums[j], dp);    
        }
        return dp[target] = pick;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1, -1);
        return f(nums, target, dp);
    }
};