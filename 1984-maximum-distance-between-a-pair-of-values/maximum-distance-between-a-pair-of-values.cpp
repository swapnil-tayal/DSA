class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int ans = 0;
        reverse(nums2.begin(), nums2.end());
        for(int i=0; i<nums1.size(); i++){

            int ind = lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            if(ind == nums2.size()) continue;
            ind = nums2.size() - ind - 1;
            if(ind >= i){
                ans = max(ans, ind - i);
            }
        }
        return ans;
    }
};