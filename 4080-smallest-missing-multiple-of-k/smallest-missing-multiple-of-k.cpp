class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        set<int> st(nums.begin(), nums.end());
        int ind = 1;
        while(st.count(ind * k)){
            ind++;
        }
        return ind * k;
    }
};