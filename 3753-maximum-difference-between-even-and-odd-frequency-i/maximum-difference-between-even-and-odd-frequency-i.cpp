class Solution {
public:
    int maxDifference(string s) {
        
        map<int,int> mp;
        for(auto i: s) mp[i]++;
        vector<int> maxO;
        vector<int> maxE;
        for(auto &i: mp){
            if(i.second % 2) maxO.push_back(i.second);
            else maxE.push_back(i.second);
        }
        int ans = -1e9;
        for(auto i: maxE){
            for(auto j: maxO){
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};