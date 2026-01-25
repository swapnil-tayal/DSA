class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int ans = 1e9;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-k+1; i++){
            ans = min(ans, nums[i+k-1] - nums[i]);
        }
        return ans;
    }
};