class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);
        for(int i=0; i<n; i++) hash[i] = i;
        int ind = 0;

        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){

                if(nums[i] % nums[prev] == 0 and dp[i] < dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    hash[i] = prev;
                }
                if(dp[ind] < dp[i]) ind = i;
            }
        }
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