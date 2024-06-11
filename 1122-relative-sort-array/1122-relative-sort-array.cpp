class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int> mp;
        for(auto i: arr1) mp[i]++;
        
        vector<int> ans;
        
        for(auto i: arr2){
            
            int x = mp[i];
            while(x--){
                ans.push_back(i);
            }
            mp[i] = 0;
        }
        for(auto i: mp){
            if(i.second != 0){
                while(i.second--){
                    ans.push_back(i.first);
                }
            }
        }
        return ans;
    }
};