class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        set<int> st;
        for(auto i: nums) st.insert(i);
        
        vector<int> arr (st.begin(), st.end());
        int m = arr.size();
        int ans = 1e9;
        
        for(int i=0; i<m; i++){
            
            int ub = upper_bound(arr.begin(), arr.end(), (arr[i]+n-1)) - arr.begin();
            
            int rightExtra = n - ub;
            int leftExtra = i;
            ans = min(ans, rightExtra + leftExtra);
        }
        return ans;
    }
};