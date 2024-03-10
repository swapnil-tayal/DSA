class Solution {
    vector<int> nums;
public:
    long long f(int i, long long k, int inSub, vector<int> &nums, vector<vector<vector<long long>>> &dp){
        
        if(k == 0) return 0;
        if(i == nums.size()){
            if(k==1 && inSub == 1) return 0;
            return -1e15;
        }
        if(dp[i][inSub][k] != -1) return dp[i][inSub][k];
        
        int fac = (k%2) ? 1 : -1;
        long long ans = -1e15;
        
        if(inSub == 0) ans = f(i+1, k, 0, nums, dp);
        ans = max(ans, (nums[i]*fac*k) + f(i+1, k-1, 0, nums, dp));      
        ans = max(ans, (nums[i]*fac*k) + f(i+1, k, 1, nums, dp));
        
        return dp[i][inSub][k] = ans;
    }
    
    long long maximumStrength(vector<int>& nums, int k){
        
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(k+1, -1)));
        return f(0, k, 0, nums, dp);
    }
};