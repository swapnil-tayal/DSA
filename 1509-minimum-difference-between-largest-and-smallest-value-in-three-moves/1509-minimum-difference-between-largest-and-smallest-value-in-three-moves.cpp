class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(n <= 4) return 0;
        
        long ans = 1e11;
        ans = min(ans, (long)nums[n-1] - (long)nums[3]);
        ans = min(ans, (long)nums[n-2] - (long)nums[2]);
        ans = min(ans, (long)nums[n-3] - (long)nums[1]);
        ans = min(ans, (long)nums[n-4] - (long)nums[0]);
        
        return ans;
    }
};