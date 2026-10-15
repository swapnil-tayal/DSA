class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                sum += st.size() * st.size();
            }
        }
        return sum;
    }
};