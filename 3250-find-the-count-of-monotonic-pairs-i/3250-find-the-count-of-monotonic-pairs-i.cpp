class Solution {
public:
    
    int f(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
    
        if(i == nums.size()) return 1;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int val = nums[i];
        int cnt = 0;
        
        if(prev == -1){
            for(int k=0; k<=val; k++) cnt = (cnt + f(i+1, k, nums, dp)) % (int)(1e9+7);
        
        }else{
            for(int k=val-nums[i]+prev; k<=val; k++){
                if(k >= prev and val-k <= nums[i-1]-prev){
                    cnt = (cnt + f(i+1, k, nums, dp)) % (int)(1e9+7);
                }
            }
        }
        return dp[i][prev+1] = cnt;
    }
    
    int countOfPairs(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1002, -1));
        return f(0, -1, nums, dp);
    }
};