class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        unordered_map<int, vector<vector<int>>> mp;
        
        for(int i=0; i<n; i++){
            
            int x = groupSizes[i];
            if(mp.find(x) == mp.end()){
                mp[x].push_back({i});
            
            }else{
                if(mp[x].back().size() < x){
                    mp[x].back().push_back(i);
                
                }else mp[x].push_back({i});
            }
        }
        vector<vector<int>> ans;
        for(auto i: mp){
            for(auto j: i.second) ans.push_back(j);
        }
        return ans;
    }
};