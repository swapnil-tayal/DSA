class Solution {
    vector<int> dp;
public:

    int f(int i, vector<int> &nums, int target) {

        if(i == nums.size()-1) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int ans = -1e9;
        for(int k=i+1; k<nums.size(); k++){
            if(nums[k] - nums[i] >= -target and nums[k] - nums[i] <= target){
                ans = max(ans, 1 + f(k, nums, target));
            }
        }
        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();
        dp.resize(n, -1);
        int ans = f(0, nums, target);
        return ans <= 0 ? -1 : ans;

    }
};