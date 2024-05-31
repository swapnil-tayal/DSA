class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums) mp[i]++;
        vector<int> ans;
        for(auto [i, j]: mp){
            if(j == 1) ans.push_back(i);
        }return ans; 
    }
};