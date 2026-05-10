class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        
        vector<int> t = nums;
        reverse(t.begin(), t.end());
        for(auto &i: t) nums.push_back(i);
        return nums;
    }
};