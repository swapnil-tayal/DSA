class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto &i: nums) mp[i]++;
        
        vector<vector<int>> ans;
        for(auto &i: mp){
            
            int cnt = i.second;
            int val = i.first;
            for(int i=0; i<cnt; i++){
                if(ans.size() > i) ans[i].push_back(val);
                else ans.push_back({ val });
            }
            
        }
        return ans;
    }
};