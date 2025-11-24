class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
    
        vector<bool> ans;
        int x = 0;
        for (int i : nums) {
            x = (x * 2 + i) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
};