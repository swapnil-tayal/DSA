class Solution {
public:
    
    long long f(int i, vector<int> &nums, int k, int cnt, vector<vector<long long>> &dp){
        
        if(i == nums.size()){
            // if(cnt == 0) return 1e9;
            return 0;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        
        if(cnt == 2){
            
            long long pick = max(0, k-nums[i]) + f(i+1, nums, k, 2, dp);
            long long npcik = f(i+1, nums, k, 1, dp);
            return dp[i][cnt] = min(pick, npcik);
            
        }else if(cnt == 1){
            
            long long pick = max(0, k-nums[i]) + f(i+1, nums, k, 2, dp);
            long long npcik = f(i+1, nums, k, 0, dp);
            return dp[i][cnt] = min(pick, npcik);
            
        }else{
            
            long long pick = max(0, k-nums[i]) + f(i+1, nums, k, 2, dp);
            return dp[i][cnt] = pick;
        }
        
    }
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(3, -1));
        return f(0, nums, k, 2, dp);
    }
};