class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        int ans = 1e9;
        
        int k = 0;
        set<int> st;
        
        for(int i=x; i<n; i++){
            
            st.insert(nums[k++]);
            auto ind = st.lower_bound(nums[i]);
            
            if(ind != st.end()) ans = min(ans, abs(nums[i] - *ind));
            if(ind != st.begin()) ans = min(ans, abs(nums[i] - *prev(ind)));
        
        }
        return ans;
    }
};