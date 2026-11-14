class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int ans = 1e9;
        for (int len = l; len <= r; len++) {
            for (int i = 0; i + len <= n; i++) {
                int sum = 0;
                for (int k = i; k < i + len; k++) sum += nums[k];
                if (sum > 0 && sum < ans) ans = sum;
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};