class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+2, 0);
        
        for(int i=n-1; i>=0; i--){
            
            int pick = nums[i] + dp[i+2];
            int npcik = max(dp[i+1], dp[i+2]);
            
            dp[i] = max(pick, npcik);
        }
        return dp[0];
    }
};