class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        for(int i=nums[0]; i<=nums[n-1]; i++){
            if(st.count(i) == 0) ans.push_back(i);
        }   
        return ans;
    }
};