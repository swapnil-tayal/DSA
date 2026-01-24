class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int i = 0;
        int j = n-1;
        while(i < j){
            ans = max(ans, nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};