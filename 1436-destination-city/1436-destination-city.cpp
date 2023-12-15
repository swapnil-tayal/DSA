class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        map<string, int> mp;
        for(auto i: paths){
            mp[i[0]]++;
        }
        for(auto i: paths){
            for(auto j: i){
                if(mp[j] == 0) return j;
            }
        }
        return "";
    }
};