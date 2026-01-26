class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        
        vector<int> a;
        for(auto &i: nums){
            if(i >= 0) a.push_back(i);
        }
        int n = a.size();
        if(n == 0) return nums;
        int ind = (k % n);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0){
                nums[i] = a[ind];
                ind = (ind+1)%n;
            }
        }
        return nums;
    }
};