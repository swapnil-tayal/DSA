class Solution {
public:

    long long minArraySum(vector<int>& nums) {
        
        unordered_set<int> present(nums.begin(), nums.end());
        long long sum = 0;

        for (int x : nums) {
            int best = x;
            for (int d = 1; (long long)d * d <= x; d++) {
                if (x % d == 0) {
                    if (present.count(d))     best = min(best, d);
                    if (present.count(x / d)) best = min(best, x / d);
                }
            }
            sum += best;
        }
        return sum;
    }
};