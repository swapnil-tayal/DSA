class Solution {
public:
    
    int f(int i, int prev, int p, map<long long, vector<int>> &mp, vector<int> &nums, vector<vector<vector<int>>> &dp){
        
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][prev][p] != -1) return dp[i][prev][p];
        
        if(p == 0){
            
            int pick = f(i+1, i, 1, mp, nums, dp);
            int npick = f(i+1, prev, 0, mp, nums, dp);
            return dp[i][prev][p] = pick + npick;
            
        }else if(p == 1){
            
            int npick =f(i+1, prev, 1, mp, nums, dp);
            long long diff = (long long)nums[i] - (long long)nums[prev];
            int pick = 0;
            long long val = (long long)nums[i] + (long long)diff;
            int ind = lower_bound(mp[val].begin(), mp[val].end(), i+1) - mp[val].begin();
            
            for(int k=ind; k<mp[val].size(); k++){
                pick = pick + 1 +  f(mp[val][k], i, 2, mp, nums, dp);
            }
            return dp[i][prev][p] = npick + pick;
            
        }else{
            
            long long diff = (long long)nums[i] - (long long)nums[prev];
            long long val = (long long)nums[i] + (long long)diff;
            int ind = lower_bound(mp[val].begin(), mp[val].end(), i+1) - mp[val].begin();
            
            int pick = 0;
            for(int k=ind; k<mp[val].size(); k++){
                pick = pick + 1 + f(mp[val][k], i, 2, mp, nums, dp);
            }
            return dp[i][prev][p] = pick;
        }
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        map<long long, vector<int>>mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, -1)));
        return f(0, 0, 0, mp, nums, dp);
    }
};