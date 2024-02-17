class Solution{
public:
    
    int f(int i, int inc, vector<int> &nums, vector<vector<int>> &dp){
        
        if(i == nums.size()) return 0;
        if(dp[i][inc] != -1) return dp[i][inc];
        
        int ans = 0;
        if(inc == 0){
            
            ans = max(ans, f(i+1, 0, nums, dp));
            ans = max(ans, 1 + f(i+1, 1, nums, dp));
            ans = max(ans, 1 + f(i+1, 2, nums, dp));
        
        }else{
            
            if(inc == 1){
                if(nums[i] == nums[i-1]+1){
                    ans = max(ans, 1 + f(i+1, 1, nums, dp));
                
                }else if(nums[i]+1 == nums[i-1]+1){
                    ans = max(ans, 1 + f(i+1, 2, nums, dp));
                
                }else if(nums[i] == nums[i-1]){
                    ans = max(ans, f(i+1, 1, nums, dp));
                }
            }else{
                if(nums[i] == nums[i-1]+2){
                    ans = max(ans, 1 + f(i+1, 1, nums, dp));
                
                }else if(nums[i]+1 == nums[i-1]+2){
                    ans = max(ans, 1 + f(i+1, 2, nums, dp));
                
                }else if(nums[i] == nums[i-1]){
                    ans = max(ans, f(i+1, 2, nums, dp));
                }
            }
        }
        return dp[i][inc] = ans;
    }
    
    int maxSelectedElements(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(0, 0, nums, dp);
    }
};