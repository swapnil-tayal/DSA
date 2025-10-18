class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        for(auto &i: nums) i -= k;
        sort(nums.begin(), nums.end());
        int maxNum = nums[0];
        set<int> st;
        for(int i=0; i<nums.size(); i++){

            if(!st.count(nums[i])){
                st.insert(nums[i]);
                maxNum = nums[i];
            }else{
                int nxt = maxNum+1;
                if(nxt - nums[i] <= 2*k){
                    nums[i] = maxNum+1;
                    maxNum++;
                    st.insert(nums[i]);
                }
            }
        }
        return st.size();
    }
};