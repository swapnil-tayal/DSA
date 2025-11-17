class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        
        int pos = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(pos == -1) pos = i;
                else if(i - pos <= k) return false;
                else pos = i;
            }
        }
        return true;
    }
};