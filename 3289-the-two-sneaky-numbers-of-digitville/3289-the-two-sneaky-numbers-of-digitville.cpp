class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            mp[i]--;
        }
        vector<int> ans;
        for(auto i: mp){
            if(i.second > 0) ans.push_back(i.first);
        }
        return ans;
    }
};