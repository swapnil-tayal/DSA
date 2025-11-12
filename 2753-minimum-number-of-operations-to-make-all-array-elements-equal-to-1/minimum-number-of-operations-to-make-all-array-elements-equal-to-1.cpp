class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 1e9;
        int cnt = 0;

        for (auto &i: nums) cnt += (i == 1);
        if (cnt) return n - cnt;
        
        for (int i = 0; i < n; ++i) {
            int gcd = nums[i];
            for (int j = i + 1; j < n; ++j) {
                gcd = __gcd(gcd, nums[j]);
                if (gcd == 1) {
                    ans = min(ans, j - i + n - 1);
                    break;
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};