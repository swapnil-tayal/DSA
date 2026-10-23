class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int prev = -1;
        for(int i=0; i<n; i++){
            if(nums[i] != i){
                if(prev == -1) prev = nums[i];
                else prev = prev & nums[i];
            }
        }
        return prev == -1 ? 0 : prev;
    }
};