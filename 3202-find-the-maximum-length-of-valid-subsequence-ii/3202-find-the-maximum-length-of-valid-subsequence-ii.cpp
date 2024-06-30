class Solution{
    unordered_map<int, vector<int>> mp;
public:
    
    int f(int i, vector<int> &nums, int prev, int isSec, vector<vector<vector<int>>> &dp){
        
        if(i == nums.size()) return 0;
        if(dp[i][isSec][prev+1] != -1) return dp[i][isSec][prev+1];
        
        if(prev == -1){
            
            int pick = 1 + f(i+1, nums, i, 1, dp);
            int npick = f(i+1, nums, prev, 0, dp);
            return dp[i][prev+1][isSec] = max(pick, npick);
            
        }else if(isSec){
            
            int lastVal = nums[prev];
            int ind = upper_bound(mp[lastVal].begin(), mp[lastVal].end(), i) - mp[lastVal].begin();
            int pick = 1;
            if(mp[lastVal].size() > ind) pick = 1 + f(mp[lastVal][ind], nums, i, 0, dp);
            int npick = f(i+1, nums, prev, 1, dp);
            return dp[i][isSec][prev+1] = max(pick, npick);
            
        }else{
            
            int lastVal = nums[prev];
            int ind = upper_bound(mp[lastVal].begin(), mp[lastVal].end(), i) - mp[lastVal].begin();
            int pick = 1;
            if(mp[lastVal].size() > ind){
                pick = 1 + f(mp[lastVal][ind], nums, i, 0, dp);
            }
            return dp[i][isSec][prev+1] = pick;
        }
    }
    
    int maximumLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[i] = nums[i] % k;
            mp[nums[i]].push_back(i);
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(n, -1)));
        return f(0, nums, -1, 0, dp);
    }
};