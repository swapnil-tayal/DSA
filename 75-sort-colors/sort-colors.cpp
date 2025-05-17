class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        int k = j;
        for(int i=j; i<n; i++){
            if(nums[i] == 1){
                swap(nums[i], nums[k]);
                k++;
            }
        }
    }
};