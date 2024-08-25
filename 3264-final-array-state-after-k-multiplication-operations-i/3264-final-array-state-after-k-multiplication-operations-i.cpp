class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        while(k--){
            
            int ind = -1;
            for(int i=0; i<nums.size(); i++){
                if(ind == -1 || nums[i] < nums[ind]){
                    ind = i;
                }
            }
            nums[ind] *= multiplier;
        }
        return nums;
    }
};