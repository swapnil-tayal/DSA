class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
            
        map<int,map<int,int>> mp;
        for(auto i: pick){
            mp[i[0]][i[1]]++;
        }
        
        set<int> st;
        for(int i=0; i<n; i++){
            
            int player = i;
            for(auto k: mp[player]){
                if(k.second > i) st.insert(i);
            }
        }
        return st.size();
    }   
};