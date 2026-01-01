class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int> mp;
        for(auto &i: arr1) mp[i]++;

        vector<int> ans;
        for(auto &i: arr2){
            while(mp[i]-- > 0) ans.push_back(i);
        }
        for(auto &i: mp){
            while(i.second-- > 0) ans.push_back(i.first);
        }
        return ans;
    }
};