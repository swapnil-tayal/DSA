class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int num = 0;
        for(auto &i: nums){
            num ^= i;
        }
        
        map<int,int> mp;
        for(auto &i: nums){
            
            int a = i;
            int b = num ^ a;
            mp[b]++;
        }
        vector<int> ans;
        for(auto i: mp){
            if(i.second == 1) ans.push_back(i.first); 
        }
        return ans;
    }
};