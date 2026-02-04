class Solution {
    vector<vector<long long>> dp;
public:

    long long f(int i, int stage, vector<int> &nums){

        if(i == nums.size()){
            if(stage == 3) return 0;
            else return -1e15;
        }
        if(dp[i][stage] != -1) return dp[i][stage];
        long long ans = -1e15;
        if(stage == 0){
            if(i-1 >= 0 and nums[i-1] < nums[i]){
                ans = max(ans, nums[i-1] + nums[i] + f(i+1, 1, nums));
            }
            ans = max(ans, f(i+1, 0, nums));
        }else if(stage == 1){
            if(nums[i-1] < nums[i]){
                ans = max(ans, nums[i] + f(i+1, 1, nums));
            } else if(nums[i-1] > nums[i]){
                ans = max(ans, nums[i] + f(i+1, 2, nums));
            } 
        }else if(stage == 2){
            if(nums[i-1] > nums[i]){
                ans = max(ans, nums[i] + f(i+1, 2, nums));
            } else if(nums[i-1] < nums[i]){
                ans = max(ans, nums[i] + f(i+1, 3, nums));
                ans = max(ans, (long long) nums[i]);
            }
        }else if(stage == 3){
            if(nums[i-1] < nums[i]){
                ans = max(ans, nums[i] + f(i+1, 3, nums));
            } else ans = 0;
        }
        return dp[i][stage] = ans;
    }

    long long maxSumTrionic(vector<int>& nums) {
        
        dp.resize(nums.size(), vector<long long>(4, -1));
        return f(0, 0, nums);
    }
};