class Solution {
public:

    int f(int i, vector<int> &nums, int x, vector<vector<int>> &dp){

        if(i == nums.size()){
            return x == 0 ? 0 : -1e9;
        }
        if(dp[i][x] != -1) return dp[i][x];
        int pick = nums[i] + f(i+1, nums, (x+nums[i])%3, dp);
        int npick = f(i+1, nums, x, dp);
        return dp[i][x] = max(pick, npick);
    }

    int maxSumDivThree(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(0, nums, 0, dp);
    }
};