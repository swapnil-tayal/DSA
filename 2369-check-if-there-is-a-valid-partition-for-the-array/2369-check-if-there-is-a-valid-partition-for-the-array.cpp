class Solution {
public:
    
    int f(int i, vector<int> &nums, vector<int> &dp){
        
        if(i == nums.size()-1) return 0;
        if(i == nums.size()) return 1;
        if(dp[i] != -1) return dp[i];
        
        int step1 = 0;
        int step2 = 0;
        int step3 = 0;
        
        if(i+2 < nums.size()){
            
            if(nums[i] == nums[i+1]){
                if(nums[i+1] == nums[i+2]) step2 = f(i+3, nums, dp); 
                step1 = f(i+2, nums, dp);
            
            }if(nums[i]+1 == nums[i+1] and nums[i+1]+1 == nums[i+2]){
                step3 = f(i+3, nums, dp);
            }
        
        }else if(i+1 < nums.size() and nums[i] == nums[i+1]){
            step1 = f(i+2, nums, dp);
        }
        
        return dp[i] = (step1 or step2 or step3);
    }
    
    bool validPartition(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
};