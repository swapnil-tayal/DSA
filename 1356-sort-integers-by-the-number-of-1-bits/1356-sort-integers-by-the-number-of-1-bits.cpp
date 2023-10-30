class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        int n = arr.size();
        vector<pair<int,int>> ans;
        for(auto i: arr){
            
            int x = __builtin_popcount(i);
            ans.push_back({x, i});
            
        }
        sort(ans.begin(), ans.end());
        arr.clear();
        for(auto i: ans){
            arr.push_back(i.second);
        }
        return arr;
    }
};