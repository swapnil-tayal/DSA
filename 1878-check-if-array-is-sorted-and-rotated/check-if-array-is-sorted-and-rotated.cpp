class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            cnt += (nums[i] > nums[i+1]);
            if(cnt == 2) return 0;
        }
        if(cnt == 0) return 1;
        else{
            return nums[n-1] <= nums[0];
        }
    }
};