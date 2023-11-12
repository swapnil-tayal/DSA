class Solution {
public:
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        int ans1 = 0, ans2 = 1;
        int n = nums1.size();
        int f = 0;
        
        for(int i=n-2; i>=0; i--){
            
            if(nums1[i] <= nums1[n-1] and nums2[i] <= nums2[n-1]){
                
            }else{
                if(nums1[i] <= nums2[n-1] and nums2[i] <= nums1[n-1]){
                    ans1++;
                }else f = 1;
            }
        }
        if(f) ans1 = 1e9;
        f = 0;
        
        swap(nums1[n-1], nums2[n-1]);
        for(int i=n-2; i>=0; i--){
            
            if(nums1[i] <= nums1[n-1] and nums2[i] <= nums2[n-1]){
                
            }else{
                if(nums1[i] <= nums2[n-1] and nums2[i] <= nums1[n-1]){
                    ans2++;
                }else f = 1;
            }
        }
        if(f) ans2 = 1e9;
        int res = min(ans1, ans2);
        return res == 1e9 ? -1 : res;
    }
};