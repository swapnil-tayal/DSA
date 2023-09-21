class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s = nums1.size() + nums2.size();
        vector<int> ans;
        for(auto i : nums1){
            ans.push_back(i);
        }
        for(auto i : nums2){
            ans.push_back(i);
        }
        
        sort(ans.begin(), ans.end());
        
        int m = s/2;
        if(s%2 == 0){
            double res = ans[m] + ans[m-1];
            return res/2;
        }else{
            double res = ans[m];
            return res;
        }
        
    }
};