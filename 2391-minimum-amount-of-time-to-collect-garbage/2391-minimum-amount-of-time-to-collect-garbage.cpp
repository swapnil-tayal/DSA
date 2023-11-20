class Solution {
public:
    
    int f(string &s, char ch){
        for(auto &i: s){
            if(i == ch) return 1;
        }
        return 0;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n = garbage.size();
        int ans = 0;
        
        int lastG = -1, lastP = -1, lastM = -1;
        for(int i=0; i<n; i++){
            if(f(garbage[i], 'M')) lastM = i;
            if(f(garbage[i], 'G')) lastG = i;
            if(f(garbage[i], 'P')) lastP = i;
        }
        // cout<<lastG<<' '<<lastP<<' '<<lastM<<'\n';
        for(int i=0; i<n; i++){
            ans += garbage[i].size();
            if(i <= lastM and i > 0) ans += travel[i-1];
            if(i <= lastP and i > 0) ans += travel[i-1];
            if(i <= lastG and i > 0) ans += travel[i-1];
        }
        return ans;
    }
};