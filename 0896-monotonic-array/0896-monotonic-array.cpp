#define all(x) x.begin(), x.end()

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        vector<int> nums2 = nums;
        reverse(all(nums2));
        return is_sorted(all(nums)) || is_sorted(all(nums2));
    }
};