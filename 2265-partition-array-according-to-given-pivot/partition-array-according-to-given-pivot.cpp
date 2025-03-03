class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int sm = 0;
        int sa = 0;
        int lr = 0;

        for(auto &i: nums){
            if(i > pivot) lr++;
            else if(i == pivot) sa++;
            else sm++;
        }
        vector<int> ans(nums.size());
        lr = sm + sa;
        sa = sm;
        sm = 0;
        for(auto &i: nums){
            if(i == pivot) ans[sa++] = i;
            else if(i > pivot) ans[lr++] = i;
            else ans[sm++] = i;
        }
        return ans;
    }
};