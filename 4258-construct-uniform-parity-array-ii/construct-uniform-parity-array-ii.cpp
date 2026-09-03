class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();
        int f = 0;
        int miniOdd = -1;
        for(int i=0; i<n; i++){
            if(i+1 < n && nums1[i] % 2 != nums1[i+1] % 2) f = 1;
            if(nums1[i] % 2){
                if(miniOdd == -1) miniOdd = i;
                else if(nums1[miniOdd] > nums1[i]) miniOdd = i;
            }
        }
        if(f == 0) return true;
        f = 0;
        for(auto& i: nums1){
            if(i%2 == 0){
                if(nums1[miniOdd] >= i) f = 1;
            }
            if(f) break;
        }
        if(f == 0) return true;
        f = 0;
        for(auto& i: nums1){
            if(i%2 == 1){
                if(nums1[miniOdd] >= i) f = 1;
            }
            if(f) break;
        }
        if(f == 0) return true;
        return false;
    }
};