class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return 0;

        sort(nums.begin(), nums.end());
        int medi = nums[n/2];
        int medi2 = nums[n/2 - 1];
        int ans = 0;
        int ans2 = 0;

        for(auto &i: nums){
            ans += abs(i - medi);
            ans2 += abs(i - medi2);
        }
        return min(ans, ans2);
    }
};