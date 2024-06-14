class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        int cnt = 0;
        set<int> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            
            if(st.count(nums[i])){
                int lastVal = *st.rbegin();
                cnt += lastVal - nums[i] + 1;
                st.insert(lastVal+1);
            
            }else st.insert(nums[i]);
        }
        return cnt;
    }
};