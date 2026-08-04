class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ind = 0;
        for(int i=nums[0]; i<=nums[n-1]; i++){
            if(nums[ind] != i){
                ans.push_back(i);
            }else ind++;
        }   
        return ans;
    }
};