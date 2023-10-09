class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ind1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(ind1 == n || nums[ind1] != target) return {-1, -1};
        
        int ind2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return {ind1, ind2-1};
    }
};