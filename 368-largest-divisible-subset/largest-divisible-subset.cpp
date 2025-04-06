class Solution {
public:
    
//     int f(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
        
//         if(i == nums.size()) return 0;
//         if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
//         int npick = f(i+1, prev, nums, dp);
//         int pick = 0;
//         if(prev == -1 || nums[i]%nums[prev] == 0) pick = 1 + f(i+1, i, nums, dp);
        
//         return dp[i][prev+1] = max(pick, npick);
//     }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         vector<int> next(n+1, 0), cur(n+1, 0);
        
//         for(int i=n-1; i>=0; i--){
//             for(int prev=i-1; prev>=-1; prev--){
        
//                 int npick = next[prev+1];
//                 int pick = 0;
//                 if(prev == -1 || nums[i]%nums[prev] == 0) pick = 1 + next[i+1];

//                 cur[prev+1] = max(pick, npick);
//             }
//             next = cur;
//         }
        
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i=0; i<n; i++) hash[i] = i;
        int ind = 0;
        
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                
                if(nums[i] % nums[prev] == 0 and dp[i] < 1 + dp[prev]){
                    hash[i] = prev;
                    dp[i] = 1 + dp[prev];
                }
                if(dp[ind] < dp[i]){
                    ind = i;
                }
            }
        }
        
        // lis dp[n-1];
        
        vector<int> ans;
        while(hash[ind] != ind){
            ans.push_back(nums[ind]);
            ind = hash[ind];
        }
        ans.push_back(nums[ind]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};