class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int lastInvalid = -1;
        int lastMini = -1;
        int lastMaxi = -1;
        int n = nums.size();
        long long ans = 0;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                lastInvalid = i;
            }
            if(nums[i] == minK) lastMini = i;
            if(nums[i] == maxK) lastMaxi = i;
            // cout<<max(0, min(lastMini, lastMaxi) - lastInvalid)<<' ';
            ans += max(0, min(lastMini, lastMaxi) - lastInvalid);

        }
        return ans;
    }
};