class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = n;
        for(int i=0; i<n; i++){
            int ind = upper_bound(nums.begin(), nums.end(), (long long)nums[i]*k) - nums.begin();
            ind--;
            if(ind >= 0 and nums[ind] <= (long long)nums[i]*k){
                ans = min(ans, i + n-ind-1);
            }
        }
        return ans;
    }
};