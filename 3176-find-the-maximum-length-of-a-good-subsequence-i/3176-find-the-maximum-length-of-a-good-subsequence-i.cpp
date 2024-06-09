class Solution {
    vector<vector<vector<int>>> dp;
public:
    
    int f(int i, int prev, int k, vector<int> &nums, vector<vector<vector<int>>> &dp){
        
        if(i == nums.size()) return 0;
        if(dp[i][k][prev+1] != -1) return dp[i][k][prev+1];
        
        int pick, npick;
        if(prev == -1){
            
            pick = 1 + f(i+1, i, k, nums, dp);
            npick = f(i+1, prev, k, nums, dp);
        
        }else{
            pick = 0;
            if(nums[prev] != nums[i] and k-1 >= 0){
                pick = 1 + f(i+1, i, k-1, nums, dp);
            
            }else if(nums[prev] == nums[i]) pick = 1 + f(i+1, i, k, nums, dp);
            
            npick = f(i+1, prev, k, nums, dp);
        }
        return dp[i][k][prev+1] = max(pick, npick);
    }
    
    int maximumLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(k == 0){
            map<int,int> mp;
            for(auto i: nums) mp[i]++;
            int maxi = -1;
            for(auto i: mp){
                maxi = max(maxi, i.second);
            }
            return maxi;
        }
        
        dp.resize(n, vector<vector<int>>(k+1, vector<int>(n+1, -1)));
        return f(0, -1, k, nums, dp);
    }
};