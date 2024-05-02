class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        int ans = -1;
        set<int> st (nums.begin(), nums.end());
        for(auto i: st){
            if(st.count(i) and st.count(-i)){
                ans = max(ans, abs(i));
            }
        }
        return ans;
    }
};