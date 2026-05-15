class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size()-1;
        int ans = 0;
        while(s <= e){

            int mid = (s+e)/2;
            if(nums[s] <= nums[e]){
                e = mid-1;
                ans = nums[s];

            }else{
                s++;
            }
        }
        return ans;
    }
};