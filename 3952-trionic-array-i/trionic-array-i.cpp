class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 4) return 0;
        int ind = 0;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) ind = i;
            else break;
        }
        if(ind == 0) return 0;
        int temp = ind;
        for(int i=ind+1; i<n; i++){
            if(nums[i] < nums[i-1]) ind = i;
            else break;
        }
        if(ind == temp) return 0;
        temp = ind;
        for(int i=ind+1; i<n; i++){
            if(nums[i] > nums[i-1]) ind = i;
            else break;
        }
        if(temp == ind) return 0;
        return ind == n-1;
    }
};