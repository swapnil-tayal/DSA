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
            for(int k=max(prev, val-nums[i-1]+prev); k<=val; k++){
                if(k >= prev and val-k <= nums[i-1]-prev){
                    cnt = (cnt + f(i+1, k, nums, dp)) % (int)(1e9+7);
                }
            }
        }
        return dp[i][prev+1] = cnt;
    }
    
    int countOfPairs(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(52, -1));
        
        for(int i=n-1; i>=0; i--){
            for(int prev=50; prev>=-1; prev--){
                
                int val = nums[i];
                int cnt = 0;

                for(int k=0; k<=val; k++){

                    if(prev == -1 || i == 0) cnt = (cnt + (i+1==n ? 1 : dp[i+1][k+1])) % int(1e9 + 7);
                    else{
                        if(k >= prev and val-k <= nums[i-1]-prev){
                            cnt = (cnt + (i+1==n ? 1 : dp[i+1][k+1])) % (int)(1e9+7);
                        }
                    }
                }
                dp[i][prev+1] = cnt; 
            }
        }
        
        return dp[0][-1+1];
    }
};