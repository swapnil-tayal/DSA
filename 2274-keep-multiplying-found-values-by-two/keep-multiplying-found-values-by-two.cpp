class Solution {
public:
    int findFinalValue(vector<int>& nums, int a) {
        
        set<int> st(nums.begin(), nums.end());
        while(st.count(a)){
            a = a*2;
        }
        return a;
    }
};