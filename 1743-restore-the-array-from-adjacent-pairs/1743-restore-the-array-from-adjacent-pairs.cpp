class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        
        map<int,vector<int>> mp;
        for(auto i: a){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        
        int start = -1;
        for(auto i: mp){
            if(i.second.size() == 1) start = i.first;
        }
        
        vector<int> ans;
        ans.push_back(start);
        
        while(true){
            
            vector<int> temp = mp[start];
            int f = ans.size() > 1;
            int k = -1;
            if(f) k = ans[ans.size()-2];
            
            for(auto i: temp){
                
                if(f){
                    if(k == i) continue;
                    else ans.push_back(i);
                
                }else ans.push_back(i);
            }
            start = ans.back();
            // for(auto k: ans) cout<<k<<' ';
            // cout<<'\n';
            if(ans.size() >= a.size()+1) break;
        }
        return ans;
    }
};